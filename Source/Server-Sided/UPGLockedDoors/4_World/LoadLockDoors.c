class LoadDoorState
{
	bool locked = true;
	vector location;
	int doorIndex = -1;
	string key;
}

class LoadLockedDoors 
{
	static ref LoadLockedDoors g_LoadLockedDoors;
	static ref LoadLockedDoors getInstance(){
		if (!GetGame().IsServer()){
			return NULL;
		}
		if (!g_LoadLockedDoors){g_LoadLockedDoors = new LoadLockedDoors();}
		return g_LoadLockedDoors;
	}
	
	static string DIR = "$profile:UPGLockedDoors";
	static string DoorFile = DIR + "\\Doors.json";
	
	ref array<LoadDoorState> Doors = new array<LoadDoorState>;
	
	void LoadDoors() {
		if (FileExist(DoorFile)) {
			JsonFileLoader<LoadLockedDoors>.JsonLoadFile(DoorFile, this);
		}
	}
	
	void GetDoorState() {
    Print("Loading Door State");
    for (int i; i < Doors.Count(); i++) {
        vector pos = {Doors[i].location[0], Doors[i].location[1], Doors[i].location[2]};
        int c = i + 1;
        Print("Door State: " + c + " of " + Doors.Count() + " loaded!");
        Building building;
        array<Object> objects = new array<Object>;
        array<CargoBase> cargos = new array<CargoBase>;
        GetGame().GetObjectsAtPosition(pos, 1, objects, cargos);
        for (int j = 0; j < objects.Count(); j++) {
            if (Class.CastTo(building, objects.Get(j))) {
                if (Doors[i].locked) {
                    if (building.IsDoorOpen(Doors[i].doorIndex)) {
                        building.CloseDoor(Doors[i].doorIndex);
                    }
                    building.LockDoor(Doors[i].doorIndex);		
                }
            }
        }
    }
}
	
	Building ActionTargetToBuilding(ActionTarget target){
		Building building;
		if (Class.CastTo(building, target.GetObject()))
		{
			return building;
		}
		return NULL;
	}
	
	Building ActionDataToBuilding(ActionData action_data){
		return ActionTargetToBuilding(action_data.m_Target);
	}
	
	bool CheckKey(string pkey) {
		if (GetKeyList.getInstance().Keys.Find(pkey) != -1) {
			return true;
		}
		return false;
	}
	
	bool CheckKeyandDoor(vector vec, int index, string pkey) {
		for (int i; i < Doors.Count(); i++) {
			float dist = vector.DistanceSq(Doors[i].location, vec);
			if (Doors[i].location == vec && Doors[i].doorIndex == index && Doors[i].key == pkey) {
				return true;
			}
		}
		return false;	
	}
	
	bool CheckDoor(vector vec, int index) {
		for (int i; i < Doors.Count(); i++) {
			float dist = vector.DistanceSq(Doors[i].location, vec);
			if (Doors[i].location == vec && Doors[i].doorIndex == index) {
				return true;
			}	
		}
		return false;
	}		
}

class GetKeyList {
	
		static string DIR = "$profile:UPGLockedDoors";
		static string KeyFile = DIR + "\\Keys.json";
		autoptr array<string> Keys = new array<string>();
	
		static ref GetKeyList g_GetKeyList;
		static ref GetKeyList getInstance(){
			if (!GetGame().IsServer()){
				return NULL;
			}
			if (!g_GetKeyList){g_GetKeyList = new GetKeyList();}
			return g_GetKeyList;
		}
		
		void GetData() {
			if (FileExist(KeyFile)) {
				JsonFileLoader<GetKeyList>.JsonLoadFile(KeyFile, this);
				}
			else {
				if (!FileExist(DIR)) {
					MakeDirectory(DIR);
				}	
				Keys.Insert("");
				JsonFileLoader<GetKeyList>.JsonSaveFile(KeyFile, this);
			}
	}

} 

modded class BuildingBase
{
	private int ConvertComponent(int srcComponentIdx, string srcGeometry, string dstGeometry)
	{
		string selection = GetActionComponentName(srcComponentIdx, srcGeometry);

		const int maxComponents = 512;
		for (int componentIndex = 0; componentIndex < maxComponents; componentIndex++)
		{
			if (IsActionComponentPartOfSelection(componentIndex, selection, dstGeometry))
			{
				return componentIndex;
			}
		}

		return -1;
	}
	
	override bool EEOnDamageCalculated(TotalDamageResult damageResult, int damageType, EntityAI source, int component, string dmgZone, string ammo, vector modelPos, float speedCoef)
	{
		if (!super.EEOnDamageCalculated(damageResult, damageType, source, component, dmgZone, ammo, modelPos, speedCoef))
		{
			return false;
		}
		int dstComponent = ConvertComponent(component, LOD.NAME_FIRE, LOD.NAME_VIEW);
		if (dstComponent != -1)
		{
			int doorIndex = GetDoorIndex(dstComponent);
			if (IsDoorLocked(doorIndex) && LoadLockedDoors.getInstance().CheckDoor(GetPosition(), doorIndex))
			{
				return false;
			}
			else {
				
				return true;
			}
		}

		return true;
	}
}	

modded class ActionUnlockDoors: ActionContinuousBase
{
	private ref map<string, ref LoadDoorState> DoorStates = new map<string, ref LoadDoorState>();
	ref UPGNotifications notifications = new UPGNotifications;
	LoadDoorState GetDoor(vector pos, int doorIndex){
		string Door = string.Format("%1-%2-%3-%4", pos[0], pos[1], pos[2], doorIndex);
		DoorStates[Door] = LoadDoorState();
		DoorStates[Door].doorIndex = doorIndex;
		DoorStates[Door].location = {pos[0], pos[1], pos[2]};
		return DoorStates[Door];
	}
	
	override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
	{	
		if (GetGame().IsClient()){
			return super.ActionCondition(player, target, item);
		}
		if (super.ActionCondition(player, target, item)){
			Building building = LoadLockedDoors.getInstance().ActionTargetToBuilding(target);
			if (building){
				int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
				if (doorIndex != -1){
					LoadDoorState door = GetDoor(building.GetPosition(), doorIndex);
					return door.locked;
				}
			}
		}
		return false;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Building building = LoadLockedDoors.getInstance().ActionDataToBuilding(action_data);
		if (building){
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if (doorIndex != -1){
				LoadDoorState door = GetDoor(building.GetPosition(), doorIndex);
				ItemBase item = ItemBase.Cast(action_data.m_MainItem);
				PlayerBase player = PlayerBase.Cast(action_data.m_Player);
				string key = item.GetType();
				Print("[Debug] item: " + key);
				if (LoadLockedDoors.getInstance().CheckDoor(door.location, door.doorIndex)){
					if (LoadLockedDoors.getInstance().CheckKeyandDoor(door.location, door.doorIndex, key)) {
						notifications.NotifyPlayer("Locked Door", "You unlocked the door!", player.GetIdentity().GetPlainId());
						door.locked = false;	
						building.UnlockDoor(doorIndex);
						item.Delete();
						return;
					}
					else if (LoadLockedDoors.getInstance().CheckKey(key)) {
						notifications.NotifyPlayer("Locked Door", "This key doesn't work on this door!", player.GetIdentity().GetPlainId());
						return;
					}
					else {	
						notifications.NotifyPlayer("Locked Door", "You need a key to open this door!", player.GetIdentity().GetPlainId());
						return;
					}
				notifications.NotifyPlayer("Locked Door", "You need a key to open this door!", player.GetIdentity().GetPlainId());
				return;
				} else if (LoadLockedDoors.getInstance().CheckKey(key)) {
					notifications.NotifyPlayer("Locked Door", "This key doesn't work on this door!", player.GetIdentity().GetPlainId());
					return;
				} else {
					door.locked = false;
					building.UnlockDoor(doorIndex);
				}		
			}
			
		}		
	}
};
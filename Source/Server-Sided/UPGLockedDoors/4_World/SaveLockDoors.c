class SaveDoorState 
{
	bool locked = false;
	vector location;
	int doorIndex = -1;
	string key;
}

class SaveLockedDoors 
{
	static ref SaveLockedDoors g_SaveLockedDoors;
	static ref SaveLockedDoors getInstance(){
		if (!GetGame().IsServer()){
			return NULL;
		}
		if(!g_SaveLockedDoors){g_SaveLockedDoors = new SaveLockedDoors();}
		return g_SaveLockedDoors;
	}
	
	static string DIR = "$profile:UPGLockedDoors";
	static string DoorFile = DIR + "\\Doors.json";

	private ref array<SaveDoorState> Doors = new array<SaveDoorState>;
	
	void SaveDoor(SaveDoorState door) {
		Doors.Insert(door);
		SaveData();
	}
	
	void SaveData() {
        if (GetGame().IsServer()) {
            if (!FileExist(DIR)) {
                MakeDirectory(DIR);
            }
			Print("Saving Door Data");
            JsonFileLoader<SaveLockedDoors>.JsonSaveFile(DoorFile, this);
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
	
}

class CheckSaveMode 
{
	static bool CheckMode;
	static void CheckMode(bool mode) {
		CheckMode = mode;
	}

}

modded class ActionLockDoors
{
	
	bool EnableDoorSaveMode = CheckSaveMode.CheckMode;
	private ref map<string, ref SaveDoorState> DoorStates = new map<string, ref SaveDoorState>();
	ref UPGNotifications notifications = new UPGNotifications;
	SaveDoorState GetDoor(vector pos, int doorIndex){
		string Door = string.Format("%1-%2-%3-%4", pos[0], pos[1], pos[2], doorIndex);
		DoorStates[Door] = new SaveDoorState();
		DoorStates[Door].doorIndex = doorIndex;
		vector location = {pos[0], pos[1], pos[2]};
		DoorStates[Door].location = location;
		DoorStates[Door].key = "";
		return DoorStates[Door];
	}
	
	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (GetGame().IsClient()){
			return super.ActionCondition(player, target, item);
		}
		if (super.ActionCondition(player, target, item)){
			Building building = SaveLockedDoors.getInstance().ActionTargetToBuilding(target);
			if (building){
				int doorIndex = building.GetDoorIndex(target.GetComponentIndex());
				if (doorIndex != -1){	
					SaveDoorState door = GetDoor(building.GetPosition(), doorIndex);
					bool doorIsLocked = building.IsDoorLocked(door.doorIndex);
					if (!doorIsLocked && door.locked){
						building.LockDoor(door.doorIndex);
					}
					return !door.locked;
				}
			}
		}
		return false;
	}
	
	override void OnFinishProgressServer(ActionData action_data)
	{
		Building building = SaveLockedDoors.getInstance().ActionDataToBuilding(action_data);
		if (building){
			int doorIndex = building.GetDoorIndex(action_data.m_Target.GetComponentIndex());
			if (doorIndex != -1){	
				SaveDoorState door = GetDoor(building.GetPosition(), doorIndex);
				ItemBase item = ItemBase.Cast(action_data.m_MainItem);
				PlayerBase player = PlayerBase.Cast(action_data.m_Player);
				string key = item.GetType();
				if (!LoadLockedDoors.getInstance().CheckDoor(door.location, door.doorIndex)){
					door.locked = true;
				}
				else {
					notifications.NotifyPlayer("Door", "You cannot lock this door!", player.GetIdentity().GetPlainId());
					return;
				}	
				building.LockDoor(doorIndex);
				if (EnableDoorSaveMode == true) {
					SaveLockedDoors.getInstance().SaveDoor(door);
				}
			}
		}
	}
}
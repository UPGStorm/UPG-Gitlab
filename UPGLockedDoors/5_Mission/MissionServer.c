/**
* UPG Locked Door System
* Created by Storm for UPG Servers
*/

modded class MissionServer
{	
	override void OnMissionStart()
    {
        super.OnMissionStart();
		if (GetGame().IsServer()){
			LoadLockedDoorSettings settings = new LoadLockedDoorSettings;
			settings.LoadData();
			CheckSaveMode.CheckMode(settings.GetSaveMode());
			LoadLockedDoors.getInstance();
			GetKeyList.getInstance().GetData();
			for (int i; i < GetKeyList.getInstance().Keys.Count(); i++) {
				Print(GetKeyList.getInstance().Keys[i]);
			}
			LoadLockedDoors.getInstance().LoadDoors();
			LoadLockedDoors.getInstance().GetDoorState();
		}
    }
}
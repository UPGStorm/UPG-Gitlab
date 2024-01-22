class LoadLockedDoorSettings 
{
	static string DIR = "$profile:UPGLockedDoors";
	static string config = DIR + "\\LockedDoorSettings.json";
	
	bool EnableDoorSaveMode;
	bool EnableDoorLoadMode;
	
	bool GetSaveMode() {
		return EnableDoorSaveMode;
	}
	
	bool GetLoadMode() {
		return EnableDoorLoadMode;
	}
	
	void LoadData() {
		if (FileExist(config)) {
				JsonFileLoader<LoadLockedDoorSettings>.JsonLoadFile(config, this);
		} else {
			JsonFileLoader<LoadLockedDoorSettings>.JsonSaveFile(config, this);
		}
	}
}
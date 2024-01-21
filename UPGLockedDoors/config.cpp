class CfgPatches
{
	class UPGLockedDoors
	{
		requiredAddons[]=
		{
			"DZ_Data"
		};
	};
};

class CfgMods
{
	class UPGLockedDoors
	{
		type = "mod";
		dependencies[]={ "Game", "World", "Mission" };
		
		class defs
		{	
			class gameScriptModule
			{
				value = "";
				files[] = {"UPGLockedDoors\3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"UPGLockedDoors\4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"UPGLockedDoors\5_Mission"};
			};
		};
	};
};	
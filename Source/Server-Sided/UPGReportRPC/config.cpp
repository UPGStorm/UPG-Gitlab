class CfgPatches
{
	class UPGReportRPC
	{
		requiredAddons[]=
		{
			"JM_CF_Scripts", "UPGUI", "UPGStormFuncs"
		};
	};
};

class CfgMods
{
	class UPGReportRPC
	{
		type = "mod";
		dependencies[]={ "World", "Mission" };
		
		class defs
		{	
			class worldScriptModule
			{
				value = "";
				files[] = {"UPGReportRPC\scripts\4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"UPGReportRPC\scripts\5_Mission"};
			};
		};
	};
};
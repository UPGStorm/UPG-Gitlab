class CfgPatches
{
	class UPGStormFuncs
	{
		requiredAddons[]=
		{
			"JM_CF_Scripts"
		};
	};
};

class CfgMods
{
	class UPGStormFuncs
	{
		type = "mod";
		dependencies[]={ "World" };
		
		class defs
		{	
			class worldScriptModule
			{
				value = "";
				files[] = {"UPGStormFuncs\scripts\4_World"};
			};
		};
	};
};
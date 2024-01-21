/**
* DayZIntroScene.c 
* 
* TH
* www.thebritto.com.br 
* © 2019 - 2021 TH 
* 
* Last Modified: 17/01/2022 
* Modified By: TH
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

modded class DayZIntroScene
{
	protected Weather					m_Weather;
	protected int 						m_Animation;

	void DayZIntroScene()
	{
		World world = g_Game.GetWorld();
		string root_path = "cfgCustomScenes " + g_Game.GetWorldName();

		int count = g_Game.ConfigGetChildrenCount(root_path);
		int index = Math.RandomInt(0, 1);

		string childName;
		g_Game.ConfigGetChildName(root_path, index, childName);
	
		string scene_path = root_path + " " + childName;	

		vector PlayerPosition = g_Game.ConfigGetVector(scene_path + " PlayerPosition");
		vector PlayerOrientation = g_Game.ConfigGetVector(scene_path + " PlayerOrientation");
		vector CameraPosition = g_Game.ConfigGetVector(scene_path + " CameraPosition");
		float  fov = g_Game.ConfigGetFloat(scene_path + " fov");

		if (world)
		{
			TIntArray date = new TIntArray;
			g_Game.ConfigGetIntArray(scene_path + " date", date);
			world.SetDate(date.Get(0), date.Get(1), date.Get(2), date.Get(3), date.Get(4));
		}

		string item;
		GetGame().ConfigGetText(scene_path + " Hand", item);
		m_Animation = g_Game.ConfigGetInt(scene_path + " Animation");        

		GetGame().ObjectDelete(m_Camera);
		Class.CastTo(m_Camera, g_Game.CreateObject("staticcamera", CameraPosition, true));

		if (m_Camera)
		{
			m_Camera.SetFOV(fov);
			m_Camera.SetFocus(1.0, 0.0);
			m_Camera.SetActive(true);
		};

		SpawnCharacters();
		Objects();

		m_Character = new IntroSceneCharacter();
		m_Character.LoadCharacterData(PlayerPosition, PlayerOrientation);
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(m_Character.SetAnim, 30, false, m_Animation); 
		GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(this.UpdateItemInHands, 50, false, item);

		float overcast, rain, windspeed, fog;
		overcast = g_Game.ConfigGetFloat(scene_path + " overcast");
		rain = g_Game.ConfigGetFloat(scene_path + " rain");
		fog = g_Game.ConfigGetFloat(scene_path + " fog");
		m_Weather = g_Game.GetWeather();
		m_Weather.GetOvercast().SetLimits(overcast, overcast);
		m_Weather.GetRain().SetLimits(rain, rain);
		m_Weather.GetFog().SetLimits(fog, fog);
		
		m_Weather.GetOvercast().Set(overcast, overcast, 0);
		m_Weather.GetRain().Set(rain, rain, 0);
		m_Weather.GetFog().Set(fog, fog, 0);
	};

	void UpdateItemInHands(string item)
	{       
		if (item != "")
		{
			if (m_Character.GetCharacterObj().GetItemInHands())
				GetGame().ObjectDelete(m_Character.GetCharacterObj().GetItemInHands());
			m_Character.GetCharacterObj().GetHumanInventory().CreateInHands(item);
		};
	};

	void SpawnObject(string classname, vector position, vector rotation)
	{
		Object obj;
		obj = GetGame().CreateObject(classname, position);

		if(position)
			obj.SetPosition(position);

		if(rotation)
			obj.SetOrientation(rotation);

		obj.SetPosition(position);
		obj.SetOrientation(rotation);
	};

	void Objects()
	{
		string mapname = "";

		GetGame().GetWorldName(mapname);
		mapname.ToLower();

		if (mapname == "chernarusplus" || mapname == "")
		{
			//Scene 1
			SpawnObject("bldr_prop_Fireplace_Complete", "169.798645 121.366173 2158.953369", "-87.024506 -0.000000 -0.000000");
			SpawnObject("bldr_prop_LargeTent", "166.262421 121.354744 2145.841064", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_MediumTent", "161.520889 121.361816 2157.414551", "99.871216 -0.000000 -0.000000");
			SpawnObject("Land_Misc_DeerStand2", "155.294830 124.444817 2153.309082", "80.319069 -0.000000 -0.000000");
			SpawnObject("bldr_misc_woodpile_forest1", "169.907639 122.155075 2146.737549", "84.605171 -0.000000 -0.000000");
			SpawnObject("bldr_misc_woodpile_forest3", "170.596786 122.021866 2144.635498", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_Misc_WoodBlock", "169.373169 121.685783 2157.771240", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_Misc_WoodPile2", "169.191803 121.666512 2158.817871", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_Misc_WoodBlock", "168.943802 121.685616 2158.072754", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_tent_gunrack", "165.178848 121.695084 2148.982666", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_Pot", "169.954361 121.979294 2159.029541", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_Pot", "169.778412 121.981239 2158.828857", "0.000000 0.000000 0.000000");
			SpawnObject("bldr_Forest_BeetleTrap1", "163.991882 122.137474 2153.753662", "-23.214708 -0.000000 -0.000000");
		};
		
		if (mapname == "enoch")
		{
			//Scene 2
			SpawnObject("bldr_prop_Fireplace_Complete", "3429.530518 170.040314 8964.027344", "-1.887501 -0.000000 -0.000000");
			SpawnObject("bldr_prop_FishNetTrap", "3428.539063 169.920242 8958.701172", "23.416529 -0.000000 -0.000000");
			SpawnObject("bldr_prop_FishingRod", "3430.164307 170.224060 8964.019531", "172.982437 0.000000 33.499977");
			SpawnObject("bldr_prop_ImprovisedShelterPitched", "3427.908936 170.288895 8963.778320", "131.020981 0.000000 0.000000");
			SpawnObject("bldr_prop_HuntingBag", "3427.728516 170.381714 8962.991211", "126.314140 -0.000000 -0.000000");
			SpawnObject("bldr_prop_WoodenCrate", "3427.854004 170.371735 8963.830078", "-139.045929 -0.000000 -0.000000");
			SpawnObject("bldr_prop_WaterproofBag_Green", "3428.268311 170.325272 8964.237305", "0.000000 -0.000000 -0.000000");
		};
		
		if (mapname == "namalsk")
		{
			//Scene 4
			SpawnObject("StaticObj_Misc_WoodPile_Forest2", "5498.942871 117.216278 8141.328613", "86.879623 -0.000000 -0.000000");
			SpawnObject("bldr_prop_AdvancedImprovisedShelterPitched", "5501.796875 116.634621 8141.505371", "81.559891 -0.000000 -0.000000");
			SpawnObject("bldr_prop_Fireplace", "5502.675293 116.718040 8143.906738", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_WaterproofBag_Green", "5505.114258 118.956497 8141.166504", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_WaterproofBag_Orange", "5504.214844 118.960815 8141.019531", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_AssaultBag_Black", "5502.938965 116.657303 8141.087891", "60.335629 -0.000000 -0.000000");
			SpawnObject("bldr_prop_HunterPants_Winter", "5502.473633 116.725052 8142.114746", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_prop_HuntingJacket_Winter", "5502.421387 116.713280 8141.496582", "0.000000 -0.000000 -0.000000");
			SpawnObject("bldr_mil_radar_tall_planks", "5500.311035 118.173981 8141.195801", "0.000000 0.000000 -90.000000");
			SpawnObject("bldr_mil_radar_tall_planks", "5500.149902 116.438393 8140.275391", "-177.666168 0.000000 -90.000000");
		};
	};

	PlayerBase CreateCharacter(vector position, vector rotation, string itemInHands = "", int emote = -1, int stance = -1, string character = "")
	{
	   	if (character == "")
	   	{
	    	character  = GetGame().CreateRandomPlayer();
	   	}

	   	PlayerBase player = PlayerBase.Cast(GetGame().CreateObject(character, position));   
	   
	   	if(position)
	     	player.SetPosition(position);
	   	if(rotation)
	     	player.SetOrientation(rotation);

	   	player.SetPosition(position);
	   	player.SetOrientation(rotation);

	   	player.GetInventory().CreateInInventory(GlassesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(GlovesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(ShirtsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(VestsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(PantsGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(ShoesGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(BeltGame.GetRandomElement());
	   	player.GetInventory().CreateInInventory(BagsGame.GetRandomElement());

	   	if (itemInHands != "")
	   	{
			player.GetHumanInventory().CreateInHands(itemInHands);
	   	}

		if (emote != -1 && stance != -1)
      	{
         	GetGame().GetCallQueue(CALL_CATEGORY_GAMEPLAY).CallLater(StartAction, 500, true, player, emote, stance);
      	};

	  	return player;
	};

    PlayerBase StartAction (PlayerBase player, int emote = -1, int stance = -1)
    {
        player.StartCommand_Action(emote , ActionBaseCB, stance);
        return player;
    };

	void SpawnCharacters()
	{
		string mapname = "";

		GetGame().GetWorldName(mapname);
		mapname.ToLower();

		if (mapname == "chernarusplus")
		{
			
		};
	};
};
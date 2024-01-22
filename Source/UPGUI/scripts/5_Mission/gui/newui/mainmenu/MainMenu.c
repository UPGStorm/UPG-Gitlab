/**
* MainMenu.c 
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

modded class MainMenu extends UIScriptedMenu
{
	protected ButtonWidget m_Discord;
	protected ImageWidget m_DiscordImage;
	protected ButtonWidget m_Steam;
	protected ImageWidget m_SteamImage;
	protected ButtonWidget m_Facebook;
	protected ImageWidget m_FacebookImage;
	protected ButtonWidget m_Twitter;
	protected ImageWidget m_Twitterimage;
	protected ButtonWidget m_Reddit;
	protected ImageWidget m_RedditImage;
	protected ButtonWidget m_Youtube;
	protected ImageWidget m_YoutubeImage;
	protected ButtonWidget m_PayPal;
	protected ImageWidget m_PayPalImage;

	protected TextWidget 	 m_SteamID;
	protected TextWidget   m_CustomVersion;
	protected ImageWidget  m_Logotipo;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("UPGUI/gui/layouts/new_ui/main_menu.layout");

		m_Discord = ButtonWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton"));
		m_DiscordImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton_img"));
		m_Steam = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SteamButton"));
		m_SteamImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("SteamButton_img"));
		m_Facebook = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton"));
		m_FacebookImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton_img"));
		m_Twitter = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton"));
		m_Twitterimage = ImageWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton_img"));
		m_Reddit = ButtonWidget.Cast(layoutRoot.FindAnyWidget("RedditButton"));
		m_RedditImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("RedditButton_img"));
		m_Youtube = ButtonWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton"));
		m_YoutubeImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton_img"));
		m_PayPal = ButtonWidget.Cast(layoutRoot.FindAnyWidget("PayPalButton"));
		m_PayPalImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("PayPal_img"));

		m_SteamID = TextWidget.Cast(layoutRoot.FindAnyWidget("SteamID"));
		
		m_Play = layoutRoot.FindAnyWidget("play");
		m_ChooseServer = layoutRoot.FindAnyWidget("choose_server");
		m_CustomizeCharacter = layoutRoot.FindAnyWidget("customize_character");
		m_PlayVideo = layoutRoot.FindAnyWidget("play_video");
		m_Tutorials = layoutRoot.FindAnyWidget("tutorials");
		m_TutorialButton = layoutRoot.FindAnyWidget("tutorial_button");
		m_MessageButton = layoutRoot.FindAnyWidget("message_button");
		m_SettingsButton = layoutRoot.FindAnyWidget("settings_button");
		m_Exit = layoutRoot.FindAnyWidget("exit_button");
		m_PrevCharacter = layoutRoot.FindAnyWidget("prev_character");
		m_NextCharacter = layoutRoot.FindAnyWidget("next_character");

		m_Version = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
		m_ModdedWarning = TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_CharacterRotationFrame = layoutRoot.FindAnyWidget("character_rotation_frame");

		m_Logotipo = ImageWidget.Cast(layoutRoot.FindAnyWidget("dayz_logo"));
		
		if (ShowLogo)
		{
			m_Logotipo.Show(true);
			m_Logotipo.LoadImageFile(0, logotipo);
		}
		else
		{
			m_Logotipo.Show(false);
		};

		if (DiscordLinkShow){m_Discord.Show(true);m_DiscordImage.LoadImageFile(0, DiscordLinkImage);}else{m_Discord.Show(false);};	
		if (SteamLinkShow){m_Steam.Show(true);m_SteamImage.LoadImageFile(0, SteamLinkImage);}else{m_Steam.Show(false);};
		if (FacebookLinkShow){m_Facebook.Show(true);m_FacebookImage.LoadImageFile(0, FacebookLinkImage);}else{m_Facebook.Show(false);};
		if (TwitterLinkShow){m_Twitter.Show(true);m_Twitterimage.LoadImageFile(0, TwitterLinkImage);}else{m_Twitter.Show(false);};
		if (RedditLinkShow){m_Reddit.Show(true);m_RedditImage.LoadImageFile(0, RedditLinkImage);}else{m_Reddit.Show(false);};
		if (YoutubelInkShow){m_Youtube.Show(true);m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage);}else{m_Youtube.Show(false);};
		if (PayPalLinkShow){m_PayPal.Show(true);m_PayPalImage.LoadImageFile(0, PayPalLinkImage);}else{m_PayPal.Show(false);};

		m_LastPlayedTooltip = layoutRoot.FindAnyWidget("last_server_info");
		m_LastPlayedTooltip.Show(false);
		m_LastPlayedTooltipLabel = m_LastPlayedTooltip.FindAnyWidget("last_server_info_label");
		m_LastPlayedTooltipName = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_name"));
		m_LastPlayedTooltipIP = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_ip"));
		m_LastPlayedTooltipPort = TextWidget.Cast(m_LastPlayedTooltip.FindAnyWidget("last_server_info_port"));
		
		m_LastPlayedTooltipTimer = new WidgetFadeTimer();
		
		m_Stats = new MainMenuStats(layoutRoot.FindAnyWidget("character_stats_root"));
		
		m_Mission = MissionMainMenu.Cast(GetGame().GetMission());
		
		m_LastFocusedButton = m_Play;

		m_ScenePC = m_Mission.GetIntroScenePC();
		
		if(m_ScenePC)
		{
			m_ScenePC.ResetIntroCamera();
		};
		
		m_PlayVideo.Show(false);
		
		m_PlayerName = TextWidget.Cast(layoutRoot.FindAnyWidget("character_name_text"));
		
		// Set Version
		string version;
		GetGame().GetVersion(version);
		m_Version.SetText("#main_menu_version" + " " + version);
		
		GetGame().GetUIManager().ScreenFadeOut(0);

		SetFocus(null);
		
		Refresh();
		
		LoadMods();
		
		GetDayZGame().GetBacklit().MainMenu_OnShow();
	
		g_Game.SetLoadState(DayZLoadState.MAIN_MENU_CONTROLLER_SELECT);

		SteamID64();
		SetPlayerName();	

		return layoutRoot;
	};
	
	override bool OnClick(Widget w, int x, int y, int button)
	{
		if (button == MouseState.LEFT && w == m_Discord)
		{
			GetGame().OpenURL(DiscordLink);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Steam)
		{
			GetGame().OpenURL(SteamLink);
			return true;
		}
		else if (button == MouseState.LEFT && w == m_Facebook)
		{
			GetGame().OpenURL(FacebookLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Twitter)
		{
			GetGame().OpenURL(TwitterLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Reddit)
		{
			GetGame().OpenURL(RedditLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Youtube)
		{
			GetGame().OpenURL(YoutubeLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_PayPal)
		{
			GetGame().OpenURL(PayPalLink);
			return false;
		}

		return super.OnClick(w, x, y, button);
	};

	override void OnChangeCharacter(bool create_character = true)
	{
		if (m_ScenePC && m_ScenePC.GetIntroCharacter())
		{
			int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
			if (create_character)
			{
				m_ScenePC.GetIntroCharacter().CreateNewCharacterById(charID);
			}
			
			Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");
			
			if (w)
			{
				TextWidget text = TextWidget.Cast(w);
				
				if(m_ScenePC.GetIntroCharacter().IsDefaultCharacter())
				{
					text.SetText("#layout_main_menu_customize_char");
				}
				else
				{
					text.SetText("#layout_main_menu_customize_char");
				}
			}
			if (m_ScenePC.GetIntroCharacter().GetCharacterObj())
			{
				if (m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale())
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
				else
					m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
			}
			
			//update character stats
			m_Stats.UpdateStats();
		};
	};

	override void ColorHighlight(Widget w)
	{
		if(!w)
			return;
		
		
		int color_pnl = ARGB(255, 0, 0, 0);
		int color_lbl = UIColor;
		int color_img = ARGB(255, 150, 150, 150);;
		
		ButtonSetColor(w, color_pnl);
		ButtonSetTextColor(w, color_lbl);
		ImagenSetColor(w, color_img);
	};

	void SteamID64()
	{
	    if (GetGame().GetUserManager() && GetGame().GetUserManager().GetTitleInitiator()){
	        string player_id = GetGame().GetUserManager().GetTitleInitiator().GetUid();
	        m_SteamID.SetText(player_id);
	    }
	};

	void SetPlayerName()
	{
		if (m_PlayerName)
		{
			string name;
			GetCLIParam("name", name);
			if (!name) name = "Survivor";

			m_PlayerName.SetText(name);
		};
	};
};
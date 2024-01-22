/**
* InGameMenu.c 
* 
* TH
* https://obritto.com 
* © 2019 - 2022
* 
* Last Modified: 01/21/2024
* Modified By: Storm
* 
* 
*/

modded class InGameMenu extends UIScriptedMenu
{
	Widget m_Painel;
	Widget m_Report;
	Widget m_ReportedText;
	Widget m_DeadScreen;
	
	bool m_ReportSent;

	TextWidget m_PlayersKilledValue;
	TextWidget m_TimeSurvivedValue;
	TextWidget m_InfectedKilledValue;
	TextWidget m_DistanceTraveledValue;
	TextWidget m_LongRangeShotValue;

	ImageWidget m_DeadScreenImage;
	float m_DeadScreenFadeInIncrement = 1.3 / 2.75;
	float m_DeadScreenFadeInLevel;
	float m_DeadScreenImageFadeInIncrement = 1.2 / 1.45;
	float m_DeadScreenImageFadeInLevel;
	float m_ShowAlpha;
	float m_TimerSlice;

	ButtonWidget m_Discord;
	ButtonWidget m_Steam;
	ButtonWidget m_Facebook;
	ButtonWidget m_Twitter;
	ButtonWidget m_Reddit;
	ButtonWidget m_Youtube;
	ButtonWidget m_PayPal;
	ButtonWidget m_TikTok;
	ButtonWidget m_GitHub;
	ButtonWidget m_Instagram;
	ButtonWidget m_Twitch;

	ImageWidget m_DiscordImage;
	ImageWidget m_SteamImage;
	ImageWidget m_FacebookImage;
	ImageWidget m_Twitterimage;
	ImageWidget m_RedditImage;
	ImageWidget m_YoutubeImage;
	ImageWidget m_PayPalImage;
	ImageWidget m_TikTokImage;
	ImageWidget m_GitHubImage;
	ImageWidget m_InstagramImage;
	ImageWidget m_TwitchImage;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("UPGUI/gui/layouts/day_z_ingamemenu.layout");
				
		m_ContinueButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("continuebtn"));
		m_ExitButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("exitbtn"));
		m_RestartButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("restartbtn"));
		m_RespawnButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button"));
		m_RestartDeadRandomButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button_random"));
		m_RestartDeadCustomButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("respawn_button_custom"));
		m_OptionsButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("optionsbtn"));
		m_ModdedWarning = TextWidget.Cast(layoutRoot.FindAnyWidget("ModdedWarning"));
		m_HintPanel = new UiHintPanel(layoutRoot.FindAnyWidget("hint_frame"));
		m_ServerInfoPanel = layoutRoot.FindAnyWidget("server_info");
		m_ServerIP = TextWidget.Cast(layoutRoot.FindAnyWidget("server_ip"));
		m_ServerPort = TextWidget.Cast(layoutRoot.FindAnyWidget("server_port"));
		m_ServerName = TextWidget.Cast(layoutRoot.FindAnyWidget("server_name"));
		m_FavoriteImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("favorite_image"));
		m_UnfavoriteImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("unfavorite_image"));
		m_CopyInfoButton = ButtonWidget.Cast(layoutRoot.FindAnyWidget("copy_button"));

		m_Painel = layoutRoot.FindAnyWidget("painelbtn");

		m_Discord = ButtonWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton"));
		m_Steam = ButtonWidget.Cast(layoutRoot.FindAnyWidget("SteamButton"));
		m_Facebook = ButtonWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton"));
		m_Twitter = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton"));
		m_Reddit = ButtonWidget.Cast(layoutRoot.FindAnyWidget("RedditButton"));
		m_Youtube = ButtonWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton"));
		m_PayPal = ButtonWidget.Cast(layoutRoot.FindAnyWidget("PayPalButton"));
		m_TikTok = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TikTokButton"));
		m_GitHub = ButtonWidget.Cast(layoutRoot.FindAnyWidget("GithubButton"));
		m_Instagram = ButtonWidget.Cast(layoutRoot.FindAnyWidget("InstagramButton"));
		m_Twitch = ButtonWidget.Cast(layoutRoot.FindAnyWidget("TwitchButton"));

		m_DiscordImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("DiscordButton_image"));
		m_SteamImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("SteamButton_image"));
		m_FacebookImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("FacebookButton_image"));
		m_Twitterimage = ImageWidget.Cast(layoutRoot.FindAnyWidget("TwitterButton_image"));
		m_RedditImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("RedditButton_image"));
		m_YoutubeImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("YoutubeButton_image"));
		m_PayPalImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("PayPal_image"));
		m_TikTokImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("TikTok_image"));
		m_GitHubImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Github_image"));
		m_InstagramImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Instagram_image"));
		m_TwitchImage = ImageWidget.Cast(layoutRoot.FindAnyWidget("Twitch_image"));
		
		m_ReportedText = TextWidget.Cast(layoutRoot.FindAnyWidget("ReportedText"));
		m_ReportedText.Show(false);

		m_Discord.Show(DiscordLinkShow);
		m_DiscordImage.LoadImageFile(0, DiscordLinkImage);

		m_Steam.Show(SteamLinkShow);
		m_SteamImage.LoadImageFile(0, SteamLinkImage);

		m_Facebook.Show(FacebookLinkShow);
		m_FacebookImage.LoadImageFile(0, FacebookLinkImage);

		m_Twitter.Show(TwitterLinkShow);
		m_Twitterimage.LoadImageFile(0, TwitterLinkImage);

		m_Reddit.Show(RedditLinkShow);
		m_RedditImage.LoadImageFile(0, RedditLinkImage);

		m_Youtube.Show(YoutubelInkShow);
		m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage);

		m_PayPal.Show(PayPalLinkShow);
		m_PayPalImage.LoadImageFile(0, PayPalLinkImage);

		m_Twitch.Show(TwitchLinkShow);
		m_TwitchImage.LoadImageFile(0, TwitchLinkImage);

		m_Instagram.Show(InstagramLinkShow);
		m_InstagramImage.LoadImageFile(0, InstagramLinkImage);

		m_GitHub.Show(GitHubLinkShow);
		m_GitHubImage.LoadImageFile(0, GitHubLinkImage);

		m_TikTok.Show(TikTokLinkShow);
		m_TikTokImage.LoadImageFile(0, TikTokLinkImage);

		#ifdef SERVERPANEL
			m_Painel.Show(true);
		#else
			m_Painel.Show(false);
		#endif
		
		if (GetGame().IsMultiplayer())
		{
			ButtonSetText(m_RestartButton, "#main_menu_respawn");
		}
		else
		{
			ButtonSetText(m_RestartButton, "#main_menu_restart");
		}		
		
		HudShow(false);
		SetGameVersion();
		SetServerInfoVisibility(SetServerInfo() && g_Game.GetProfileOption(EDayZProfilesOptions.SERVERINFO_DISPLAY));
		m_ModdedWarning.Show(g_Game.ReportModded());

		//Deathscreen
		m_DeadScreen = Widget.Cast(layoutRoot.FindAnyWidget("dead_screen"));
		m_DeadScreen.SetAlpha(0);
		m_ReportSent = false;
		m_Report = layoutRoot.FindAnyWidget("report_button");
		m_Report.Show(false);
		m_DeadScreen.Show(false);
		m_DeadScreenImage = ImageWidget.Cast(m_DeadScreen.FindAnyWidget("dead_screen_image"));
		m_DeadScreenImage.LoadImageFile(0, DeadScreenImage);
		m_DeadScreenImage.SetAlpha(0);

		m_TimeSurvivedValue = TextWidget.Cast(layoutRoot.FindAnyWidget("TimeSurvivedValue"));
		m_PlayersKilledValue = TextWidget.Cast(layoutRoot.FindAnyWidget("PlayersKilledValue"));
		m_InfectedKilledValue = TextWidget.Cast(layoutRoot.FindAnyWidget("InfectedKilledValue"));
		m_DistanceTraveledValue = TextWidget.Cast(layoutRoot.FindAnyWidget("DistanceTraveledValue"));
		m_LongRangeShotValue = TextWidget.Cast(layoutRoot.FindAnyWidget("LongRangeShotValue"));
		
		return layoutRoot;
	};

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);

		if (w == m_Discord)
		{
			GetGame().OpenURL(DiscordLink);
			return true;
		}
		else if (w == m_Report && !m_ReportSent)
		{
		    GetRPCManager().SendRPC("UPG", "RPCSendReportKill", new Param1<string>("Report Killer"), false);
		    m_ReportedText.Show(true);
		    m_Report.Show(false);
		    m_ReportSent = true;  // Set the report flag to indicate that the report has been sent
		    return true;
		}
		#ifdef SERVERPANEL
		else if (w == m_Painel)
		{
			EnterScriptedMenu(SERVER_PANEL);
			return true;
		}
		#endif
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
		else if (button == MouseState.LEFT && w == m_TikTok)
		{
			GetGame().OpenURL(TikTokLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_GitHub)
		{
			GetGame().OpenURL(GitHubLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Instagram)
		{
			GetGame().OpenURL(InstagramLink);
			return false;
		}
		else if (button == MouseState.LEFT && w == m_Twitch)
		{
			GetGame().OpenURL(TwitchLink);
			return false;
		}
		return false;
	};

	override void Update(float timeslice)
	{
		UpdateInfo();

		if (ShowDeadScreen)
		{
			m_TimerSlice += timeslice;
			if (m_TimerSlice >= 0.01)
			{
				DeathFunction(timeslice);
				m_TimerSlice = 0;
			}
		}
		super.Update(timeslice);
	};

	void DeathFunction(float timeslice)
	{
		float new_deadscreen_val;

		if (m_DeadScreenImageFadeInLevel != 1)
		{
			m_DeadScreen.Show(true);
			m_Report.Show(true);
			new_deadscreen_val = m_DeadScreenFadeInLevel + m_DeadScreenFadeInIncrement * timeslice;
			if (new_deadscreen_val < 1)
				m_DeadScreenFadeInLevel = new_deadscreen_val;
			else
				m_DeadScreenFadeInLevel = 1;

			if (m_DeadScreenFadeInLevel > 0.5)
			{
				float new_logo_val = m_DeadScreenImageFadeInLevel + m_DeadScreenImageFadeInIncrement * timeslice;
				if (new_deadscreen_val < 1)
					m_DeadScreenImageFadeInLevel = new_logo_val;
				else
					m_DeadScreenImageFadeInLevel = 1;
			}
			m_DeadScreen.SetAlpha(m_DeadScreenFadeInLevel);
			m_DeadScreenImage.SetAlpha(m_DeadScreenImageFadeInLevel);
		};
	};

	override void ColorHighlight(Widget w)
    {
        if (!w)
            return;

        ButtonSetTextColor(w, UIColor);
    };

	override void OnShow()
    {
        super.OnShow();
        PPEffects.SetBlurInventory(0.3);
		m_ReportSent = false;  // Reset the report flag when the menu is shown
    };

    override void OnHide()
    {
        super.OnHide();
        PPEffects.SetBlurInventory(0);
    };

    void UpdateInfo()
    {
		PlayerBase player = PlayerBase.Cast(GetGame().GetPlayer());

    	if (player)
		{
			float stat_value;
			string stat_text;
			
			m_TimeSurvivedValue.SetText(GetTimeString(player.StatGet(AnalyticsManagerServer.STAT_PLAYTIME)));
			m_PlayersKilledValue.SetText(GetValueString(player.StatGet(AnalyticsManagerServer.STAT_PLAYERS_KILLED)));
			m_InfectedKilledValue.SetText(GetValueString(player.StatGet(AnalyticsManagerServer.STAT_INFECTED_KILLED)));
			m_DistanceTraveledValue.SetText(GetDistanceString(player.StatGet(AnalyticsManagerServer.STAT_DISTANCE)));
			m_LongRangeShotValue.SetText(GetDistanceString(player.StatGet(AnalyticsManagerServer.STAT_LONGEST_SURVIVOR_HIT), true));
		};
    };

	string GetTimeString(float total_time)
	{
		string day_symbol = " d";							//define symbols
		string hour_symbol = " h";
		string minute_symbol = " min";
		
		if (total_time > 0)
		{
			string time_string;		
			int time_seconds = total_time; 						//convert total time to int
			
			int days = time_seconds / 3600 / 24;
			int hours = time_seconds / 3600 % 24;
			int minutes = (time_seconds % 3600) / 60;
			
			if (days > 0)
			{
				time_string += GetValueString(days) + day_symbol;		//days
				time_string += " ";										//separator
			}
			
			if (hours > 0 || days > 0)
			{
				time_string += GetValueString(hours) + hour_symbol;	//hours
				time_string += " ";										//separator
			}			

			if (minutes >= 0)
			{
				time_string += GetValueString(minutes) + minute_symbol;	//minutes
			}			

			return time_string;
		}
		
		return "0" + " " + minute_symbol;
	};
	
	string GetDistanceString(float total_distance, bool meters_only = false)    
    {
        if(total_distance < 0)
            return "0m";
    
        int distance_meters = total_distance;
        string distance_string;
        
        int kilometers = distance_meters / 1000;
        if (kilometers > 0 && !meters_only)    
        {
            distance_string += GetValueString(kilometers) + "km";            //kilometers
            distance_string += " ";                                            //separator
        }
        else    
        {
            distance_string += GetValueString(distance_meters) + "m";        //meters
        }
        
        return distance_string;
    };
    
    string GetValueString(float total_value)    
    {
        if(total_value < 0)
            return "0";
    
        int value = total_value;
        string out_string;
        
        if (value >= 1000)    
        {
            string value_string = value.ToString();
            
            int count;        
            int first_length = value_string.Length() % 3;        //calculate position of the first separator
            if (first_length > 0)    
            {
                count = 3 - first_length;
            }
            
            for (int i = 0; i < value_string.Length(); ++i)    
            {
                out_string += value_string.Get(i);
                count ++;
                
                if (count >= 3)    
                {
                    out_string += " ";            //separator
                    count = 0;
                }
            }
        }
        else    
        {
            out_string = value.ToString();
        }
        return out_string;
    };

	override bool OnMouseEnter(Widget w, int x, int y)
	{
		ColorHighlight(w);

		if(w == m_Discord)
		{
			m_DiscordImage.LoadImageFile(0, DiscordLinkImage_hover);
		}
		else if (w == m_Steam)
		{
			m_SteamImage.LoadImageFile(0, SteamLinkImage_hover);
		}
		else if (w == m_Facebook)
		{
			m_FacebookImage.LoadImageFile(0, FacebookLinkImage_hover);
		}
		else if (w == m_Twitter)
		{
			m_Twitterimage.LoadImageFile(0, TwitterLinkImage_hover);
		}
		else if (w == m_Reddit)
		{
			m_RedditImage.LoadImageFile(0, RedditLinkImage_hover);
		}
		else if (w == m_Youtube)
		{
			m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage_hover);
		}
		else if (w == m_PayPal)
		{
			m_PayPalImage.LoadImageFile(0, PayPalLinkImage_hover);
		}
		else if (w == m_TikTok)
		{
			m_TikTokImage.LoadImageFile(0, TikTokLinkImage_hover);
		}
		else if (w == m_GitHub)
		{
			m_GitHubImage.LoadImageFile(0, GitHubLinkImage_hover);
		}
		else if (w == m_Twitch)
		{
			m_TwitchImage.LoadImageFile(0, TwitchLinkImage_hover);
		}
		else if (w == m_Instagram)
		{
			m_InstagramImage.LoadImageFile(0, InstagramLinkImage_hover);
		}
		return false;
	};
	
	override bool OnMouseLeave(Widget w, Widget enterW, int x, int y)
	{
		ColorNormal(w);

		if(w == m_Discord)
		{
			m_DiscordImage.LoadImageFile(0, DiscordLinkImage);
		}
		else if (w == m_Steam)
		{
			m_SteamImage.LoadImageFile(0, SteamLinkImage);
		}
		else if (w == m_Facebook)
		{
			m_FacebookImage.LoadImageFile(0, FacebookLinkImage);
		}
		else if (w == m_Twitter)
		{
			m_Twitterimage.LoadImageFile(0, TwitterLinkImage);
		}
		else if (w == m_Reddit)
		{
			m_RedditImage.LoadImageFile(0, RedditLinkImage);
		}
		else if (w == m_Youtube)
		{
			m_YoutubeImage.LoadImageFile(0, YoutubeLinkImage);
		}
		else if (w == m_PayPal)
		{
			m_PayPalImage.LoadImageFile(0, PayPalLinkImage);
		}
		else if (w == m_TikTok)
		{
			m_TikTokImage.LoadImageFile(0, TikTokLinkImage);
		}
		else if (w == m_GitHub)
		{
			m_GitHubImage.LoadImageFile(0, GitHubLinkImage);
		}
		else if (w == m_Twitch)
		{
			m_TwitchImage.LoadImageFile(0, TwitchLinkImage);
		}
		else if (w == m_Instagram)
		{
			m_InstagramImage.LoadImageFile(0, InstagramLinkImage);
		}
		return false;
	};
};
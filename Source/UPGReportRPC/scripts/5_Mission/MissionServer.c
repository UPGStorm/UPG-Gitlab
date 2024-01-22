modded class MissionServer extends MissionBase 
{
	private static const string DISCORD_URL = "https://discord.com/api/webhooks/";
	static string ServerName;
	static string Endpoint;
	static string Username;
	static string AvatarUrl;
	static int EmbedColor;

	override void OnInit() {
		super.OnInit();
		if (GetGame().IsServer()) {
			GetDiscordSettings settings = new GetDiscordSettings;
			settings.GetData();
			GetRPCManager().AddRPC( "UPG", "RPCSendReportKill", this, SingeplayerExecutionType.Both);
		}	
	}
	
	void RPCSendReportKill(CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target)
	{
			if (!sender)
			{
				return;
			}
			Param1<string> data
			if (!ctx.Read(data)) return;
		
			UPGNotifications notifications = new UPGNotifications;
		
			string ReporterId = sender.GetPlainId();
			string ReporterName = sender.GetName();
			string KillerId;
			string KillerName;
			string server = ServerName;
			Man player = sender.GetPlayer();
			
			if (!player.m_KillerData) {
				return;
			}
		
			Man killer;
		
			if (!Man.CastTo(killer, player.m_KillerData.m_Killer)) {
				return;
			}
			
			if (!killer.GetIdentity() || !killer.GetIdentity().GetPlainId()) {
				return;
			}
			
			KillerId = killer.GetIdentity().GetPlainId();
			KillerName = killer.GetIdentity().GetName();
		
			if (KillerId == ReporterId) {
				return;
			}
				
			Print("Player Report Kill");
			notifications.NotifyPlayer("Report Player", "Your report has been sent!", sender.GetPlainId());
			PostWebhook(server, ReporterName, ReporterId, KillerName, KillerId);
	}
	
	private void PostWebhook(string server, string ReporterName, string ReporterId, string ReportedName,string ReportedId)
	{
		DiscordEmbed embed = BuildEmbed(server, ReporterName, ReporterId, ReportedName, ReportedId);

		DiscordWebhook webhook = new DiscordWebhook();
		webhook.username = Username;
		webhook.avatar_url = AvatarUrl;
		webhook.AddEmbed(embed);

		string json;
		JsonSerializer serializer = new JsonSerializer();
		serializer.WriteToString(webhook, false, json);

		RestContext rest = GetRestApi().GetRestContext(DISCORD_URL);
		rest.SetHeader("application/json");
		rest.POST(null, Endpoint, json);
	}

	private DiscordEmbed BuildEmbed(string server, string ReporterName, string ReporterId, string ReportedName, string ReportedId)
	{
		DiscordEmbed embed = new DiscordEmbed();
		embed.title = string.Format("<t:%1:f>", CF_Date.Now(true).GetTimestamp());
		embed.color = EmbedColor;

		embed.SetServer(server);
		
		embed.description = string.Format("Server: %1 ", server);
		embed.description += string.Format("\nSender: [%1](http://steamcommunity.com/profiles/%2) | ID: %2 ", ReporterName, ReporterId);
		embed.description += string.Format("\nReported: [%1](http://steamcommunity.com/profiles/%2) | ID: %2 ", ReportedName, ReportedId);
		
		return embed;
	}	
}

class GetDiscordSettings 
{
	static string DIR = "$profile:UPGReports";
	static string settings = DIR + "\\Settings.json";
	string ServerName;
	string Endpoint;
	string Username;
	string AvatarUrl;
	int EmbedColor;
	
	void GetData() {
		auto data = new GetDiscordSettings();
		if (FileExist(settings)) {
			JsonFileLoader<GetDiscordSettings>.JsonLoadFile(settings, this);
			MissionServer.ServerName = ServerName;
			MissionServer.Endpoint = Endpoint;
			MissionServer.Username = Username;
			MissionServer.AvatarUrl = AvatarUrl;
			MissionServer.EmbedColor = EmbedColor;
		}
		if (!FileExist(DIR)) {
                MakeDirectory(DIR);
            }
        JsonFileLoader<GetDiscordSettings>.JsonSaveFile(settings, this);
	}
}
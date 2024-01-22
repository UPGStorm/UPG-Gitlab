class UPGNotifications 
{
	ref NotificationSystem UPGNotificationSystem = new NotificationSystem();
	int NotificationMessageTime = 10;
	ref array<int> NotificationColor = {200, 0, 200, 200};
	int getNotificationColor(){
		return ARGB(NotificationColor[0], NotificationColor[1], NotificationColor[2], NotificationColor[3]);
	}
	
	string WarningMessageImagePath = "UPGUI\\Warning.paa";
	
	void NotifyPlayer(string header, string message, string playerID)
	{
		PlayerBase player = PlayerBase.Cast(UPGGetPlayerBaseByID(playerID));
		if (player){
			UPGNotificationSystem.CreateNotification(new ref StringLocaliser(header), new ref StringLocaliser(message), WarningMessageImagePath, getNotificationColor(), NotificationMessageTime, player.GetIdentity());	
		}
	}
}
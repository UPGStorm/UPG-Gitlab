/**
* DayZPlayerImplement.c 
* 
* TH
* https://obritto.com 
* © 2019 - 2022
* 
* Last Modified: 16/10/2022 
* Modified By: TH
* 
* This work is licensed under the Creative Commons Attribution-NonCommercial-NoDerivatives 4.0 International License. 
* To view a copy of this license, visit http://creativecommons.org/licenses/by-nc-nd/4.0/. 
* This work is property of TH. You do not have permissions to edit/distribute any of this content without written permission from the content author (TH). 
* Failure to adhere to the content license(s) above will result in actions from Bohemia Interactive Studios and/or Valve.
* 
*/

modded class DayZPlayerImplement extends DayZPlayer 
{
    override void ShowDeadScreen(bool show, float duration)
    {    
        #ifndef NO_GUI
            if (show && IsPlayerSelected())
            {
                GetGame().GetUIManager().ScreenFadeIn(duration, "", FadeColors.BLACK, FadeColors.WHITE);
                GetGame().GetUIManager().EnterScriptedMenu(MENU_INGAME, null);     
            }
            else
            {
                GetGame().GetUIManager().ScreenFadeOut(0);
            };
            
            if (duration > 0)
            {
                GetGame().GetCallQueue(CALL_CATEGORY_GUI).CallLater(StopDeathDarkeningEffect, duration*1000, false);
                ShowDeadScreen = true;
            }
            else
            {
                GetGame().GetCallQueue(CALL_CATEGORY_GUI).Call(StopDeathDarkeningEffect);
                ShowDeadScreen = false;
            };
        #endif
    };
};
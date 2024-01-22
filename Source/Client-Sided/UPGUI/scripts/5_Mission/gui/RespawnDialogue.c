/**
* RespawnDialogue.c 
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

modded class RespawnDialogue extends UIScriptedMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("UPGUI/gui/layouts/day_z_respawn_dialogue.layout");
		m_DetailsRoot 				= layoutRoot.FindAnyWidget( "menu_details_tooltip" );
		m_DetailsLabel				= TextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_label" ) );
		m_DetailsText				= RichTextWidget.Cast( m_DetailsRoot.FindAnyWidget( "menu_details_tooltip_content" ) );
		Widget custom_respawn 		= layoutRoot.FindAnyWidget("respawn_button_custom");
		SetFocus(custom_respawn);
		return layoutRoot;
	};
	
    protected void ColorHighlight(Widget w)
    {
        if (!w)
            return;

        ButtonSetColor(w, ARGB(0, 0, 0, 0));
        ButtonSetTextColor(w, UIColor);
    };
};

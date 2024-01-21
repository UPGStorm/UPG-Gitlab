/**
* IntroSceneCharacter.c 
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

modded class IntroSceneCharacter extends Managed
{
    void SetAnim(int pose)
    {        
        if ( pose != -1)
        {
            m_CharacterObj.StartCommand_Action(pose, ActionBaseCB, DayZPlayerConstants.STANCEMASK_ALL);
        };
    };

    protected void CharacterLoad( int character_id, vector char_pos, vector char_rot )
    {
        if ( character_id == -1 )
        {
            Error("IntroSceneCharacter->CharacterLoad: character_id = "+ character_id +" Cant Load Character!!!");
            return;
        }
        
        CharacterUnload();
        
        SetCharacterID( character_id );
                
        m_CharacterObj = PlayerBase.Cast( m_CharacterDta.CreateCharacterPerson( character_id ) );
        
        if ( m_CharacterObj )
        {        
            m_CharacterObj.PlaceOnSurface();
            m_CharacterObj.SetPosition(char_pos);
            m_CharacterObj.SetOrientation(char_rot);
        }    
    }
};
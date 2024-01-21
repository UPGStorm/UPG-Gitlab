/**
* MissionMainMenu.c 
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

modded class MissionMainMenu
{
	private ref AbstractWave m_MenuMusic;
	
	override void OnMissionStart()
    {
        super.OnMissionStart();
        PlayMusic();
    }
    
    override void OnMissionFinish()
    {
        super.OnMissionFinish();
        StopMusic();
    }
	
	void PlayMusic()
	{
		if ( !m_MenuMusic )
		{
			ref SoundParams soundParams	= new SoundParams("Main_Music_Menu_SoundSet");
			ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
			ref SoundObject soundObject	= soundBuilder.BuildSoundObject();
			
			soundObject.SetKind( WaveKind.WAVEMUSIC );
			m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
			m_MenuMusic.Loop( true );
			m_MenuMusic.Play();
		}
	}
}
class CfgPatches
{
    class UPGUI
    {
        units[]={};
        weapons[]={};
        requiredVersion=0.1;
        requiredAddons[]={"DZ_Data"};
    };
};
class CfgMods
{
    class UPGUI
    {
        dir="";
        picture="";
        action="";
        hideName=0;
        hidePicture=0;
        name="";
        credits="";
        author="";
        authorID="0";
        version="0.1";
        extra=0;
        type="mod";
        dependencies[]={"Game", "World", "Mission"};
        class defs
        {
            class gameScriptModule
            {
                files[]={"UPGUI/scripts/3_Game"};
            };
            class worldScriptModule
            {
                files[]={"UPGUI/scripts/4_World"};
            };
            class missionScriptModule
            {
                files[]={"UPGUI/scripts/5_Mission"};
            };
        };
    };
};
class cfgCustomScenes
{
    class ChernarusPlus
    {
        class Scene1
        {
            PlayerPosition[]={169.2113, 121.34695, 2153.9114};
            PlayerOrientation[]={61.6962, 0, 0};
            CameraPosition[]={175.31384, 124.882164, 2156.7847};
            fov=0.75;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class Deerisle
    {
        class Scene2
        {
            PlayerPosition[]={3879.8328, 14.029198, 9838.097};
            PlayerOrientation[]={-143.79842, 0, 0};
            CameraPosition[]={3874.6802, 16.514147, 9831.304};
            fov=0.75;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class Enoch
    {
        class Scene3
        {
            PlayerPosition[]={3428.6086, 170.13553, 8961.098};
            PlayerOrientation[]={124.21991, 0, 0};
            CameraPosition[]={3433.4724, 171.08875, 8960.803};
            fov=0.75;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class Namalsk
    {
        class Scene4
        {
            PlayerPosition[]={5504.2026, 116.73982, 8143.4014};
            PlayerOrientation[]={69.74689, 0, 0};
            CameraPosition[]={5508.5664, 118.14295, 8144.9634};
            fov=0.75;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class Banov
    {
        class loc1
        {
            PlayerPosition[]={1983.63, 223.423, 2462.45};
            PlayerOrientation[]={-161.78198, 0, 0};
            CameraPosition[]={1982.45, 224.37122, 2459.0168};
            fov=0.5;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class TakistanPlus
    {
        class loc1
        {
            PlayerPosition[]={5943.6196, 83.04, 11859.926};
            PlayerOrientation[]={152, 0, 0};
            CameraPosition[]={5946.6875, 84.04, 11853.825};
            fov=0.5;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
    class Iztek
    {
        class Scene
        {
            PlayerPosition[]={4602.506, 47.68022, 5583.71};
            PlayerOrientation[]={71.27603, 0, 0};
            CameraPosition[]={4609.2695, 49.854855, 5586.931};
            fov=0.75;
            overcast=0;
            rain=0;
            fog=0;
            date[]={1997, 1, 15, 12, 0};
            Animation=-1;
            Hand="";
        };
    };
};
class CfgSoundSets
{
    class Main_Music_Menu_SoundSet
    {
        soundShaders[]={"Main_Music_Menu_SoundShader"};
        volumeFactor=1;
        frequencyFactor=1;
        spatial=0;
    };
};
class CfgSoundShaders
{
    class Main_Music_Menu_SoundShader
    {
        samples[]={{"UPGUI\gui\sounds\MainMenu.ogg", 1}};
        volume=0.35;
    };
};

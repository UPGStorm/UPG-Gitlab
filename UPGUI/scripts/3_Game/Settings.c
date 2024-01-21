/**
* Settings.c 
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

// Colors
const int UIColor = ARGB(255, 47, 204, 76);
const int UIColorText = ARGB(255, 47, 204, 76);

// Deathscreen
static bool ShowDeadScreen = false;
const string DeadScreenImage = "UPGUI/gui/data/deathscreen/deathscreen.edds";

// Logotipo
const bool ShowLogo = true;
const string logotipo = "UPGUI/gui/data/logotipo/logotipo.edds";

// Links
const string DiscordLink = "https://discord.gg/upg";
const string DiscordLinkImage = "UPGUI/gui/data/social/discord.edds";
const string DiscordLinkImage_hover = "UPGUI/gui/data/social/discord_hover.edds";
const bool DiscordLinkShow = true;

const string SteamLink = "https://steamcommunity.com/sharedfiles/filedetails/?id=2715763652";
const string SteamLinkImage = "UPGUI/gui/data/social/steam.edds";
const string SteamLinkImage_hover = "UPGUI/gui/data/social/steam_hover.edds";
const bool SteamLinkShow = true;

const string FacebookLink = "https://upgdayz.com";
const string FacebookLinkImage = "UPGUI/gui/data/social/www.edds";
const string FacebookLinkImage_hover = "UPGUI/gui/data/social/www_hover.edds";
const bool FacebookLinkShow = true;

const string TwitterLink = "https://twitter.com/UPGDayZ";
const string TwitterLinkImage = "UPGUI/gui/data/social/twitter.edds";
const string TwitterLinkImage_hover = "UPGUI/gui/data/social/twitter_hover.edds";
const bool TwitterLinkShow = true;

const string RedditLink = "https://www.reddit.com/";
const string RedditLinkImage = "UPGUI/gui/data/social/reddit.edds";
const string RedditLinkImage_hover = "UPGUI/gui/data/social/reddit_hover.edds";
const bool RedditLinkShow = false;

const string YoutubeLink = "https://www.youtube.com/@upgdayz8663";
const string YoutubeLinkImage = "UPGUI/gui/data/social/youtube.edds";
const string YoutubeLinkImage_hover = "UPGUI/gui/data/social/youtube_hover.edds";
const bool YoutubelInkShow = true;

const string PayPalLink = "https://www.paypal.com/donate/?business=5XE4BPM86Q56L&no_recurring=0&item_name=upgdayz.com&currency_code=USD";
const string PayPalLinkImage = "UPGUI/gui/data/social/paypal.edds";
const string PayPalLinkImage_hover = "UPGUI/gui/data/social/paypal_hover.edds";
const bool PayPalLinkShow = true;

const string TwitchLink = "https://www.twitch.tv/plurnstyle";
const string TwitchLinkImage = "UPGUI/gui/data/social/twitch.edds";
const string TwitchLinkImage_hover = "UPGUI/gui/data/social/twitch_hover.edds";
const bool TwitchLinkShow = false;

const string InstagramLink = "https://www.instagram.com/plurnstyle/";
const string InstagramLinkImage = "UPGUI/gui/data/social/instagram.edds";
const string InstagramLinkImage_hover = "UPGUI/gui/data/social/instagram_hover.edds";
const bool InstagramLinkShow = false;

const string GitHubLink = "https://github.com/Plurnstyle";
const string GitHubLinkImage = "UPGUI/gui/data/social/gitHub.edds";
const string GitHubLinkImage_hover = "UPGUI/gui/data/social/gitHub_hover.edds";
const bool GitHubLinkShow = false;

const string TikTokLink = "https://www.tiktok.com/";
const string TikTokLinkImage = "UPGUI/gui/data/social/tiktok.edds";
const string TikTokLinkImage_hover = "UPGUI/gui/data/social/tiktok_hover.edds";
const bool TikTokLinkShow = false;


//Random clothing in PlayerBase into main menu
autoptr TStringArray GlassesGame = {"SportGlasses_Orange","SportGlasses_Blue","SportGlasses_Black","SportGlasses_Green","ThinFramesGlasses","ThickFramesGlasses","DesignerGlasses","AviatorGlasses","TacticalGoggles","NVGHeadstrap"};
autoptr TStringArray GlovesGame = {"NBCGlovesGray","OMNOGloves_Brown","OMNOGloves_Gray","TacticalGloves_Green","TacticalGloves_Black","TacticalGloves_Beige","WorkingGloves_Black","WorkingGloves_Brown","WorkingGloves_Beige","WorkingGloves_Yellow","SurgicalGloves_Green","SurgicalGloves_White","SurgicalGloves_Blue","SurgicalGloves_LightBlue"};
autoptr TStringArray HatsGame = {"BallisticHelmet_Green","BallisticHelmet_Black","BallisticHelmet_UN","Ssh68Helmet","GorkaHelmet","Mich2001Helmet","FiautoptrightersHelmet_White","FiautoptrightersHelmet_Red","FiautoptrightersHelmet_Yellow","ZSh3PilotHelmet","GreatHelm","TankerHelmet","DarkMotoHelmet_Green","DarkMotoHelmet_Black","DarkMotoHelmet_Grey","DarkMotoHelmet_Lime","DarkMotoHelmet_White","DarkMotoHelmet_Blue","DarkMotoHelmet_Red","MotoHelmet_Green","MotoHelmet_Black","MotoHelmet_Grey","MotoHelmet_Lime","MotoHelmet_White","MotoHelmet_Blue","MotoHelmet_Red","DirtBikeHelmet_Khaki","DirtBikeHelmet_Black","DirtBikeHelmet_Chernarus","DirtBikeHelmet_Green","DirtBikeHelmet_Police","DirtBikeHelmet_Blue","DirtBikeHelmet_Red","DirtBikeHelmet_Mouthguard","HockeyHelmet_Black","HockeyHelmet_White","HockeyHelmet_Blue","HockeyHelmet_Red","SkateHelmet_Green","SkateHelmet_Black","SkateHelmet_Gray","SkateHelmet_Blue","SkateHelmet_Red","ConstructionHelmet_Lime","ConstructionHelmet_White","ConstructionHelmet_Blue","ConstructionHelmet_Red","ConstructionHelmet_Orange","ConstructionHelmet_Yellow","NBCHoodGray","Ushanka_Green","Ushanka_Black","Ushanka_Blue","RadarCap_Green","RadarCap_Black","RadarCap_Brown","RadarCap_Blue","RadarCap_Red","ZmijovkaCap_Green","ZmijovkaCap_Black","ZmijovkaCap_Brown","ZmijovkaCap_Blue","ZmijovkaCap_Red","FlatCap_BlackCheck","FlatCap_Black","FlatCap_Brown","FlatCap_Grey","FlatCap_GreyCheck","FlatCap_BrownCheck","FlatCap_Blue","FlatCap_Red","BeanieHat_Green","BeanieHat_Black","BeanieHat_Brown","BeanieHat_Beige","BeanieHat_Grey","BeanieHat_Blue","BeanieHat_Red","BeanieHat_Pink","MilitaryBeret_NZ","MilitaryBeret_CDF","MilitaryBeret_UN","MilitaryBeret_Red","MilitaryBeret_ChDKZ","PoliceCap","OfficerHat","PilotkaCap","CowboyHat_green","CowboyHat_black","CowboyHat_darkBrown","CowboyHat_Brown","BoonieHat_Flecktran","BoonieHat_Dubok","BoonieHat_DPM","BoonieHat_Olive","BoonieHat_Tan","BoonieHat_Black","BoonieHat_NavyBlue","BoonieHat_Blue","BoonieHat_Red","BoonieHat_Orange","PrisonerCap","BaseballCap_Camo","BaseballCap_Olive","BaseballCap_Black","BaseballCap_CMMG_Black","BaseballCap_Beige","BaseballCap_Blue","BaseballCap_Red","BaseballCap_Pink","BaseballCap_CMMG_Pink","MedicalScrubsHat_Green","MedicalScrubsHat_White","MedicalScrubsHat_Blue"};
autoptr TStringArray MasksGame = {"SurgicalMask","BandanaMask_PolkaPattern","BandanaMask_RedPattern","BandanaMask_BlackPattern","BandanaMask_GreenPattern","BandanaMask_CamoPattern","NioshFaceMask","HockeyMask","Balaclava3Holes_Blue","Balaclava3Holes_Beige","Balaclava3Holes_Black","Balaclava3Holes_Green","WeldingMask","GP5GasMask"};
autoptr TStringArray ShirtsGame = {"TShirt_OrangeWhiteStripes","TShirt_RedBlackStripes","TShirt_Red","TShirt_Blue","TShirt_White","TShirt_Grey","TShirt_Beige","TShirt_Black","TShirt_Green","TelnyashkaShirt","Shirt_RedCheck","Shirt_BlueCheckBright","Shirt_BlueCheck","Shirt_WhiteCheck","Shirt_PlaneBlack","Shirt_GreenCheck","Blouse_Violet","Blouse_Blue","Blouse_White","Blouse_Green","MedicalScrubsShirt_Blue","MedicalScrubsShirt_White","MedicalScrubsShirt_Green","ChernarusSportShirt","TacticalShirt_Grey","TacticalShirt_Tan","TacticalShirt_Black","TacticalShirt_Olive","Sweater_Red","Sweater_Blue","Sweater_Gray","Sweater_Green","Hoodie_Red","Hoodie_Blue","Hoodie_Grey","Hoodie_Brown","Hoodie_Black","Hoodie_Green","LabCoat","TrackSuitJacket_Red","TrackSuitJacket_LightBlue","TrackSuitJacket_Blue","TrackSuitJacket_Black","TrackSuitJacket_Green","DenimJacket","ManSuit_Blue","ManSuit_White","ManSuit_LightGrey","ManSuit_DarkGrey","ManSuit_Beige","ManSuit_Brown","ManSuit_Black","ManSuit_Khaki","WomanSuit_Blue","WomanSuit_White","WomanSuit_LightGrey","WomanSuit_DarkGrey","WomanSuit_Beige","WomanSuit_Brown","WomanSuit_Black","WomanSuit_Khaki","WoolCoat_Red","WoolCoat_RedCheck","WoolCoat_Blue","WoolCoat_BlueCheck","WoolCoat_GreyCheck","WoolCoat_BrownCheck","WoolCoat_Beige","WoolCoat_Black","WoolCoat_BlackCheck","WoolCoat_Green","RidersJacket_Black","FiautoptrighterJacket_Beige","FiautoptrighterJacket_Black","JumpsuitJacket_Red","JumpsuitJacket_Blue","JumpsuitJacket_Gray","JumpsuitJacket_Green","BomberJacket_Maroon","BomberJacket_SkyBlue","BomberJacket_Blue","BomberJacket_Grey","BomberJacket_Brown","BomberJacket_Black","BomberJacket_Olive","QuiltedJacket_Orange","QuiltedJacket_Yellow","QuiltedJacket_Red","QuiltedJacket_Violet","QuiltedJacket_Blue","QuiltedJacket_Grey","QuiltedJacket_Black","QuiltedJacket_Green","PrisonUniformJacket","PoliceJacketOrel","PoliceJacket","ParamedicJacket_Crimson","ParamedicJacket_Blue","ParamedicJacket_Green","HikingJacket_Red","HikingJacket_Blue","HikingJacket_Black","HikingJacket_Green","Raincoat_Pink","Raincoat_Orange","Raincoat_Yellow","Raincoat_Red","Raincoat_Blue","Raincoat_Black","Raincoat_Green","TTsKOJacket_Camo","BDUJacket","HuntingJacket_Winter","HuntingJacket_Brown","HuntingJacket_Autumn","HuntingJacket_Spring","HuntingJacket_Summer","M65Jacket_Tan","M65Jacket_Black","M65Jacket_Khaki","M65Jacket_Olive","GorkaEJacket_Autumn","GorkaEJacket_Flat","GorkaEJacket_PautRev","GorkaEJacket_Summer","USMCJacket_Desert","USMCJacket_Woodland","NBCJacketGray"};
autoptr TStringArray VestsGame = {"autoptrlexVest","PoliceVest","HuntingVest","PressVest_LightBlue","PressVest_Blue","UKAssVest_Black","UKAssVest_Khaki","UKAssVest_Olive","UKAssVest_Camo","HighCapacityVest_Black","HighCapacityVest_Olive","PlateCarrierVest",};
autoptr TStringArray PantsGame = {"Skirt_Yellow","Skirt_Red","Skirt_Blue","Skirt_White","MiniDress_Pink","MiniDress_PinkChecker","MiniDress_RedChecker","MiniDress_BlueChecker","MiniDress_BlueWithDots","MiniDress_WhiteChecker","MiniDress_BrownChecker","MiniDress_GreenChecker","NurseDress_Blue","NurseDress_White","MedicalScrubsPants_Blue","MedicalScrubsPants_White","MedicalScrubsPants_Green","TrackSuitPants_Red","TrackSuitPants_LightBlue","TrackSuitPants_Blue","TrackSuitPants_Black","TrackSuitPants_Green","PrisonUniformPants","Breeches_Pink","Breeches_Red","Breeches_Blue","Breeches_White","Breeches_Beetcheck","Breeches_Beige","Breeches_Browncheck","Breeches_Black","Breeches_Blackcheck","Breeches_Green","SlacksPants_Blue","SlacksPants_White","SlacksPants_LightGrey","SlacksPants_DarkGrey","SlacksPants_Beige","SlacksPants_Brown","SlacksPants_Black","SlacksPants_Khaki","CanvasPantsMidi_Red","CanvasPantsMidi_Violet","CanvasPantsMidi_Blue","CanvasPantsMidi_Grey","CanvasPantsMidi_Beige","CanvasPants_Red","CanvasPants_Violet","CanvasPants_Blue","CanvasPants_Grey","CanvasPants_Beige","JumpsuitPants_Red","JumpsuitPants_Blue","JumpsuitPants_Grey","JumpsuitPants_Green","PolicePants","ParamedicPants_Crimson","ParamedicPants_Blue","ParamedicPants_Green","FiautoptrightersPants_Beige","FiautoptrightersPants_Black","CargoPants_Blue","CargoPants_Grey","CargoPants_Beige","CargoPants_Black","CargoPants_Green","ShortJeans_Red","ShortJeans_Blue","ShortJeans_Darkblue","ShortJeans_Brown","ShortJeans_Black","ShortJeans_Green","Jeans_Blue","Jeans_BlueDark","Jeans_Grey","Jeans_Brown","Jeans_Black","Jeans_Green","TTSKOPants","BDUPants","USMCPants_Desert","USMCPants_Woodland","PolicePantsOrel","HunterPants_Winter","HunterPants_Brown","HunterPants_Spring","HunterPants_Autumn","HunterPants_Summer","GorkaPants_Flat","GorkaPants_PautRev","GorkaPants_Autumn","GorkaPants_Summer","NBCPantsGray",};
autoptr TStringArray ShoesGame = {"AthleticShoes_Blue","AthleticShoes_Grey","AthleticShoes_Brown","AthleticShoes_Black","AthleticShoes_Green","JoggingShoes_Violet","JoggingShoes_Red","JoggingShoes_Blue","JoggingShoes_White","JoggingShoes_Black","Sneakers_Red","Sneakers_White","Sneakers_Gray","Sneakers_Black","Sneakers_Green","DressShoes_White","DressShoes_Brown","DressShoes_Black","DressShoes_Beige","DressShoes_Sunburst","HikingBootsLow_Blue","HikingBootsLow_Grey","HikingBootsLow_Beige","HikingBootsLow_Black","WorkingBoots_Yellow","WorkingBoots_Grey","WorkingBoots_Beige","WorkingBoots_Brown","WorkingBoots_Green","HikingBoots_Brown","HikingBoots_Black","CombatBoots_Grey","CombatBoots_Beige","CombatBoots_Brown","CombatBoots_Black","CombatBoots_Green","JungleBoots_Beige","JungleBoots_Brown","JungleBoots_Black","JungleBoots_Olive","JungleBoots_Green","Wellies_Grey","Wellies_Brown","Wellies_Black","Wellies_Green","TTSKOBoots","MilitaryBoots_Redpunk","MilitaryBoots_Bluerock","MilitaryBoots_Beige","MilitaryBoots_Brown","MilitaryBoots_Black","NBCBootsGray"};
autoptr TStringArray BeltGame = {"CivilianBelt","MilitaryBelt"};
autoptr TStringArray BagsGame = {"ChildBag_Red","ChildBag_Blue","ChildBag_Green","DryBag_Yellow","DryBag_Orange","DryBag_Red","DryBag_Blue","DryBag_Black","DryBag_Green","TaloonBag_Orange","TaloonBag_Violet","TaloonBag_Blue","TaloonBag_Green","SmershBag","AssaultBag_Black","AssaultBag_Green","AssaultBag_Ttsko","HuntingBag","TortillaBag","CoyoteBag_Brown","CoyoteBag_Green","MountainBag_Orange","MountainBag_Red","MountainBag_Blue","MountainBag_Green","AliceBag_Black","AliceBag_Green","AliceBag_Camo"};
autoptr TStringArray SheltersGame = {"ShelterFabric","ShelterLeather","ShelterStick"};
autoptr TStringArray AnimalsGame = {"Animal_BosTaurusF_Brown","Animal_BosTaurusF_Spotted","Animal_BosTaurusF_White","Animal_BosTaurus_Brown","Animal_BosTaurus_Spotted","Animal_BosTaurus_White","Animal_CanisLupus_Grey","Animal_CanisLupus_White","Animal_CapraHircusF","Animal_CapraHircus_Black","Animal_CapraHircus_Brown","Animal_CapraHircus_White","Animal_CapreolusCapreolus","Animal_CapreolusCapreolusF","Animal_CervusElaphus","Animal_CervusElaphusF","Animal_GallusGallusDomesticus","Animal_GallusGallusDomesticusF_Brown","Animal_GallusGallusDomesticusF_Spotted","Animal_GallusGallusDomesticusF_White","Animal_OvisAries","Animal_OvisAriesF","Animal_SusDomesticus","Animal_SusScrofa","Animal_UrsusArctos"};
autoptr TStringArray ZombiesGame = {"ZmbF_BlueCollarFat_Blue","ZmbF_BlueCollarFat_Green","ZmbF_BlueCollarFat_Red","ZmbF_BlueCollarFat_White","ZmbF_CitizenANormal_Beige","ZmbF_CitizenANormal_Blue","ZmbF_CitizenANormal_Brown","ZmbF_CitizenBSkinny","ZmbF_Clerk_Normal_Blue","ZmbF_Clerk_Normal_Green","ZmbF_Clerk_Normal_Red","ZmbF_Clerk_Normal_White","ZmbF_DoctorSkinny","ZmbF_HikerSkinny_Blue","ZmbF_HikerSkinny_Green","ZmbF_HikerSkinny_Grey","ZmbF_HikerSkinny_Red","ZmbF_JoggerSkinny_Blue","ZmbF_JoggerSkinny_Brown","ZmbF_JoggerSkinny_Green","ZmbF_JoggerSkinny_Red","ZmbF_JournalistNormal_Blue","ZmbF_JournalistNormal_Green","ZmbF_JournalistNormal_Red","ZmbF_JournalistNormal_White","ZmbF_MechanicNormal_Beige","ZmbF_MechanicNormal_Green","ZmbF_MechanicNormal_Grey","ZmbF_MechanicNormal_Orange","ZmbF_MilkMaidOld_Beige","ZmbF_MilkMaidOld_Black","ZmbF_MilkMaidOld_Green","ZmbF_MilkMaidOld_Grey","ZmbF_NurseFat","ZmbF_ParamedicNormal_Blue","ZmbF_ParamedicNormal_Green","ZmbF_ParamedicNormal_Red","ZmbF_PatientOld","ZmbF_PoliceWomanNormal","ZmbF_ShortSkirt_beige","ZmbF_ShortSkirt_black","ZmbF_ShortSkirt_brown","ZmbF_ShortSkirt_checks","ZmbF_ShortSkirt_green","ZmbF_ShortSkirt_grey","ZmbF_ShortSkirt_red","ZmbF_ShortSkirt_stripes","ZmbF_ShortSkirt_white","ZmbF_ShortSkirt_yellow","ZmbF_SkaterYoung_Brown","ZmbF_SkaterYoung_Striped","ZmbF_SkaterYoung_Violet","ZmbF_SurvivorNormal_Blue","ZmbF_SurvivorNormal_Orange","ZmbF_SurvivorNormal_Red","ZmbF_SurvivorNormal_White","ZmbF_VillagerOld_Blue","ZmbF_VillagerOld_Green","ZmbF_VillagerOld_Red","ZmbF_VillagerOld_White","ZmbM_CitizenASkinny_Blue","ZmbM_CitizenASkinny_Brown","ZmbM_CitizenASkinny_Grey","ZmbM_CitizenASkinny_Red","ZmbM_CitizenBFat_Blue","ZmbM_CitizenBFat_Green","ZmbM_CitizenBFat_Red","ZmbM_ClerkFat_Brown","ZmbM_ClerkFat_Grey","ZmbM_ClerkFat_Khaki","ZmbM_ClerkFat_White","ZmbM_CommercialPilotOld_Blue","ZmbM_CommercialPilotOld_Brown","ZmbM_CommercialPilotOld_Grey","ZmbM_CommercialPilotOld_Olive","ZmbM_ConstrWorkerNormal_Beige","ZmbM_ConstrWorkerNormal_Black","ZmbM_ConstrWorkerNormal_Green","ZmbM_ConstrWorkerNormal_Grey","ZmbM_DoctorFat","ZmbM_FarmerFat_Beige","ZmbM_FarmerFat_Blue","ZmbM_FarmerFat_Brown","ZmbM_FarmerFat_Green","ZmbM_FiautoptrighterNormal","ZmbM_FishermanOld_Blue","ZmbM_FishermanOld_Green","ZmbM_FishermanOld_Grey","ZmbM_FishermanOld_Red","ZmbM_HandymanNormal_Beige","ZmbM_HandymanNormal_Blue","ZmbM_HandymanNormal_Green","ZmbM_HandymanNormal_Grey","ZmbM_HandymanNormal_White","ZmbM_HeavyIndustryWorker","ZmbM_HermitSkinny_Beige","ZmbM_HermitSkinny_Black","ZmbM_HermitSkinny_Green","ZmbM_HermitSkinny_Red","ZmbM_HikerSkinny_Blue","ZmbM_HikerSkinny_Green","ZmbM_HikerSkinny_Yellow","ZmbM_HunterOld_Autumn","ZmbM_HunterOld_Spring","ZmbM_HunterOld_Summer","ZmbM_HunterOld_Winter","ZmbM_Jacket_beige","ZmbM_Jacket_black","ZmbM_Jacket_blue","ZmbM_Jacket_bluechecks","ZmbM_Jacket_brown","ZmbM_Jacket_greenchecks","ZmbM_Jacket_grey","ZmbM_Jacket_khaki","ZmbM_Jacket_magenta","ZmbM_Jacket_stripes","ZmbM_JoggerSkinny_Blue","ZmbM_JoggerSkinny_Green","ZmbM_JoggerSkinny_Red","ZmbM_JournalistSkinny","ZmbM_MechanicSkinny_Blue","ZmbM_MechanicSkinny_Green","ZmbM_MechanicSkinny_Grey","ZmbM_MechanicSkinny_Red","ZmbM_MotobikerFat_Beige","ZmbM_MotobikerFat_Black","ZmbM_MotobikerFat_Blue","ZmbM_OffshoreWorker_Green","ZmbM_OffshoreWorker_Orange","ZmbM_OffshoreWorker_Red","ZmbM_OffshoreWorker_Yellow","ZmbM_ParamedicNormal_Black","ZmbM_ParamedicNormal_Blue","ZmbM_ParamedicNormal_Green","ZmbM_ParamedicNormal_Red","ZmbM_PatientSkinny","ZmbM_PatrolNormal_Autumn","ZmbM_PatrolNormal_Flat","ZmbM_PatrolNormal_PautRev","ZmbM_PatrolNormal_Summer","ZmbM_PolicemanFat","ZmbM_PolicemanSpecForce","ZmbM_PrisonerSkinny","ZmbM_SkaterYoung_Blue","ZmbM_SkaterYoung_Brown","ZmbM_SkaterYoung_Green","ZmbM_SkaterYoung_Grey","ZmbM_SoldierNormal","ZmbM_VillagerOld_Blue","ZmbM_VillagerOld_Green","ZmbM_VillagerOld_White","ZmbM_priestPopSkinny","ZmbM_usSoldier_normal_Desert","ZmbM_usSoldier_normal_Woodland"};
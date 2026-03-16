#pragma once

#include "../global.h"

/**
 * \file general_battle_strings.h
 * \brief Contains declarations for many strings used in battle.
 */

#define EOS 0xFF

//New Strings
extern const u8 BattleText_TwoTrainersWantToBattle[];
extern const u8 BattleText_ShadowWarriorAttacked[];
extern const u8 BattleText_ShadowWarriorsAttacked[];
extern const u8 BattleText_InGamePartnerSentOutZGoN[];
extern const u8 BattleText_TwoTrainersSentPkmn[];
extern const u8 BattleText_Trainer2WithdrewPkmn[];
extern const u8 BattleText_Trainer2SentOutPkmn[];
extern const u8 BattleText_TwoWildAttacked[];
extern const u8 BattleText_DistortionWorldMonAttacked[];
extern const u8 BattleText_WorstNightmare[];
extern const u8 BattleText_LegendaryAppeared[];
extern const u8 BattleText_GoTwoPkmn_BattleSands[];
extern const u8 BattleText_GoPkmn_BattleSands[];
extern const u8 BattleText_PartnerWithdrewPkmn[];
extern const u8 BattleText_PartnerSaysGo[];
extern const u8 BattleText_AttackerUsedZStatusMove[];
extern const u8 BattleText_AttackerUsedMaxMove[];
extern const u8 BattleText_AttackerUsedGMaxMove[];
extern const u8 BattleText_TwoInGameTrainersDefeated[];
extern const u8 BattleText_PlayerLostToTwoInGameTrainers[];
extern const u8 TheOpposingString[];
extern const u8 TheShadowString[];
extern const u8 gText_TheWild[];
extern const u8 gText_BlackPlayerPrefix[];

//Rewritten Strings
extern const u8 BattleText_TwoLinkTrainersWantToBattle[];
extern const u8 BattleText_Trainer1WantsToBattle[];
extern const u8 BattleText_Trainer1WantsToBattle_BattleSands[];
extern const u8 BattleText_LinkTrainerWantsToBattle[];
extern const u8 BattleText_WildPkmnAppeared6[];
extern const u8 BattleText_TwoWildPkmnAppeared[];
extern const u8 BattleText_WildPkmnAppearedPause[];
extern const u8 BattleText_WildPkmnAppeared[];
extern const u8 sText_FoePkmnPrefix2[];
extern const u8 sText_FoePkmnPrefix3[];
extern const u8 sText_FoePkmnPrefix4[];
extern const u8 sText_FoePkmnPrefix5[];
extern const u8 sText_TheOpposingCapsNoSpace[];
extern const u8 sText_TheOpposingNoCaps[];
extern const u8 sText_Your[];
extern const u8 sText_YourCaps[];

//Vanilla Strings
#define BattleText_GhostAppeared (u8*) 0x83FD30D
#define BattleText_GhostAppearedNoID (u8*) 0x83FD2D9
#define BattleText_GoTwoPkmn (u8*) 0x83FD466
#define BattleText_LinkPartnerSentOutPkmnGoPkmn (u8*) 0x83FD4B5
#define BattleText_GoTwoPkmn (u8*) 0x83FD466
#define BattleText_GoPkmn (u8*) 0x83FD45E
#define BattleText_TwoLinkTrainersSentOutPkmn (u8*) 0x83FD41E
#define BattleText_LinkTrainerSentOutTwoPkmn (u8*) 0x83FD407
#define BattleText_Trainer1SentOutTwoPkmn (u8*) 0x83FD3C7
#define BattleText_LinkTrainerSentOutPkmn (u8*) 0x83FD3F7
#define BattleText_Trainer1SentOutPkmn (u8*) 0x83FD3B1
#define BattleText_PkmnThatsEnough (u8*) 0x83FD4CD
#define BattleText_PkmnComeBack (u8*) 0x83FD4EB
#define BattleText_PkmnOkComeBack (u8*) 0x83FD4FA
#define BattleText_PkmnGoodComeBack (u8*) 0x83FD50D
#define BattleText_LinkTrainer2WithdrewPkmn (u8*) 0x83FD545
#define BattleText_LinkTrainer1WithdrewPkmn (u8*) 0x83FD535
#define BattleText_Trainer1WithdrewPkmn (u8*) 0x83FD522
#define BattleText_GoPkmn2 (u8*) 0x83FD475
#define BattleText_DoItPkmn (u8*) 0x83FD47D
#define BattleText_GoForItPkmn (u8*) 0x83FD488
#define BattleText_YourFoesWeakGetEmPkmn (u8*) 0x83FD497
#define BattleText_Trainer1SentOutPkmn2 (u8*) 0x83FD3E4
#define BattleText_LinkTrainerMultiSentOutPkmn (u8*) 0x83FD44E
#define BattleText_Trainer1SentOutPkmn2 (u8*) 0x83FD3E4
#define BattleText_LinkTrainerSentOutPkmn2 (u8*) 0x83FD43E
#define BattleText_Trainer1SentOutPkmn2 (u8*) 0x83FD3E4
#define BattleText_AttackerUsedX (u8*) 0x83FD57B
#define BattleText_GotAwaySafely (u8*) 0x83FCC8A
#define BattleText_TwoWildFled (u8*) 0x83FCD9F
#define BattleText_C00Fled (u8*) 0x83FE9D4
#define BattleText_WildFled (u8*) 0x83FCD92
#define BattleText_TwoLinkTrainersDefeated (u8*) 0x83FCCF8
#define BattleText_PlayerLostToTwo (u8*) 0x83FCD27
#define BattleText_PlayerBattledToDrawVsTwo (u8*) 0x83FCD66
#define BattleText_PlayerDefeatedLinkTrainer1 (u8*) 0x83FD1C7
#define BattleText_PlayerLostAgainstTrainer1 (u8*) 0x83FE9E4
#define BattleText_PlayerBattledToDrawTrainer1 (u8*) 0x83FE9FF
#define BattleText_PlayerDefeatedLinkTrainer (u8*) 0x83FCCE4
#define BattleText_PlayerLostAgainstLinkTrainer (u8*) 0x83FCD0F
#define BattleText_PlayerBattledToDrawLinkTrainer (u8*) 0x83FCD41
#define sText_AllyPkmnPrefix (u8*) 0x83FD564
#define sText_AllyPkmnPrefix2 (u8*) 0x83FD56D
#define sText_AllyPkmnPrefix3 (u8*) 0x83FD576

#define sText_Someones (u8*) 0x83FD81A
#define sText_Bills	(u8*) 0x83FD824

extern const u8 gText_ProtectedByTerrain[];
extern const u8 gText_ReflectType[];
extern const u8 gText_Purify[];
extern const u8 gText_BecameNimble[];
extern const u8 gText_FreezeShockCharging[];
extern const u8 gText_IceBurnCharging[];
extern const u8 gText_ShadowForce[];
extern const u8 gText_LaserFocus[];
extern const u8 gText_BurnUp[];
extern const u8 gText_UTurn[];
extern const u8 gText_RemoveFog[];
extern const u8 gText_SpectralThief[];
extern const u8 gText_StockpileWoreOff[];
extern const u8 gText_Bestow[];
extern const u8 gText_AquaRingSet[];
extern const u8 gText_CantUseHyperspaceFury[];
extern const u8 gText_CantUseMove[];
extern const u8 gText_WrongHoopaForm[];
extern const u8 gText_PsychoShift[];
extern const u8 gText_GeomancyCharge[];
extern const u8 gText_PowerHerb[];
extern const u8 gText_PowerTrick[];
extern const u8 gText_PowerSwap[];
extern const u8 gText_GuardSwap[];
extern const u8 gText_SpeedSwap[];
extern const u8 gText_HeartSwap[];
extern const u8 gText_PowerSplit[];
extern const u8 gText_GuardSplit[];
extern const u8 gText_PledgeReady[];
extern const u8 gText_PledgeCombined[];
extern const u8 gText_Swamp[];
extern const u8 gText_SeaOfFire[];
extern const u8 gText_Rainbow[];
extern const u8 gText_Fling[];
extern const u8 gText_ProtectLifted[];
extern const u8 gText_HealBlockSet[];
extern const u8 gText_EmbargoSet[];
extern const u8 gText_PowderSet[];
extern const u8 gText_TelekinesisSet[];
extern const u8 gText_HealBlockTarget[];
extern const u8 gText_Electrify[];
extern const u8 gText_TopsyTurvy[];
extern const u8 gText_AfterYou[];
extern const u8 gText_Quash[];
extern const u8 gText_MagnetRiseSet[];
extern const u8 gText_FlameBurst[];

extern const u8 gText_SlappedAwake[];
extern const u8 gText_BurnCured[];
extern const u8 gText_ItemCantBeRemoved[];

extern const u8 gText_HealingWishHeal[];
extern const u8 gText_LunarDanceHeal[];
extern const u8 gText_PrimalRainEnd[];
extern const u8 gText_PrimalSunEnd[];
extern const u8 gText_PrimalAirCurrentEnd[];

extern const u8 gText_SkyDropUp[];
extern const u8 gText_FreedFromSkyDrop[];
extern const u8 gText_AbilitySuppressed[];
.text
.thumb
.align 2
/*
battle_start_turn_start_battle_scripts.s
	scripts to support battle start and turn start
*/

.include "../asm_defines.s"
.include "../battle_script_macros.s"

.global BattleScript_AirBalloonFloat
.global BattleScript_AirBalloonSub
.global BattleScript_Totem
.global BattleScript_TotemRet
.global BattleScript_TotemOmniboost
.global BattleScript_TotemOmniboostRet
.global BattleScript_TotemMultiBoost
.global BattleScript_TotemMultiBoostRet
.global BattleScript_Primal
.global BattleScript_PrimalSub
.global BattleScript_ElectricTerrainBattleBegin
.global BattleScript_GrassyTerrainBattleBegin
.global BattleScript_MistyTerrainBattleBegin
.global BattleScript_PsychicTerrainBattleBegin
.global BattleScript_PixieBoost
.global BattleScript_PixieBoostRet
.global BattleScript_QuickClaw
.global BattleScript_QuickDraw
.global BattleScript_FocusPunchSetUp
.global BattleScript_BeakBlastSetUp
.global BattleScript_ShellTrapSetUp
.global BattleScript_NoTargetMoveFailed
.global BattleScript_CamomonsTypeRevealRet
.global BattleScript_CamomonsTypeRevealEnd3
.global BattleScript_DynamaxEnergySwirl
.global BattleScript_RaidBattleStart
.global BattleScript_RaidBattleStart_NoDynamax
.global BattleScript_RaidBattleStorm
.global BattleScript_RaidShieldsBattleStart

.global StringNull

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_AirBalloonFloat:
	call BattleScript_AirBalloonSub
	end3

BattleScript_AirBalloonSub:
	jumpifspecialstatusflag BANK_ATTACKER STATUS3_AIR_BALLOON_BS 0x0 AirBalloonFloatEnd
	setspecialstatusbit BANK_ATTACKER STATUS3_AIR_BALLOON_BS
	setword BATTLE_STRING_LOADER gText_AirBalloonEntry
	printstring 0x184
	waitmessage DELAY_1SECOND
AirBalloonFloatEnd:
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_Totem:
	call BattleScript_TotemRet
	end3

BattleScript_TotemMultiBoost:
	call BattleScript_TotemMultiBoostRet
	end3

BattleScript_TotemOmniboost:
	call BattleScript_TotemOmniboostRet
	end3

BattleScript_TotemRet:
	playanimation BANK_ATTACKER ANIM_TOTEM_BOOST 0x0
	setword BATTLE_STRING_LOADER gText_TotemAuraFlared
	printstring 0x184
	waitmessage DELAY_1SECOND
	statbuffchange STAT_ATTACKER | STAT_BS_PTR .LReturn
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x2 .LReturn
	setgraphicalstatchangevalues
	playanimation BANK_ATTACKER 0x1 ANIM_ARG_1
	printfromtable gStatUpStringIds
	waitmessage DELAY_1SECOND
.LReturn:
	return

BattleScript_TotemMultiBoostRet:
	playanimation BANK_ATTACKER ANIM_TOTEM_BOOST 0x0
	setword BATTLE_STRING_LOADER gText_TotemAuraFlared
	printstring 0x184
	waitmessage DELAY_1SECOND
	callasm ToggleTotemOmniboostByte
	playstatchangeanimation BANK_ATTACKER, 0xFF, STAT_ANIM_UP | STAT_ANIM_IGNORE_ABILITIES
	callasm ToggleTotemOmniboostByte
	statbuffchange STAT_ATTACKER | STAT_BS_PTR BattleScript_TotemMultiBoost_SecondStat
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x2 BattleScript_TotemMultiBoost_SecondStat
	setgraphicalstatchangevalues
	printfromtable gStatUpStringIds
	waitmessage DELAY_1SECOND
BattleScript_TotemMultiBoost_SecondStat:
	callasm LoadTotemMultiBoostSecondStat
	statbuffchange STAT_ATTACKER | STAT_BS_PTR .LReturn
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x2 .LReturn
	setgraphicalstatchangevalues
	printfromtable gStatUpStringIds
	waitmessage DELAY_1SECOND
	return

BattleScript_TotemOmniboostRet:
	playanimation BANK_ATTACKER ANIM_TOTEM_BOOST 0x0
	setword BATTLE_STRING_LOADER gText_TotemAuraFlared
	printstring 0x184
	waitmessage DELAY_1SECOND
	callasm ToggleTotemOmniboostByte
	playstatchangeanimation BANK_ATTACKER, 0xFF, STAT_ANIM_UP | STAT_ANIM_IGNORE_ABILITIES
	callasm ToggleTotemOmniboostByte
	setword BATTLE_STRING_LOADER gText_TotemOmniboostStatsRose
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_Primal:
	call BattleScript_PrimalSub
	end3

BattleScript_PrimalSub:
	jumpifspecies BANK_ATTACKER SPECIES_GROUDON_PRIMAL PGroudonAnim
	jumpifspecies BANK_ATTACKER SPECIES_KYOGRE_PRIMAL PKyogreAnim
	playanimation BANK_ATTACKER ANIM_TRANSFORM 0x0

RegularPrimalAnim:
	goto PrimalStringDisplay

PGroudonAnim:
	playanimation BANK_ATTACKER ANIM_RED_PRIMAL_REVERSION 0x0
	goto PrimalStringDisplay
	
PKyogreAnim:
	playanimation BANK_ATTACKER ANIM_BLUE_PRIMAL_REVERSION 0x0
	
PrimalStringDisplay:
	callasm UpdatePrimalAbility
	reloadhealthbar BANK_ATTACKER
	setword BATTLE_STRING_LOADER gText_PrimalReversion
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_ElectricTerrainBattleBegin:
	setword BATTLE_STRING_LOADER gText_ElectricTerrainBattleBegin
	printstring 0x184
	playanimation 0x0 ELECTRIC_TERRAIN_ACTIVE_ANIM 0x0
	end3

BattleScript_GrassyTerrainBattleBegin:
	setword BATTLE_STRING_LOADER gText_GrassyTerrainBattleBegin
	printstring 0x184
	playanimation 0x0 GRASSY_TERRAIN_ACTIVE_ANIM 0x0
	end3

BattleScript_MistyTerrainBattleBegin:
	setword BATTLE_STRING_LOADER gText_MistyTerrainBattleBegin
	printstring 0x184
	playanimation 0x0 MISTY_TERRAIN_ACTIVE_ANIM 0x0
	end3

BattleScript_PsychicTerrainBattleBegin:
	setword BATTLE_STRING_LOADER gText_PsychicTerrainBattleBegin
	printstring 0x184
	playanimation 0x0 PSYCHIC_TERRAIN_ACTIVE_ANIM 0x0
	end3

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_PixieBoost:
	call BattleScript_PixieBoostRet
	end3

BattleScript_PixieBoostRet:
	statbuffchange STAT_ATTACKER | STAT_BS_PTR .LReturn
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x2 .LReturn
	setgraphicalstatchangevalues
	playanimation BANK_ATTACKER 0x1 ANIM_ARG_1
	setword BATTLE_STRING_LOADER gText_PixieBattleBuff
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_QuickClaw:
	setword BATTLE_STRING_LOADER StringNull
	printstring 0x184
	setword BATTLE_STRING_LOADER gText_ItemIncreasedSpeedBracket
	jumpifhelditemeffect 0xA ITEM_EFFECT_QUICK_CLAW QuickClawBS
	playanimation 0xA ANIM_BERRY_EAT 0x0
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	call BattleScript_CheekPouch
	end3

QuickClawBS:
	playanimation 0xA ANIM_ITEM_USE 0x0
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	end3

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_QuickDraw:
	setword BATTLE_STRING_LOADER StringNull
	printstring 0x184
	call BattleScript_AbilityPopUp
	setword BATTLE_STRING_LOADER gText_AbilityIncreasedSpeedBracket
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	call BattleScript_AbilityPopUpRevert
	end3

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_FocusPunchSetUp:
	printstring 0x130
	waitmessage 0xA
	playanimation 0xA ANIM_FOCUS_PUNCH_PUMP 0x0
	printstring 0xAB
	waitmessage DELAY_1SECOND
	end3

BattleScript_BeakBlastSetUp:
	printstring 0x130
	waitmessage 0xA
	playanimation 0xA ANIM_BEAK_BLAST_WARM_UP 0x0
	setword BATTLE_STRING_LOADER gText_BeakBlastWarmUp
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_ShellTrapSetUp:
	printstring 0x130
	waitmessage 0xA
	playanimation 0xA ANIM_SHELL_TRAP_SET 0x0
	setword BATTLE_STRING_LOADER gText_ShellTrapSet
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_NoTargetMoveFailed:
	attackcanceler
	goto FAILED - 2

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_CamomonsTypeRevealEnd3:
	call BattleScript_CamomonsTypeRevealRet
	end3

BattleScript_CamomonsTypeRevealRet:
	printstring 0x184
	waitmessage DELAY_1SECOND
	return
	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_RaidBattleStart:
	playanimation BANK_SCRIPTING ANIM_DYNAMAX_START 0x0
	printstring 0x184
	waitmessage DELAY_1SECOND
BattleScript_RaidBattleStart_NoDynamax:
	setword BATTLE_STRING_LOADER gText_RaidBattleStormStarted
	call BattleScript_RaidBattleStorm
	end3
	
BattleScript_RaidBattleStorm:
	playanimation BANK_SCRIPTING ANIM_RAID_BATTLE_STORM 0x0
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_DynamaxEnergySwirl:
	playanimation BANK_SCRIPTING ANIM_DYNAMAX_ENERGY_SWIRL 0x0
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_RaidShieldsBattleStart:
	pause 0x20
	callasm CreateRaidShieldSprites
	pause 0x10
	setword BATTLE_STRING_LOADER gText_RaidShield
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

StringNull: .byte 0xFF

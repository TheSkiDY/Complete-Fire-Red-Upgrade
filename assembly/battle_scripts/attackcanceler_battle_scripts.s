.text
.thumb
.align 2
/*
attackcanceler_battle_scripts.s
	battle scripts to support attackcanceler battle command
*/

.include "../asm_defines.s"
.include "../battle_script_macros.s"

.global BattleScript_PrintCustomString
.global BattleScript_QuickClaw
.global BattleScript_MagicBounce
.global BattleScript_MoveUsedFlinched
.global BattleScript_MoveUsedDevolvedForgot
.global BattleScript_MoveUsedIsConfused
.global BattleScript_MoveUsedLoafingAround
.global BattleScript_MoveUsedGravityPrevents
.global BattleScript_MoveUsedHealBlockPrevents
.global BattleScript_MoveUsedThroatChopPrevents
.global BattleScript_MoveUsedFailedPrimalWeather
.global BattleScript_MoveUsedPsychicTerrainPrevents
.global BattleScript_MoveUsedPowderPrevents
.global BattleScript_StanceChangeToBlade
.global BattleScript_StanceChangeToShield
.global BattleScript_ZMoveActivateStatus
.global BattleScript_ZMoveActivateDamaging
.global BattleScript_DarkTypePreventsPrankster
.global BattleScript_MoveUsedSkyBattlePrevents
.global BattleScript_MoveUsedRingChallengePrevents
.global BattleScript_CantUseSignatureMove
.global BattleScript_HoopaCantUseHyperspaceFury
.global BattleScript_MoveUsedDynamaxPrevents
.global BattleScript_MoveUsedRaidBattlePrevents
.global BattleScript_MoveUsedRaidShieldPrevents
.global BattleScript_RaidBattleStatNullification

.global BattleScript_TryRemoveIllusion
.global gText_AbilityRaisedStatString

@;@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_PrintCustomString:
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MagicBounce:
	call BattleScript_AttackstringBackupScriptingBank
	ppreduce
	pause 0x10
	call BattleScript_AbilityPopUp
	setword BATTLE_STRING_LOADER gText_MagicBounce
	printstring 0x184
	waitmessage DELAY_1SECOND	
	call BattleScript_AbilityPopUpRevert
	orword HIT_MARKER, HITMARKER_ATTACKSTRING_PRINTED | HITMARKER_NO_PPDEDUCT | HITMARKER_x800000
	various BANK_ATTACKER 0x1
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedFlinched:
	printstring 0x4A
	waitmessage DELAY_1SECOND
	jumpifability BANK_ATTACKER ABILITY_STEADFAST SteadfastBoost
	goto BS_MOVE_END

SteadfastBoost:
	jumpifstat BANK_ATTACKER LESSTHAN STAT_ATK STAT_MAX SteadfastAtk
	jumpifstat BANK_ATTACKER EQUALS STAT_SPD STAT_MAX BS_MOVE_END

SteadfastAtk:
	copyarray BATTLE_SCRIPTING_BANK USER_BANK 0x1
	call BattleScript_AbilityPopUp
	setbyte 0x2023FDF 0x0
	playstatchangeanimation BANK_ATTACKER, STAT_ANIM_ATK | STAT_ANIM_SPD, STAT_ANIM_UP
	setstatchanger STAT_ATK | INCREASE_1
	statbuffchange STAT_ATTACKER | STAT_BS_PTR | STAT_CERTAIN SteadfastSpd
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x2 SteadfastSpd
	copyarray 0x2023FDB USER_BANK 0x1
	printfromtable 0x83FE57C
	waitmessage DELAY_1SECOND

SteadfastSpd:
	setstatchanger STAT_SPD | INCREASE_1
	statbuffchange STAT_ATTACKER | STAT_BS_PTR | STAT_CERTAIN SteadfastEnd
	copyarray 0x2023FDB USER_BANK 0x1
	printfromtable 0x83FE57C
	waitmessage DELAY_1SECOND
	goto SteadfastEnd

SteadfastEnd:
	call BattleScript_AbilityPopUpRevert
	goto BS_MOVE_END
	
@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedDevolvedForgot:
	setword BATTLE_STRING_LOADER gText_DevolvedForgotMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedIsConfused:
	printstring 65 @;STRINGID_PKMNISCONFUSED
	waitmessage DELAY_1SECOND
	chosenstatusanimation BANK_ATTACKER TRUE STATUS2_CONFUSION
	goto 0x81D90DF

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedLoafingAround:
	call BS_FLUSH_MESSAGE_BOX
	jumpifbyte EQUALS MULTISTRING_CHOOSER 0x4 BattleScript_TruantLoafingAround
	printfromtable 0x83FE61A @;gInobedientStringIds
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

BattleScript_TruantLoafingAround:
	setbyte MULTISTRING_CHOOSER 0x0
	call BattleScript_AbilityPopUp
	printfromtable 0x83FE61A @;gInobedientStringIds
	waitmessage DELAY_1SECOND
	call BattleScript_AbilityPopUpRevert
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedGravityPrevents:
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_GravityAttackCancelString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto 0x81D694E

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedHealBlockPrevents:
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_HealBlockAttackCancelString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedThroatChopPrevents:
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_ThroatChopAttackCancelString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedFailedPrimalWeather:
	orbyte OUTCOME OUTCOME_FAILED
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	jumpifhalfword ANDS WEATHER_FLAGS weather_harsh_sun HarshSunEvaportionBS
	setword BATTLE_STRING_LOADER gText_MoveFizzledInHeavyRainString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

HarshSunEvaportionBS:
	setword BATTLE_STRING_LOADER gText_MoveEvaporatedInHarshSunString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedPsychicTerrainPrevents:
	orbyte OUTCOME OUTCOME_FAILED
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	setword BATTLE_STRING_LOADER gText_PsychicTerrainAttackCancelString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedPowderPrevents:
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	playanimation BANK_ATTACKER ANIM_POWDER_EXPLOSION 0x0
	jumpifability BANK_ATTACKER ABILITY_MAGICGUARD SkipPowderDamage
	graphicalhpupdate BANK_ATTACKER
	datahpupdate BANK_ATTACKER

SkipPowderDamage:
	setword BATTLE_STRING_LOADER gText_PowderExplosionString
	printstring 0x184
	waitmessage DELAY_1SECOND
	faintpokemon BANK_ATTACKER 0x0 0x0
	orbyte OUTCOME 0x1
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_StanceChangeToBlade:
	call BS_FLUSH_MSGBOX
	call BattleScript_AbilityPopUp
	playanimation BANK_ATTACKER ANIM_TRANSFORM 0x0
	setword BATTLE_STRING_LOADER gText_SwitchedToBladeForm
	printstring 0x184
	waitmessage DELAY_1SECOND
	call BattleScript_AbilityPopUpRevert
	return

BattleScript_StanceChangeToShield:
	call BS_FLUSH_MSGBOX
	call BattleScript_AbilityPopUp
	playanimation BANK_ATTACKER ANIM_TRANSFORM 0x0
	setword BATTLE_STRING_LOADER gText_SwitchedToShieldForm
	printstring 0x184
	waitmessage DELAY_1SECOND
	call BattleScript_AbilityPopUpRevert
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_ZMoveActivateStatus:
	call BattleScript_TryRemoveIllusion
	setword BATTLE_STRING_LOADER gText_ZPowerSurroundsString
	printstring 0x184
	playanimation BANK_ATTACKER ANIM_ZMOVE_ACTIVATE 0x0
	callasm SetZEffect+1
	setword BATTLE_STRING_LOADER gText_ZMoveUnleashedString
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_ZMoveActivateDamaging:
	call BattleScript_TryRemoveIllusion
	setword BATTLE_STRING_LOADER gText_ZPowerSurroundsString
	printstring 0x184
	playanimation BANK_ATTACKER ANIM_ZMOVE_ACTIVATE 0x0
	setword BATTLE_STRING_LOADER gText_ZMoveUnleashedString
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_TryRemoveIllusion:
	jumpifspecialstatusflag BANK_SCRIPTING STATUS3_ILLUSION 0x1 RemoveIllusionReturn
	@;remove illusion counter
	call BS_FLUSH_MESSAGE_BOX
	clearspecialstatusbit BANK_SCRIPTING STATUS3_ILLUSION
	callasm ClearScriptingBankDisguisedAs
	reloadhealthbar BANK_SCRIPTING
	playanimation BANK_SCRIPTING ANIM_TRANSFORM 0x0
	setword BATTLE_STRING_LOADER gText_IllusionWoreOffString
	printstring 0x184
	waitmessage DELAY_1SECOND
RemoveIllusionReturn:
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_DarkTypePreventsPrankster:
	orbyte OUTCOME OUTCOME_NOT_AFFECTED
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	printstring 27 @;STRINGID_IT_DOESNT_AFFECT
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedSkyBattlePrevents:
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_SkyBattleAttackCancelString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedRingChallengePrevents:
	attackstring
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_RingChallengeBanSpecificMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_CantUseSignatureMove:
	attackstring
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER CantUseHyperspaceFuryString
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

BattleScript_HoopaCantUseHyperspaceFury:
	attackstring
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_WrongHoopaForm
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedDynamaxPrevents:
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_DynamaxAttackCancel
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedRaidBattlePrevents:
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_RaidBattleAttackCancel
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_MoveUsedRaidShieldPrevents:
	attackstring
	ppreduce
	pause DELAY_HALFSECOND
	orbyte OUTCOME OUTCOME_FAILED
	setword BATTLE_STRING_LOADER gText_RaidShieldProtected
	printstring 0x184
	waitmessage DELAY_1SECOND
	goto BS_MOVE_END

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

BattleScript_RaidBattleStatNullification:
	call BS_FLUSH_MSGBOX
	playanimation BANK_SCRIPTING ANIM_RAID_BATTLE_ENERGY_BURST 0x0
	setword BATTLE_STRING_LOADER gText_RaidBattleStatNullification
	printstring 0x184
	waitmessage DELAY_1SECOND
	refreshhpbar BANK_SCRIPTING
	return

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


.text
.thumb
.align 2
/*
z_effect_battle_scripts.s
	handles implementing z move effects
*/

.include "../asm_defines.s"
.include "../battle_script_macros.s"

.global BattleScript_StatsResetZMove
.global BattleScript_AllStatsUpZMove
.global BattleScript_BoostCritsZMove
.global BattleScript_FollowMeZMove
.global BattleScript_RecoverHPZMove
.global BattleScript_StatUpZMove
.global BattleScript_SetUpHealReplacementZMove
.global BattleScript_HealReplacementZMove

BattleScript_StatsResetZMove:
	setword BATTLE_STRING_LOADER gText_StatsResetZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_AllStatsUpZMove:
	setword BATTLE_STRING_LOADER gText_StatsRaisedZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_BoostCritsZMove:
	setword BATTLE_STRING_LOADER gText_CritBoostedZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_FollowMeZMove:
	printstring 0xA4
	waitmessage DELAY_1SECOND
	return

BattleScript_RecoverHPZMove:
	orword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	graphicalhpupdate BANK_SCRIPTING
	datahpupdate BANK_SCRIPTING
	setword BATTLE_STRING_LOADER gText_HPRestoredZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	bicword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	return
	
BattleScript_StatUpZMove:
	playanimation BANK_SCRIPTING 0x1 0x2023FD4
	setword BATTLE_STRING_LOADER gText_StatRaisedZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_SetUpHealReplacementZMove:
	setword BATTLE_STRING_LOADER gText_HPWillRestoreZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	return

BattleScript_HealReplacementZMove:
	orword HIT_MARKER HITMARKER_IGNORE_SUBSTITUTE
	playanimation BANK_SCRIPTING ANIM_HEALING_WISH_HEAL 0x0
	setword BATTLE_STRING_LOADER gText_HPSwitchInRestoredZMove
	printstring 0x184
	waitmessage DELAY_1SECOND
	playanimation BANK_SCRIPTING ANIM_HEALING_SPARKLES 0x0
	graphicalhpupdate BANK_SCRIPTING
	datahpupdate BANK_SCRIPTING
	bicword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	return

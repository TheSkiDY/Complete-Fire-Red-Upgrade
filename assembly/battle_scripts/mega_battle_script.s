.text
.thumb
.align 2
/*
mega_battle_scripts.s
	handles mega evolution
*/

.include "../asm_defines.s"
.include "../battle_script_macros.s"

.global BattleScript_MegaEvolution
.global BattleScript_MegaWish
.global BattleScript_UltraBurst
.global BattleScript_Dynamax

BattleScript_MegaEvolution:
	setword BATTLE_STRING_LOADER gText_MegaReacting
	printstring 0x184
	waitmessage DELAY_HALFSECOND

MegaAnimBS:
	playanimation BANK_SCRIPTING ANIM_MEGA_EVOLUTION 0x0
	reloadhealthbar BANK_SCRIPTING
	setword BATTLE_STRING_LOADER gText_MegaEvolutionComplete
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_MegaWish:
	setword BATTLE_STRING_LOADER gText_FerventWish
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	goto MegaAnimBS

BattleScript_UltraBurst:
	setword BATTLE_STRING_LOADER gText_UltraBurstGlowing
	printstring 0x184
	waitmessage DELAY_HALFSECOND
	playanimation BANK_SCRIPTING ANIM_ULTRA_BURST 0x0
	reloadhealthbar BANK_SCRIPTING
	setword BATTLE_STRING_LOADER gText_UltraBurstComplete
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_Dynamax:
	call BS_FLUSH_MESSAGE_BOX
	callasm UpdateHPForDynamax
	playanimation BANK_SCRIPTING ANIM_CALL_BACK_POKEMON
	waitanimation
	pause DELAY_1SECOND
	pause DELAY_HALFSECOND
	returntoball BANK_SCRIPTING
	call BattleScript_TryRevertCramorant

BattleScript_Dynamax_Rejoin:
	waitstateatk
	callasm TryDoDynamaxTrainerSlide
	callasm SetAndTransferDontRemoveTransformSpecies
	callasm BackupScriptingBankMoveSelectionCursor @;Prevents the move selection cursor from being reset by the switch-in anim
	switchinanim BANK_SCRIPTING 0x1 @;Play the switch-in animation
	waitanimation
	callasm RestoreScriptingBankMoveSelectionCursor
	callasm ClearAndTransferDontRemoveTransformSpecies
	playanimation BANK_SCRIPTING ANIM_DYNAMAX_START 0x0
	orword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	graphicalhpupdate BANK_SCRIPTING
	datahpupdate BANK_SCRIPTING
	bicword HIT_MARKER, HITMARKER_IGNORE_SUBSTITUTE
	setword BATTLE_STRING_LOADER gText_MonDynamaxed
	printstring 0x184
	waitmessage DELAY_1SECOND
	end3

BattleScript_TryRevertCramorant:
	formchange BANK_SCRIPTING SPECIES_CRAMORANT_GULPING SPECIES_CRAMORANT TRUE TRUE FALSE BattleScript_TryRevertGorgingCramorant
BattleScript_TryRevertGorgingCramorant:
	formchange BANK_SCRIPTING SPECIES_CRAMORANT_GORGING SPECIES_CRAMORANT TRUE TRUE FALSE BattleScript_Dynamax_Rejoin
	goto BattleScript_Dynamax_Rejoin

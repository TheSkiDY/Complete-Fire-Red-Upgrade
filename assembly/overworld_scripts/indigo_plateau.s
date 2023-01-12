.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_IndigoPlateau_InviteGirl_Start
.global gIndigoPlateauScripts


@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

EventScript_IndigoPlateau_InviteGirl_Start:
	lock
	faceplayer
	checkflag 0x82C
	if 0x1 _goto IndigoPlateau_InviteGirl_NoEntry
	msgbox 0x819A8D8 MSG_KEEPOPEN
	release
	end

IndigoPlateau_InviteGirl_NoEntry:
	checkflag 0x844
	if 0x1 _goto IndigoPlateau_InviteGirl_AfterLoreleiCheck
	msgbox 0x819A943 MSG_KEEPOPEN
	release
	end

IndigoPlateau_InviteGirl_AfterLoreleiCheck:
	msgbox 0x819A8D8 MSG_KEEPOPEN
	release
	end

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

gIndigoPlateauScripts:
	mapscript MAP_SCRIPT_ON_TRANSITION IndigoPlateau_MoveInviteGirl
	mapscript MAP_SCRIPT_ON_RESUME IndigoPlateau_CallSpecial
	.byte MAP_SCRIPT_TERMIN

IndigoPlateau_MoveInviteGirl:
	sethealingplace 0xA
	checkflag 0x82C
	if 0x1 _call IndigoPlateau_LoreleiMissing
	end

IndigoPlateau_LoreleiMissing:
	checkflag 0x844
	if 0x1 _goto IndigoPlateau_End
	movesprite2 0x4 0x4 0x2
	return

IndigoPlateau_End:
	return

IndigoPlateau_CallSpecial:
	special 0x182
	end

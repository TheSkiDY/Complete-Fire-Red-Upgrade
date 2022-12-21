.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_IndigoPlateau_FromHereOnGirl_Start
.global MapScript_IndigoPlateau_Start

EventScript_IndigoPlateau_FromHereOnGirl_Start:
	lock
	faceplayer
	checkflag 0x82C
	if 0x1 _goto EventScript_IndigoPlateau_FromHereOnGirl_NoEntry
	msgbox 0x819A8D8 MSG_KEEPOPEN
	release
	end

EventScript_IndigoPlateau_FromHereOnGirl_NoEntry:
	checkflag 0x844
	if 0x1 _goto EventScript_IndigoPlateau_FromHereOnGirl_AfterLoreleiCheck
	msgbox 0x819A943 MSG_KEEPOPEN
	release
	end

EventScript_IndigoPlateau_FromHereOnGirl_AfterLoreleiCheck:
	msgbox 0x819A8D8 MSG_KEEPOPEN
	release
	end

MapScript_IndigoPlateau_Start:
	sethealingplace 0xA
	checkflag 0x82C
	if 0x1 _call MapScript_IndigoPlateau_LoreleiMissing
	end

MapScript_IndigoPlateau_LoreleiMissing:
	checkflag 0x844
	if 0x1 _goto MapScript_IndigoPlateau_End
	movesprite2 0x4 0x4 0x2
	return

MapScript_IndigoPlateau_End:
	return

.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global ItemScript_PortablePC
.global ItemScript_InfiniteRepel

ItemScript_PortablePC:
	lockall
	callasm IsPortablePCBanned
	compare LASTRESULT 0x1
	if 0x1 _goto IS_PortablePCBanned
	sound 0x4
	setvar 0x8006 0x0
	loadpointer 0x0 gText_PortablePCOption1
	special 0x25
	setvar 0x8006 0x1
	loadpointer 0x0 gText_PortablePCOption2
	special 0x25
	setvar 0x8006 0x2
	loadpointer 0x0 gText_PortablePCOption3
	special 0x25
	preparemsg gText_PortablePCOpened
	waitmsg
	multichoice 0x0 0x0 0x21 0x0
	compare LASTRESULT 0x0
	if 0x1 _goto IS_HealPokemon
	compare LASTRESULT 0x1
	if 0x1 _goto IS_OpenPC
	compare LASTRESULT 0x2
	if 0x1 _goto IS_ClosePortablePC
	goto IS_ClosePortablePC
	end

IS_PortablePCBanned:
	msgbox gText_CantUsePortablePC MSG_KEEPOPEN
	closeonkeypress
	releaseall
	end

IS_ClosePortablePC:
	sound 0x3
	releaseall
	end

IS_HealPokemon:
	closeonkeypress
	special 0x0
	sound 0x1
	pause 0x10
	checksound
	msgbox gText_PokemonHealedByPortablePC MSG_NORMAL
	goto IS_ClosePortablePC

IS_OpenPC:
	special 0x3C
	waitstate
	goto IS_ClosePortablePC

ItemScript_InfiniteRepel:
	lockall
	checkflag 0x911
	if 0x1 _goto IS_InfRepelTurnOff
	goto IS_InfRepelTurnOn
	end

IS_InfRepelTurnOn:
	setflag 0x911
	msgbox gText_InfiniteRepelActivated MSG_KEEPOPEN
	closeonkeypress
	goto IS_InfRepelEnd
	end

IS_InfRepelTurnOff:
	clearflag 0x911
	msgbox gText_InfiniteRepelDeactivated MSG_KEEPOPEN
	closeonkeypress
	goto IS_InfRepelEnd
	end

IS_InfRepelEnd:
	releaseall
	end


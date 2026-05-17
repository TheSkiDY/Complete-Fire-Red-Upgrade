.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global ItemScript_PortablePC
.global ItemScript_Crate

ItemScript_PortablePC:
	lockall
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

ItemScript_Crate:
	lockall
	callasm RandomizeBattleRewardItems
	callasm FirstRewardMultichoiceSetup
	preparemsg gText_CrateOpened
	waitmsg
	multichoice 0x0 0x0 0x23 0x1
	callasm SaveFirstReward
	goto Crate_SecondChoice
	end

Crate_SecondChoice:
	callasm SecondRewardMultichoiceSetup
	preparemsg gText_CrateSecondChoice
	waitmsg
	multichoice 0x0 0x0 0x22 0x1
	callasm SaveSecondReward
	goto Crate_GiveItems
	end

Crate_GiveItems:
	callasm SetVarsChosenItems
	giveitem 0x5050 0x5052 MSG_OBTAIN
	giveitem 0x5051 0x5053 MSG_OBTAIN
	goto Crate_Close
	end

Crate_Close:
	releaseall
	end

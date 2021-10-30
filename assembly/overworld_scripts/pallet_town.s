.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy

EventScript_PalletTown_TechnologyGuy:
	lock 
	faceplayer
	setflag 0x971
	setvar 0x50A0 0xA
	givepokemon SPECIES_BOUNSWEET 0x8 ITEM_PINK_BOW 0x0 0x0 0x0
	additem ITEM_HONEY 0x3
	additem ITEM_EXP_CHARM 0x1
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	end

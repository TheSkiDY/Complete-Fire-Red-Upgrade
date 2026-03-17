.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy
.global EventScript_PalletTown_RandomizerStop

EventScript_PalletTown_TechnologyGuy:
	lock
	faceplayer
	additem ITEM_RARE_CANDY 1
	additem ITEM_ABILITY_CAPSULE 50
	additem ITEM_ABILITY_PATCH 50
	setvar 0x8004 0xF @erase party
	special 0x62
	givepokemon SPECIES_LANDORUS 10 0 0 0 
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x91F @bike turbo
	release
	end


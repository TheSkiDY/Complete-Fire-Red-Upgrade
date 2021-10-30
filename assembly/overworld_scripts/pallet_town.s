.thumb
.align 2

.include "../xse_commands.s"
.include "../xse_defines.s"
.include "../asm_defines.s"

.global EventScript_PalletTown_TechnologyGuy

EventScript_PalletTown_TechnologyGuy:
	lock 
	loadpointer 0x0 gText_TechnologyGuyName
	setvar 0x8000 0x1
	setvar 0x8001 0xB
	setvar 0x8002 0x8
	setvar 0x8003 0x2
	callasm 0x8727CF9
	faceplayer
	givepokemon SPECIES_FERROTHORN 42 0x0 0x0 0x0 0x0
	givepokemon SPECIES_FRILLISH 15 0x0 0x0 0x0 0x0
	givepokemon SPECIES_TERRAKION 30 0x0 0x0 0x0 0x0
	additem 753 0x1
	additem 754 0x1
	additem 755 0x1
	additem 756 0x1
	additem 757 0x1
	additem 758 0x1
	additem 759 0x1
	additem 760 0x1
	additem 761 0x1
	additem 762 0x1
	additem 763 0x1
	additem 764 0x1
	additem 765 0x1
	additem 766 0x1
	additem 767 0x1
	additem 768 0x1
	additem 769 0x1
	additem 770 0x1
	additem 771 0x1
	additem 772 0x1
	additem 773 0x1
	additem 774 0x1
	additem 775 0x1
	additem 776 0x1
	additem 777 0x1
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	callasm 0x8727DCD
	end

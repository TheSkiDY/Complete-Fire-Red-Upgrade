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
	givepokemon SPECIES_MEWTWO 20 0 0 0 0
	givepokemon SPECIES_WYRDEER 10 0 0 0 0
	givepokemon SPECIES_SQUAWKABILLY_BLUE 10 0 0 0 0
	givepokemon SPECIES_AEGISLASH 10 0 0 0 0
	givepokemon SPECIES_PECHARUNT 10 0 0 0 0
	givepokemon SPECIES_WYRDEER 10 0 0 0 
	givepokemon SPECIES_KLEAVOR 10 0 0 0 
	givepokemon SPECIES_URSALUNA 10 0 0 0 
	givepokemon SPECIES_BASCULEGION 10 0 0 0 
	givepokemon SPECIES_SNEASLER 10 0 0 0 
	givepokemon SPECIES_OVERQWIL 10 0 0 0 
	givepokemon SPECIES_ENAMORUS 10 0 0 0 
	givepokemon SPECIES_SPRIGATITO 10 0 0 0 
	givepokemon SPECIES_FLORAGATO 10 0 0 0 
	givepokemon SPECIES_MEOWSCARADA 10 0 0 0 
	givepokemon SPECIES_FUECOCO 10 0 0 0 
	givepokemon SPECIES_CROCALOR 10 0 0 0 
	givepokemon SPECIES_SKELEDIRGE 10 0 0 0 
	givepokemon SPECIES_QUAXLY 10 0 0 0 
	givepokemon SPECIES_QUAXWELL 10 0 0 0 
	givepokemon SPECIES_QUAQUAVAL 10 0 0 0 
	givepokemon SPECIES_LECHONK 10 0 0 0 
	givepokemon SPECIES_OINKOLOGNE 10 0 0 0 
	givepokemon SPECIES_TAROUNTULA 10 0 0 0 
	givepokemon SPECIES_SPIDOPS 10 0 0 0 
	givepokemon SPECIES_NYMBLE 10 0 0 0 
	givepokemon SPECIES_LOKIX 10 0 0 0 
	givepokemon SPECIES_PAWMI 10 0 0 0 
	givepokemon SPECIES_PAWMO 10 0 0 0 
	givepokemon SPECIES_PAWMOT 10 0 0 0 
	givepokemon SPECIES_TANDEMAUS 10 0 0 0 
	givepokemon SPECIES_MAUSHOLD 10 0 0 0 
	givepokemon SPECIES_FIDOUGH 10 0 0 0 
	givepokemon SPECIES_DACHSBUN 10 0 0 0 
	givepokemon SPECIES_SMOLIV 10 0 0 0 
	givepokemon SPECIES_DOLLIV 10 0 0 0 
	givepokemon SPECIES_ARBOLIVA 10 0 0 0 
	givepokemon SPECIES_SQUAWKABILLY 10 0 0 0 
	givepokemon SPECIES_NACLI 10 0 0 0 
	givepokemon SPECIES_NACLSTACK 10 0 0 0 
	givepokemon SPECIES_GARGANACL 10 0 0 0 
	givepokemon SPECIES_CHARCADET 10 0 0 0 
	givepokemon SPECIES_ARMAROUGE 10 0 0 0 
	givepokemon SPECIES_CERULEDGE 10 0 0 0 
	givepokemon SPECIES_TADBULB 10 0 0 0 
	givepokemon SPECIES_BELLIBOLT 10 0 0 0 
	givepokemon SPECIES_WATTREL 10 0 0 0 
	givepokemon SPECIES_KILOWATTREL 10 0 0 0 
	givepokemon SPECIES_MASCHIFF 10 0 0 0 
	givepokemon SPECIES_MABOSSTIFF 10 0 0 0 
	givepokemon SPECIES_SHROODLE 10 0 0 0 
	givepokemon SPECIES_GRAFAIAI 10 0 0 0 
	givepokemon SPECIES_BRAMBLIN 10 0 0 0 
	givepokemon SPECIES_BRAMBLEGHAST 10 0 0 0 
	givepokemon SPECIES_TOEDSCOOL 10 0 0 0 
	givepokemon SPECIES_TOEDSCRUEL 10 0 0 0 
	givepokemon SPECIES_KLAWF 10 0 0 0 
	givepokemon SPECIES_CAPSAKID 10 0 0 0 
	givepokemon SPECIES_SCOVILLAIN 10 0 0 0 
	givepokemon SPECIES_RELLOR 10 0 0 0 
	givepokemon SPECIES_RABSCA 10 0 0 0 
	givepokemon SPECIES_FLITTLE 10 0 0 0 
	givepokemon SPECIES_ESPATHRA 10 0 0 0 
	givepokemon SPECIES_TINKATINK 10 0 0 0 
	givepokemon SPECIES_TINKATUFF 10 0 0 0 
	givepokemon SPECIES_TINKATON 10 0 0 0 
	givepokemon SPECIES_WIGLETT 10 0 0 0 
	givepokemon SPECIES_WUGTRIO 10 0 0 0 
	givepokemon SPECIES_BOMBIRDIER 10 0 0 0 
	givepokemon SPECIES_FINIZEN 10 0 0 0 
	givepokemon SPECIES_PALAFIN 10 0 0 0 
	givepokemon SPECIES_VAROOM 10 0 0 0 
	givepokemon SPECIES_REVAVROOM 10 0 0 0 
	givepokemon SPECIES_CYCLIZAR 10 0 0 0 
	givepokemon SPECIES_ORTHWORM 10 0 0 0 
	givepokemon SPECIES_GLIMMET 10 0 0 0 
	givepokemon SPECIES_GLIMMORA 10 0 0 0 
	givepokemon SPECIES_GREAVARD 10 0 0 0 
	givepokemon SPECIES_HOUNDSTONE 10 0 0 0 
	givepokemon SPECIES_FLAMIGO 10 0 0 0 
	givepokemon SPECIES_CETODDLE 10 0 0 0 
	givepokemon SPECIES_CETITAN 10 0 0 0 
	givepokemon SPECIES_VELUZA 10 0 0 0 
	givepokemon SPECIES_DONDOZO 10 0 0 0 
	givepokemon SPECIES_TATSUGIRI 10 0 0 0 
	givepokemon SPECIES_ANNIHILAPE 10 0 0 0 
	givepokemon SPECIES_CLODSIRE 10 0 0 0 
	givepokemon SPECIES_FARIGIRAF 10 0 0 0 
	givepokemon SPECIES_DUDUNSPARCE 10 0 0 0 
	givepokemon SPECIES_KINGAMBIT 10 0 0 0 
	givepokemon SPECIES_GREAT_TUSK 10 0 0 0 
	givepokemon SPECIES_SCREAM_TAIL 10 0 0 0 
	givepokemon SPECIES_BRUTE_BONNET 10 0 0 0 
	givepokemon SPECIES_FLUTTER_MANE 10 0 0 0 
	givepokemon SPECIES_SLITHER_WING 10 0 0 0 
	givepokemon SPECIES_SANDY_SHOCKS 10 0 0 0 
	givepokemon SPECIES_IRON_TREADS 10 0 0 0 
	givepokemon SPECIES_IRON_BUNDLE 10 0 0 0 
	givepokemon SPECIES_IRON_HANDS 10 0 0 0 
	givepokemon SPECIES_IRON_JUGULIS 10 0 0 0 
	givepokemon SPECIES_IRON_MOTH 10 0 0 0 
	givepokemon SPECIES_IRON_THORNS 10 0 0 0 
	givepokemon SPECIES_FRIGIBAX 10 0 0 0 
	givepokemon SPECIES_ARCTIBAX 10 0 0 0 
	givepokemon SPECIES_BAXCALIBUR 10 0 0 0 
	givepokemon SPECIES_GIMMIGHOUL 10 0 0 0 
	givepokemon SPECIES_GHOLDENGO 10 0 0 0 
	givepokemon SPECIES_WO_CHIEN 10 0 0 0 
	givepokemon SPECIES_CHIEN_PAO 10 0 0 0 
	givepokemon SPECIES_TING_LU 10 0 0 0 
	givepokemon SPECIES_CHI_YU 10 0 0 0 
	givepokemon SPECIES_ROARING_MOON 10 0 0 0 
	givepokemon SPECIES_IRON_VALIANT 10 0 0 0 
	givepokemon SPECIES_KORAIDON 10 0 0 0 
	givepokemon SPECIES_MIRAIDON 10 0 0 0 
	givepokemon SPECIES_WALKING_WAKE 10 0 0 0 
	givepokemon SPECIES_IRON_LEAVES 10 0 0 0 
	givepokemon SPECIES_DIPPLIN 10 0 0 0 
	givepokemon SPECIES_POLTCHAGEIST 10 0 0 0 
	givepokemon SPECIES_SINISTCHA 10 0 0 0 
	givepokemon SPECIES_OKIDOGI 10 0 0 0 
	givepokemon SPECIES_MUNKIDORI 10 0 0 0 
	givepokemon SPECIES_FEZANDIPITI 10 0 0 0 
	givepokemon SPECIES_OGERPON 10 0 0 0 
	givepokemon SPECIES_ARCHALUDON 10 0 0 0 
	givepokemon SPECIES_HYDRAPPLE 10 0 0 0 
	givepokemon SPECIES_GOUGING_FIRE 10 0 0 0 
	givepokemon SPECIES_RAGING_BOLT 10 0 0 0 
	givepokemon SPECIES_IRON_BOULDER 10 0 0 0 
	givepokemon SPECIES_IRON_CROWN 10 0 0 0 
	givepokemon SPECIES_TERAPAGOS 10 0 0 0 
	givepokemon SPECIES_PECHARUNT 10 0 0 0 
	msgbox gText_PalletTown_TechnologyGuy MSG_NORMAL
	setflag 0x91E @dexnav
	setflag 0x82F @running shoes
	setflag 0x91F @bike turbo
	release
	end


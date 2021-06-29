.thumb
.text
.align 2
/*
ability_description_table.s
	table of ability description pointers
*/

.global gAbilityDescriptions
gAbilityDescriptions:
.word 0x824f3c4		@ABILITY_NONE
.word 0x824f3d8		@ABILITY_STENCH
.word 0x824f3f2		@ABILITY_DRIZZLE
.word 0x824f40a		@ABILITY_SPEEDBOOST
.word 0x824f422		@ABILITY_BATTLEARMOR
.word 0x824f438		@ABILITY_STURDY
.word DESC_DAMP		@ABILITY_DAMP
.word DESC_LIMBER	@ABILITY_LIMBER
.word 0x824f481		@ABILITY_SANDVEIL
.word 0x824f49d		@ABILITY_STATIC
.word 0x824f4b3		@ABILITY_VOLTABSORB
.word 0x824f4ce		@ABILITY_WATERABSORB
.word 0x824f4e5		@ABILITY_OBLIVIOUS
.word 0x824f4fa		@ABILITY_CLOUDNINE
.word DESC_COMPOUNDEYES		@ABILITY_COMPOUNDEYES
.word 0x824f524		@ABILITY_INSOMNIA
.word 0x824f534		@ABILITY_COLORCHANGE
.word 0x824f550		@ABILITY_IMMUNITY
.word 0x824f564		@ABILITY_FLASHFIRE
.word 0x824f57e		@ABILITY_SHIELDDUST
.word 0x824f596		@ABILITY_OWNTEMPO
.word 0x824f5aa		@ABILITY_SUCTIONCUPS
.word 0x824f5c3		@ABILITY_INTIMIDATE
.word 0x824f5dc		@ABILITY_SHADOWTAG
.word 0x824f5f7		@ABILITY_ROUGHSKIN
.word 0x824f607		@ABILITY_WONDERGUARD
.word 0x824f61f		@ABILITY_LEVITATE
.word 0x824f63a		@ABILITY_EFFECTSPORE
.word 0x824f654		@ABILITY_SYNCHRONIZE
.word 0x824f66f		@ABILITY_CLEARBODY
.word 0x824f68b		@ABILITY_NATURALCURE
.word 0x824f6a5		@ABILITY_LIGHTNINGROD
.word 0x824f6bd		@ABILITY_SERENEGRACE
.word 0x824f6d5		@ABILITY_SWIFTSWIM
.word 0x824f6eb		@ABILITY_CHLOROPHYLL
.word DESC_ILLUMINATE		@ABILITY_ILLUMINATE
.word 0x824f71f		@ABILITY_TRACE
.word 0x824f737		@ABILITY_HUGEPOWER
.word 0x824f746		@ABILITY_POISONPOINT
.word 0x824f75e		@ABILITY_INNERFOCUS
.word DESC_MAGMAARMOR		@ABILITY_MAGMAARMOR
.word DESC_WATERVEIL		@ABILITY_WATERVEIL
.word 0x824f795		@ABILITY_MAGNETPULL
.word 0x824f7af		@ABILITY_SOUNDPROOF
.word 0x824f7c9		@ABILITY_RAINDISH
.word 0x824f7e5		@ABILITY_SANDSTREAM
.word 0x824f7fa		@ABILITY_PRESSURE
.word 0x824f811		@ABILITY_THICKFAT
.word 0x824f82b		@ABILITY_EARLYBIRD
.word 0x824f847		@ABILITY_FLAMEBODY
.word 0x824f861		@ABILITY_RUNAWAY
.word 0x824f878		@ABILITY_KEENEYE
.word DESC_HYPERCUTTER		@ABILITY_HYPERCUTTER
.word 0x824f8ae		@ABILITY_PICKUP
.word DESC_TRUANT	@ABILITY_TRUANT
.word 0x824f8dd		@ABILITY_HUSTLE
.word 0x824f8f8		@ABILITY_CUTECHARM
.word DESC_EMPTY_8
.word DESC_EMPTY_9
.word 0x824f93a		@ABILITY_FORECAST
.word 0x824f954		@ABILITY_STICKYHOLD
.word 0x824f969		@ABILITY_SHEDSKIN
.word 0x824f985		@ABILITY_GUTS
.word 0x824f99e		@ABILITY_MARVELSCALE
.word 0x824f9b8		@ABILITY_LIQUIDOOZE
.word 0x824f9d0		@ABILITY_OVERGROW
.word 0x824f9ec		@ABILITY_BLAZE
.word 0x824fa07		@ABILITY_TORRENT
.word 0x824fa23		@ABILITY_SWARM
.word 0x824fa3d		@ABILITY_ROCKHEAD
.word 0x824fa55		@ABILITY_DROUGHT
.word 0x824fa71		@ABILITY_ARENATRAP
.word 0x824fa83		@ABILITY_VITALSPIRIT
.word 0x824fa93		@ABILITY_WHITESMOKE
.word DESC_NEUTRALISINGGAS		@Old: ABILITY_PUREPOWER
.word DESC_EMPTY_1
.word DESC_HUNGERSWITCH		@Old: ABILITY_CACOPHONY
.word DESC_EMPTY_2

.word DESC_SWEETVEIL
.word DESC_SKILLLINK
.word DESC_MOTORDRIVE
.word DESC_MULTISCALE
.word DESC_TECHNICIAN
.word DESC_SCRAPPY
.word DESC_SUPERLUCK
.word DESC_SNIPER
.word DESC_REGENERATOR
.word DESC_PRANKSTER
.word DESC_ADAPTABILITY
.word DESC_BIGPECKS
.word DESC_MAGICBOUNCE
.word DESC_RECKLESS
.word DESC_SHEERFORCE
.word DESC_IRONFIST
.word DESC_RIVALRY
.word DESC_SANDFORCE
.word DESC_SOLARPOWER
.word DESC_HEATPROOF
.word DESC_DRYSKIN
.word DESC_TINTEDLENS
.word DESC_EMPTY_3
.word DESC_FILTER
.word DESC_INFILTRATOR
.word DESC_DOWNLOAD
.word DESC_POISONHEAL
.word DESC_ICEBODY
.word DESC_MOODY
.word DESC_HYDRATION
.word DESC_HEALER
.word DESC_SNOWCLOAK
.word DESC_TANGLEDFEET
.word DESC_SNOWWARNING
.word DESC_QUICKFEET
.word DESC_SAPSIPPER
.word DESC_OVERCOAT
.word DESC_MAGICGUARD
.word DESC_BULLETPROOF
.word DESC_GALEWINGS
.word DESC_MOXIE
.word DESC_AFTERMATH
.word DESC_CURSEDBODY
.word DESC_STUN_TOUCH
.word DESC_MUMMY
.word DESC_EMPTY_5
.word DESC_SANDRUSH
.word DESC_ANALYTIC
.word DESC_NOGUARD
.word DESC_MEGALAUNCHER
.word DESC_TOUGHCLAWS
.word DESC_STRONGJAW
.word DESC_VICTORYSTAR
.word DESC_STORMDRAIN
.word DESC_DARKAURA
.word DESC_FAIRYAURA
.word DESC_AURABREAK
.word DESC_REFRIGERATE
.word DESC_PIXILATE
.word DESC_AERILATE
.word DESC_NORMALIZE
.word DESC_UNBURDEN
.word DESC_SIMPLE
.word DESC_UNAWARE
.word DESC_DEFIANT
.word DESC_COMPETITIVE
.word DESC_DEFEATIST
.word DESC_SLOWSTART
.word DESC_EMPTY_7
.word DESC_VALOUR
.word DESC_FURCOAT
.word DESC_WONDERSKIN
.word DESC_PROTEAN
.word DESC_PARENTALBOND
.word DESC_MOLDBREAKER
.word DESC_EMPTY_6
.word DESC_UNSEENFIST
.word DESC_ZENMODE
.word DESC_BATTLEBOND
.word DESC_BEASTBOOST
.word DESC_CORROSION
.word DESC_DISGUISE
.word DESC_EMERGENCYEXIT
.word DESC_FLUFFY
.word DESC_STEELYSPIRIT
.word DESC_PERISHBODY
.word DESC_WANDERINGSPIRIT
.word DESC_POWERCONSTRUCT
.word DESC_EMPTY_4
.word DESC_RKS_SYSTEM
.word DESC_SCHOOLING
.word DESC_SHADOWSHIELD
.word DESC_SHIELDSDOWN
.word DESC_SLUSHRUSH
.word DESC_SOULHEART
.word DESC_STAMINA
.word DESC_STEELWORKER
.word DESC_GRIMNEIGH
.word DESC_TRIAGE
.word DESC_WATERBUBBLE
.word DESC_WATERCOMPACTION
.word DESC_STALL
.word DESC_MULTITYPE
.word DESC_ELECTRICSURGE
.word DESC_GRASSYSURGE
.word DESC_MISTYSURGE
.word DESC_PSYCHICSURGE
.word DESC_SURGESURFER
.word DESC_GRASSPELT
.word DESC_ANGERPOINT
.word DESC_ANTICIPATION
.word DESC_FOREWARN
.word DESC_FRISK
.word DESC_CONTRARY
.word DESC_UNNERVE
.word DESC_WEAKARMOR
.word DESC_HEAVYMETAL
.word DESC_LIGHTMETAL
.word DESC_STEADFAST
.word DESC_IMPOSTER
.word DESC_JUSTIFIED
.word DESC_RATTLED
.word DESC_MERCILESS
.word DESC_AROMAVEIL
.word DESC_FLOWERVEIL
.word DESC_LEAFGUARD
.word DESC_KLUTZ
.word DESC_FLOWERGIFT
.word DESC_BADDREAMS
.word DESC_PICKPOCKET
.word DESC_EMPTY_10
.word DESC_POISONTOUCH
.word DESC_MAGICIAN
.word DESC_STANCECHANGE
.word DESC_PRIMORDIALSEA
.word DESC_DESOLATELAND
.word DESC_DELTASTREAM
.word DESC_GORILLATACTICS
.word DESC_BERSERK
.word DESC_LONGREACH
.word DESC_LIQUIDVOICE
.word DESC_DRAGONSMAW
.word DESC_INNARDSOUT
.word DESC_MAJESTIC
.word DESC_GLUTTONY
.word DESC_HONEYGATHER
.word DESC_FRIENDGUARD
.word DESC_HARVEST
.word DESC_TELEPATHY
.word DESC_ILLUSION
.word DESC_CHEEKPOUCH
.word DESC_SYMBIOSIS
.word DESC_STAKEOUT
.word DESC_COMATOSE
.word DESC_DANCER
.word DESC_BATTERY
.word DESC_RECEIVER
.word DESC_TRANSISTOR
.word DESC_NEUROFORCE
.word DESC_GALVANIZE
.word DESC_INTREPIDSWORD
.word DESC_DAUNTLESSSHIELD
.word DESC_BALLFETCH
.word DESC_COTTONDOWN
.word DESC_MIRRORARMOR
.word DESC_GULPMISSILE
.word DESC_STALWART
.word DESC_STEAMENGINE
.word DESC_PUNKROCK
.word DESC_SANDSPIT
.word DESC_ICESCALES
.word DESC_RIPEN
.word DESC_ICEFACE
.word DESC_POWERSPOT
.word DESC_MIMICRY
.word DESC_SCREENCLEANER
.word DESC_PASTEL_VEIL

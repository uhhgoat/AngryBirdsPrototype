#ifndef IMAGE_NAME
#define IMAGE_NAME


#include "EnumBase.h"

struct ImageName : public EnumBase
{
	ImageName(ImageName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x30000,

		Background,
		RedBird,
		BlueBird,
		YellowBird,
		GreenBird,
		BlackBird,
		WhiteBird,
		BigRedBird,

		RedBirdDamaged,
		BlueBirdDamaged,
		YellowBirdDamaged,
		GreenBirdDamaged,
		WhiteBirdDamaged,
		BlackBirdDamaged,
		BigRedBirdDamaged,

		RedBirdFlying,
		BlueBirdFlying,
		YellowBirdFlying,
		GreenBirdFlying,
		WhiteBirdFlying,
		BlackBirdFlying,
		BigRedBirdFlying,

		RedBirdBlink,
		BlueBirdBlink,
		YellowBirdBlink,
		GreenBirdBlink,
		WhiteBirdBlink,
		BlackBirdBlink,
		BigRedBirdBlink,

		WhiteBirdShrivelled,
		YellowBirdSuper,

		Blast1,
		Blast2,
		Blast3,
		Blast4,
		Blast5,
		Blast6,

		Platform,

		WoodBlockShort,
		WoodBlockMed,
		WoodBlockLong,
		WoodBlockShort2,
		WoodBlockMed2,
		WoodBlockLong2,
		WoodBlockShort3,
		WoodBlockMed3,
		WoodBlockLong3,
		WoodBlockShort4,
		WoodBlockMed4,
		WoodBlockLong4,
		WoodBlockTiny,
		WoodBlockTiny2,
		WoodBlockTiny3,
		WoodBlockTiny4,
		WoodBlockMedThick,
		WoodBlockMedThick2,
		WoodBlockMedThick3,
		WoodBlockMedThick4,
		WoodBlockSquare,
		WoodBlockSquare2,
		WoodBlockSquare3,
		WoodBlockSquare4,

		GlassBlockShort,
		GlassBlockMed,
		GlassBlockLong,
		GlassBlockShort2,
		GlassBlockMed2,
		GlassBlockLong2,
		GlassBlockShort3,
		GlassBlockMed3,
		GlassBlockLong3,
		GlassBlockShort4,
		GlassBlockMed4,
		GlassBlockLong4,
		GlassBlockMedThick,
		GlassBlockMedThick2,
		GlassBlockMedThick3,
		GlassBlockMedThick4,
		GlassBlockTinySquare,
		GlassBlockTinySquare2,
		GlassBlockTinySquare3,
		GlassBlockTinySquare4,

		StoneBlockShort,
		StoneBlockMed,
		StoneBlockLong,
		StoneBlockShort2,
		StoneBlockMed2,
		StoneBlockLong2,
		StoneBlockShort3,
		StoneBlockMed3,
		StoneBlockLong3,
		StoneBlockShort4,
		StoneBlockMed4,
		StoneBlockLong4,
		StoneBlockMedThick,
		StoneBlockMedThick2,
		StoneBlockMedThick3,
		StoneBlockMedThick4,
		StoneCircle,
		StoneCircle2,
		StoneCircle3,
		StoneCircle4,

		KingPig,
		QueenPig,
		RegularPig,
		RegularPig2,
		RegularPig3,
		HelmetPig,
		HelmetPig2,
		HelmetPig3,

		Bang,
		SlingShotRight,
		SlingShotLeft,
		Sling,
		Egg,
		Trail,

		Not_Initialized,
	};
};

#endif
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

		Alien_Blue,
		Alien_Green,
		Alien_Red,
		Stitch,
		RedBird,
		BlueBird,
		YellowBird,
		GreenBird,
		BlackBird,
		WhiteBird,
		BigRedBird,
		WoodBlockShort,
		WoodBlockMed,
		WoodBlockLong,
		GlassBlockShort,
		GlassBlockMed,
		GlassBlockLong,
		KingPig,
		QueenPig,

		Not_Initialized,
	};
};

#endif
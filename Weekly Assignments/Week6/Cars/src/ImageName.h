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
		CarCasualBody,
		CarOffroadBody,
		Wheel,
		Bang,

		Thruster,

		Not_Initialized,
	};
};

#endif
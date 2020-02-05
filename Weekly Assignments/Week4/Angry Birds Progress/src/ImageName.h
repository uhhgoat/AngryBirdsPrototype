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
		GlassBlockShort,
		GlassBlockMed,
		GlassBlockLong,
		KingPig,
		QueenPig,
		Bang,
		SlingShotRight,
		SlingShotLeft,
		Sling,

		Not_Initialized,
	};
};

#endif
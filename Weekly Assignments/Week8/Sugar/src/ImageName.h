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

		Long_Wood_Block,
		Long_Wood_Block3,
		Glass_Block,
		RedBird,
		RedBird2,
		Bang,
		Pig,
		YellowBird,
		Short_Stone_Block,
		GearLarge,
		GearSmall,
		TrailPuff,
		FeatherYellow,

		Not_Initialized,
	};
};

#endif
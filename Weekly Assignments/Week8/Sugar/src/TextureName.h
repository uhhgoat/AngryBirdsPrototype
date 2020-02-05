#ifndef TEXTURE_NAME
#define TEXTURE_NAME

#include "EnumBase.h"

struct TextName : public EnumBase
{
	TextName(TextName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x40000,

		AngryBirds,
		Wood_Blocks,
		Glass_Blocks,
		Stone_Blocks,
		Gears,

		Not_initialized
	};
};
#endif

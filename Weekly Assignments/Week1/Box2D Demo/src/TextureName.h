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

		Characters,
		WoodBlocks,
		GlassBlocks,
		StoneBlocks,

		Not_initialized
	};
};
#endif

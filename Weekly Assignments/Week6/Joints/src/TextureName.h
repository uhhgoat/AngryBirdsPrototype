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

		Background,
		Characters,
		WoodBlocks,
		GlassBlocks,
		StoneBlocks,
		Sling,

		Not_initialized
	};
};
#endif

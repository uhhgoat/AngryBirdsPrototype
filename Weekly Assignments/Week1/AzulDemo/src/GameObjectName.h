#ifndef GAME_OBJECT_NAME
#define GAME_OBJECT_NAME

#include "EnumBase.h"

struct GameObjectName : public EnumBase
{
	GameObjectName(GameObjectName::Name n)
	{
		this->value = n;
	}

	enum Name
	{
		Root = 0x70000,
		
		MainGroup,

		Stitch,
		Alien,
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

		NOT_INITIALIZED
	};
};

#endif
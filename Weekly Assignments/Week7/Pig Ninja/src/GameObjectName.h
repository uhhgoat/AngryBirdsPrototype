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
		EffectsGroup,
		BirdGroup,

		RedBird,
		Block,
		Bang,
		Pig,
		GearLarge,
		GearSmall,

		NOT_INITIALIZED
	};
};

#endif
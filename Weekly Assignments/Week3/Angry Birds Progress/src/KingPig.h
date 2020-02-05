#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class KingPig : public GameObject2D
{
private:

public:
	
	KingPig(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~KingPig() = default;

	
};

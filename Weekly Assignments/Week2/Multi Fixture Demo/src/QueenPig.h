#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class QueenPig : public GameObject2D
{
private:

public:
	
	QueenPig(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~QueenPig() = default;

	
};

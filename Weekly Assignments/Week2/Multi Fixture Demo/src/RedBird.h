#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class RedBird : public GameObject2D
{
private:

public:
	
	RedBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~RedBird() = default;

	
};
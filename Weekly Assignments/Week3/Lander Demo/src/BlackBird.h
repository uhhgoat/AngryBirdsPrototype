#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class BlackBird : public GameObject2D
{
private:

public:
	
	BlackBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~BlackBird() = default;

	
};
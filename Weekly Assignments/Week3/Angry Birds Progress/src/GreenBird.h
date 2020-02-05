#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class GreenBird : public GameObject2D
{
private:

public:
	
	GreenBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~GreenBird() = default;

	
};
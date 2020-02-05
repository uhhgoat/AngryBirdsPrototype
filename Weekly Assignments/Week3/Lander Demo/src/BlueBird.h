#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class BlueBird : public GameObject2D
{
private:

public:
	
	BlueBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~BlueBird() = default;

	
};
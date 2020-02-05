#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WhiteBird : public GameObject2D
{
private:

public:
	
	WhiteBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~WhiteBird() = default;

	
};
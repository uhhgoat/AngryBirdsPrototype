#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class BigRedBird : public GameObject2D
{
private:

public:
	
	BigRedBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~BigRedBird() = default;

	
};
#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class YellowBird : public GameObject2D
{
private:

public:

	YellowBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~YellowBird() = default;


};
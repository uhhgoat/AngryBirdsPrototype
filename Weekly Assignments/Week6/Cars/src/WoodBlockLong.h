#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WoodBlockLong : public GameObject2D
{
private:

public:
	WoodBlockLong(float x, float y, float rot, b2World &world);
	~WoodBlockLong() = default;

};
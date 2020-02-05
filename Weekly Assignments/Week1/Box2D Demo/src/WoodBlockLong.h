#pragma once
#include "GameObject2D.h"
class WoodBlockLong : public GameObject2D
{
private:

public:
	WoodBlockLong(float x, float y, float rot, b2World &world);
	~WoodBlockLong() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
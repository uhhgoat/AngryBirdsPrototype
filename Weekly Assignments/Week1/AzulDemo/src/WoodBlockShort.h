#pragma once
#include "GameObject2D.h"
class WoodBlockShort : public GameObject2D
{
private:

public:
	WoodBlockShort(float x, float y, float rot);
	~WoodBlockShort() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
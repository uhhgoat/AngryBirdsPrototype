#pragma once
#include "GameObject2D.h"
class WoodBlockMed : public GameObject2D
{
private:

public:
	WoodBlockMed(float x, float y, float rot, b2World &world);
	~WoodBlockMed() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
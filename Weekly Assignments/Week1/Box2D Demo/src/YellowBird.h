#pragma once
#include "GameObject2D.h"
class YellowBird : public GameObject2D
{
private:

public:
	YellowBird(float x, float y, float rot, b2World &world);
	YellowBird(float x, float y, float rot, bool showDebugShape, b2World &world);
	~YellowBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
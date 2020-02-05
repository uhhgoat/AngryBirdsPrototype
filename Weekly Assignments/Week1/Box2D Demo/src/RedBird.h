#pragma once
#include "GameObject2D.h"
class RedBird : public GameObject2D
{
private:

public:
	RedBird(float x, float y, float rot, b2World &world);
	RedBird(float x, float y, float rot, bool showDebugShape, b2World &world);
	~RedBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
#pragma once
#include "GameObject2D.h"
class BigRedBird : public GameObject2D
{
private:

public:
	BigRedBird(float x, float y, float rot, b2World &world);
	BigRedBird(float x, float y, float rot, bool showDebugShape, b2World &world);
	~BigRedBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
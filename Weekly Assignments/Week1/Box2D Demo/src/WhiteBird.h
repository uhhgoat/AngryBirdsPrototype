#pragma once
#include "GameObject2D.h"
class WhiteBird : public GameObject2D
{
private:

public:
	WhiteBird(float x, float y, float rot, b2World &world);
	WhiteBird(float x, float y, float rot, bool showDebugShape, b2World &world);
	~WhiteBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
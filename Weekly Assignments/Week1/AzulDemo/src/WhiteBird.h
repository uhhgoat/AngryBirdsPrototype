#pragma once
#include "GameObject2D.h"
class WhiteBird : public GameObject2D
{
private:

public:
	WhiteBird(float x, float y, float rot);
	WhiteBird(float x, float y, float rot, bool showDebugShape);
	~WhiteBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
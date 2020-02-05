#pragma once
#include "GameObject2D.h"
class YellowBird : public GameObject2D
{
private:

public:
	YellowBird(float x, float y, float rot);
	YellowBird(float x, float y, float rot, bool showDebugShape);
	~YellowBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
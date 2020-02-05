#pragma once
#include "GameObject2D.h"
class GreenBird : public GameObject2D
{
private:

public:
	GreenBird(float x, float y, float rot);
	GreenBird(float x, float y, float rot, bool showDebugShape);
	~GreenBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
#pragma once
#include "GameObject2D.h"
class BlueBird : public GameObject2D
{
private:

public:
	BlueBird(float x, float y, float rot, b2World &world);
	BlueBird(float x, float y, float rot, bool showDebugShape, b2World &world);
	~BlueBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
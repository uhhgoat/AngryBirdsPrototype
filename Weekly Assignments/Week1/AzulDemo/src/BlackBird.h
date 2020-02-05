#pragma once
#include "GameObject2D.h"
class BlackBird : public GameObject2D
{
private:

public:
	BlackBird(float x, float y, float rot);
	BlackBird(float x, float y, float rot, bool showDebugShape);
	~BlackBird() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
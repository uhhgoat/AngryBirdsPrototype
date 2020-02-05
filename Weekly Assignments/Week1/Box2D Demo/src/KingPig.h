#pragma once
#include "GameObject2D.h"
class KingPig : public GameObject2D
{
private:

public:
	KingPig(float x, float y, float rot, b2World &world);
	KingPig(float x, float y, float rot, bool showDebugShape, b2World &world);
	~KingPig() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};

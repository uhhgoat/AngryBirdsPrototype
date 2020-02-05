#pragma once
#include "GameObject2D.h"
class KingPig : public GameObject2D
{
private:

public:
	KingPig(float x, float y, float rot);
	KingPig(float x, float y, float rot, bool showDebugShape);
	~KingPig() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};

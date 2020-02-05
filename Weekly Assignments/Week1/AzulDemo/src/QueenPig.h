#pragma once
#include "GameObject2D.h"
class QueenPig : public GameObject2D
{
private:

public:
	QueenPig(float x, float y, float rot);
	QueenPig(float x, float y, float rot, bool showDebugShape);
	~QueenPig() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};

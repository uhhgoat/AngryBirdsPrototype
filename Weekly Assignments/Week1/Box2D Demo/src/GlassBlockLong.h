#pragma once
#include "GameObject2D.h"
class GlassBlockLong : public GameObject2D
{
private:

public:
	GlassBlockLong(float x, float y, float rot, b2World &world);
	~GlassBlockLong() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
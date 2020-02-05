#pragma once
#include "GameObject2D.h"
class GlassBlockMed : public GameObject2D
{
private:

public:
	GlassBlockMed(float x, float y, float rot);
	~GlassBlockMed() = default;

	//void AddScale(float s);
	//float GetScale();
	//void Rotate(float a);
};
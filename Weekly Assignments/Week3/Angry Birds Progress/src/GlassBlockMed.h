#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class GlassBlockMed : public GameObject2D
{
private:

public:
	GlassBlockMed(float x, float y, float rot, b2World &world);
	~GlassBlockMed() = default;

};
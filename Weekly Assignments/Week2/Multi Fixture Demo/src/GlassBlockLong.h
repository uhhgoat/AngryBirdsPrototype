#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class GlassBlockLong : public GameObject2D
{
private:

public:
	GlassBlockLong(float x, float y, float rot, b2World &world);
	~GlassBlockLong() = default;

};
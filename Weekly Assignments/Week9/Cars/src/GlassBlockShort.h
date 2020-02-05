#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class GlassBlockShort : public GameObject2D
{
private:

public:
	GlassBlockShort(float x, float y, float rot, b2World &world);
	~GlassBlockShort() = default;

};
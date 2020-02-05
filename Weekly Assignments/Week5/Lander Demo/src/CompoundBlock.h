#pragma once
#include "MultiFixtureObject.h"
#include "Includes.h"
#include "FilterCategory.h"
class CompoundBlock : public MultiFixtureObject
{
public:
	CompoundBlock(float x, float y, float rot, b2World &world, bool showDebugShape = false);
};
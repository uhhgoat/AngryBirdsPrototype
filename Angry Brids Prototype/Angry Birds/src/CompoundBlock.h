#pragma once
#include "MultiFixtureObject.h"
#include "Includes.h"
#include "FilterCategory.h"
class CompoundBlock : public MultiFixtureObject
{
public:
	CompoundBlock(float x, float y, float rot, bool showDebugShape = false);
	CompoundBlock() = default;
	~CompoundBlock() = default;
	CompoundBlock(const CompoundBlock&) = delete;
	CompoundBlock& operator=(const CompoundBlock&) = delete;
};
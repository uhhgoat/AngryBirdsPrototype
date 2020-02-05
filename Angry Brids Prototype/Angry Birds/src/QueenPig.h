#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class QueenPig : public GameObject2D
{
private:

public:
	
	QueenPig(float x, float y, float rot, bool showDebugShape = false);
	QueenPig() = default;
	~QueenPig() = default;
	QueenPig(const QueenPig&) = delete;
	QueenPig& operator=(const QueenPig&) = delete;

	
};

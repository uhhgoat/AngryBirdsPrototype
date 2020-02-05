#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class KingPig : public GameObject2D
{
private:

public:
	
	KingPig(float x, float y, float rot, bool showDebugShape = false);
	KingPig() = default;
	~KingPig() = default;
	KingPig(const KingPig&) = delete;
	KingPig& operator=(const KingPig&) = delete;

	
};

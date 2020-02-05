#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WoodBlockLong : public GameObject2D
{
private:
	int hitPoints;
public:
	WoodBlockLong(float x, float y, float rot, b2World &world);
	~WoodBlockLong() = default;
	virtual void TakeImpact(float damage) override;

};
#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WoodBlockShort : public GameObject2D
{
private:
	int hitPoints;
public:
	WoodBlockShort(float x, float y, float rot, b2World &world);
	~WoodBlockShort() = default;
	virtual void TakeImpact(float damage) override;

};
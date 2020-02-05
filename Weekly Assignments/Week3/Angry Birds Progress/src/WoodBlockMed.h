#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WoodBlockMed : public GameObject2D
{
private:
	int hitPoints;
public:
	WoodBlockMed(float x, float y, float rot, b2World &world);
	~WoodBlockMed() = default;
	virtual void TakeImpact(float damage) override;

};
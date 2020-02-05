#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class EtherealBlock : public GameObject2D
{
private:
	int hitPoints;
public:
	EtherealBlock(float x, float y, float rot, b2World &world);
	~EtherealBlock() = default;
	
};
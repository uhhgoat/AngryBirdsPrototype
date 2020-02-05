#pragma once
#include "Includes.h"
class TerrainSegment : public GameObject2D
{
private:
public:
	float xOff;
	float yOff;
	TerrainSegment(b2Body* body, b2Vec2 left, b2Vec2 right);
};
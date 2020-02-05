#pragma once
#include "MultiFixtureObject.h"
#include "Includes.h"
#include "FilterCategory.h"
#include <vector>
#include "TerrainSegment.h"
class Terrain : public MultiFixtureObject
{
private:
	GameObject2D * platform;
	std::vector<b2Vec2> points;
	std::vector<TerrainSegment*> segmentList;
	int maxRange = 200;
	float yClampUp = 600;
	float yClampDown = 0;
public:
	Terrain(int segments, float left, float right, b2World &world, bool showDebugShape = false);
	~Terrain();
	void AddSegments(int segments, int startIdx, b2Vec2 left, b2Vec2 right);
	GameObject2D* GetPlatform();
};
#include "Terrain.h"
Terrain::Terrain(int segments, float left, float right, b2World &world, bool showDebugShape)
{
	points.resize(segments + 1);
	//segmentList.resize(segments);

	points[0] = b2Vec2(left, 200);
	points[segments] = b2Vec2(right, 200);
	AddSegments(segments, 0, points[0], points[segments]);





	// Create one and only one body
	b2BodyDef TerrainDef;
	TerrainDef.type = b2_staticBody;
	TerrainDef.position.Set(PixelToMeter(0), PixelToMeter(200));
	

	b2Body *pTerrainBody = world.CreateBody(&TerrainDef);


	for (int i = 0; i < segments; i++)
	{
		segmentList.push_back(new TerrainSegment(pTerrainBody, points[i], points[i + 1]));
		GameObjectMan::Add(segmentList.back(), GameObjectName::MainGroup);
	}

	int idx = (int)((3.0f / 4.0f)*(segments));
	b2Vec2 platPos = b2Vec2(segmentList[idx]->xOff, segmentList[idx]->yOff + 250);
	platform = new WoodBlockShort(platPos.x, platPos.y, 0, world);
	GameObjectMan::Add(platform, GameObjectName::MainGroup);


	showDebugShape;
}

Terrain::~Terrain()
{

}

GameObject2D* Terrain::GetPlatform()
{
	return platform;
}

void Terrain::AddSegments(int segments, int startIdx, b2Vec2 left, b2Vec2 right)
{
	if (segments <= 1)
	{
		return;
	}
	b2Vec2 mid;
	//find midpoint of two segments
	mid = 0.5f* (right + left);
	//randomize y value
	mid.y += rand() % maxRange - (maxRange / 2);

	if (mid.y > yClampUp)
		mid.y = yClampUp;
	if (mid.y < yClampDown)
		mid.y = yClampDown;

	int midIdx = startIdx + segments / 2;
	points[midIdx] = mid;
	AddSegments(segments / 2, startIdx, left, mid);
	AddSegments(segments / 2, midIdx, mid, right);
}
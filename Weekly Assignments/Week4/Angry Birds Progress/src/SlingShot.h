#pragma once
#include "Includes.h"
class SlingShot : public MultiFixtureObject
{
private:
	GameObject2D * slingRight;
	GameObject2D* slingLeft;
public:
	SlingShot(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~SlingShot() = default;

	void Update();
	void UpdateRubber(GameObject2D* go);
};
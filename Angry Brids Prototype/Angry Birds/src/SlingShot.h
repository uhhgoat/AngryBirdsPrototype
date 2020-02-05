#pragma once
#include "Includes.h"
#include "AutoCam.h"
#include <vector>
#include "TestLevel.h"
#include "Level_1_1.h"
#include "Level_1_9.h"
#include "Level_FerrisWheel.h"
class SlingShot : public MultiFixtureObject
{
private:
	enum ShotState
	{
		Idle = 0,
		Drawn = 1
	};
	bool mLast = false;
	bool mPressed = false;

	AutoCam* autoCam;

	GameObject2D* slingRight;
	GameObject2D* slingLeft;

	GameObject2D* birdInSlingShot;
	GameObject2D* birdInFlight;
	GameObject2D* previousBird;
	std::vector<GameObject2D*> birdsInQueue;
	ShotState state;
	b2Vec2 centerAnchor;

	GameObject2D* camFollow;

	TestLevel* testLevel;
	Level_1_1* level1;
	Level_1_9* level2;
	Level_FerrisWheel* level3;
	Level* currentLevel;
public:
	SlingShot(float x, float y, float rot, bool showDebugShape = false);
	SlingShot() = default;
	~SlingShot() = default;
	SlingShot(const SlingShot&) = delete;
	SlingShot& operator=(const SlingShot&) = delete;

	b2Vec2 GetMouseWorld();

	Trajectory* projTraj;

	void Update();
	void UpdateRubber(GameObject2D* go);
	void UpdateBird();

	void ShootBird();

	void AddBirdToQueue(GameObject2D* bird);
	void ClearBirdsQueue();
};
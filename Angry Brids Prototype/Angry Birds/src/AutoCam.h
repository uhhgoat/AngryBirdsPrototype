#pragma once
#include "Box2D.h"

enum state
{
	AUTO = 0,
	MANUAL = 1,
	RETURNING = 2
};

class AutoCam
{
	float minHeight = 800;
	float maxHeight = 2000;
	float maxLeft = 100;
	float maxRight = 1900;
	float scrollSpeed = 10;
	state currentState = AUTO;

	b2Vec2 manualLocation;
public:
	AutoCam() = delete;
	~AutoCam() = delete;
	AutoCam(const AutoCam&) = delete;
	AutoCam& operator=(const AutoCam&) = delete;

	AutoCam(b2Vec2 start);

	void Update(b2Vec2 cen1, b2Vec2 cen2);

	void SetAuto();
	void SetManual();
	void Return();
};
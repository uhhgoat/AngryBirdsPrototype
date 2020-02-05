#pragma once
#include "Includes.h"
class AutoCam
{
	GameObject2D* target1;
	GameObject2D* target2;
	float minHeight = 500;
public:
	AutoCam(GameObject2D* target1, GameObject2D* target2);

	void Update();
};
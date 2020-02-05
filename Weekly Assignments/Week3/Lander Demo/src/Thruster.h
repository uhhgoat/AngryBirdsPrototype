#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class Thruster : public GameObject2D
{
private:
	float xOff;
	float yOff;
public:

	Thruster(float x, float y, float rot, b2Body *birdBody, float offsetX, float offsetY, bool showDebugShape = false);
	~Thruster() = default;

	void ApplyForce(float force);
	//void ApplyTorque(float torque);
};
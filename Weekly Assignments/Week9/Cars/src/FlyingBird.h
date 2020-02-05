#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
#include "Thruster.h"
class FlyingBird : public GameObject2D
{
private:
	float acceleration;
	float angSpeed;
	float resetX;
	float resetY;
	Thruster* bottom;
	Thruster* bottomL;
	Thruster* bottomR;
	Thruster* left;
	Thruster* right;
public:

	FlyingBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~FlyingBird();

	void FireUp();
	void TurnLeft();
	void TurnRight();
	void ControlFlight();
	void CameraControls();
	virtual void TakeImpact(float damage) override;
	virtual void Update(float t) override;

};
#ifndef _CarCasual
#define _CarCasual
#include "Includes.h"

class b2RevoluteJoint;
class b2WheelJoint;
class Wheel;
class CarBodyCasual;

class CarCasual
{
public:
	CarCasual(float x, float y);
	~CarCasual();

	void Update();

	void Forward();
	void Backward();
	void Break();
	void Coast();

	GameObject2D* getBody();

private:
	//*
	b2RevoluteJoint * pRearWheel;
	b2RevoluteJoint* pFrontWheel;
	//*/

	/*
	b2WheelJoint* pRearWheel;
	b2WheelJoint* pFrontWheel;
	//*/

	static const int CarCasualWidth = 275;
	static const int CarCasualHeight = 85;
	static const int WheelRadius = 11;
	static const int SpeedDelta = 1;
	static const int SpeedLimit = 20;

	float speed;

	CarBodyCasual* pCarCasualBody;
	Wheel* pRear;
	Wheel* pFront;

};

#endif _CarCasual
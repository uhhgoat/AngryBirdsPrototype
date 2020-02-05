#ifndef _CarOffroad
#define _CarOffroad
#include "Includes.h"

class b2RevoluteJoint;
class b2WheelJoint;
class WheelBig;
class CarBodyOffroad;

class CarOffroad
{
public:
	CarOffroad(float x, float y);
	~CarOffroad();

	void Update();

	void Forward();
	void Backward();
	void Break();
	void Coast();

	GameObject2D* getBody();

private:
	/*
	b2RevoluteJoint * pRearWheel;
	b2RevoluteJoint* pFrontWheel;
	//*/

	//*
	b2WheelJoint* pRearWheel;
	b2WheelJoint* pFrontWheel;
	//*/

	static const int CarOffroadWidth = 275;
	static const int CarOffroadHeight = 105;
	static const int WheelRadius = 11;
	static const int SpeedDelta = 1;
	static const int SpeedLimit = 15;

	float speed;

	CarBodyOffroad* pCarOffroadBody;
	WheelBig* pRear;
	WheelBig* pFront;

};

#endif _CarOffroad
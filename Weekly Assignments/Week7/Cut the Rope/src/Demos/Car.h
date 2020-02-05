// Car
// Andre Berthiaume, May 2017

#ifndef _Car
#define _Car

class b2RevoluteJoint;
class b2WheelJoint;
class Gear;
class GenericBlock;

class Car
{
public:
	Car(float x, float y);
	~Car();

	void Update();
	
	void Forward();
	void Backward();
	void Break();
	void Coast();

private:
	//*
	b2RevoluteJoint* pRearWheel;
	b2RevoluteJoint* pFrontWheel;
	//*/

	/*
	b2WheelJoint* pRearWheel;
	b2WheelJoint* pFrontWheel;
	//*/

	static const int CarWidth = 80;
	static const int CarHeight = 25;
	static const int WheelRadius = 20;
	static const int SpeedDelta = 1;

	float speed;

	GenericBlock* pCarBody;
	Gear* pRear;
	Gear* pFront;

};

#endif _Car
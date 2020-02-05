// Wheel Joint Demo
// AB 04/18

#ifndef _WheelJointDemo
#define _WheelJointDemo

class Car;
class GenericBlock;

class WheelJointDemo
{
public:
	WheelJointDemo();
	~WheelJointDemo();

	void Update();

private:
	Car* pCar;
	GenericBlock* pGround;
};

#endif _WheelJointDemo

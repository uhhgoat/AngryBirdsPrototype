// Gear Joint Demo
// AB 04/18

#ifndef _GearJointDemo
#define _GearJointDemo

class b2MouseJoint;
class Gear;
class BlockWoodLong;
class Pig;
class StickWood;

class GearJointDemo
{
public:
	GearJointDemo();
	~GearJointDemo();

	void Update();

private:
	b2MouseJoint* pMouseJoint;

	Gear* pBigGear;
	Gear* pSmallGear;
	BlockWoodLong* pGround;
	Pig* pPig;
	StickWood* pStick;
};

#endif _GearJointDemo

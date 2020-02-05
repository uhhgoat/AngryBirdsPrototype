
#ifndef _RopeJointDemo
#define _RopeJointDemo

class StickWood;
class GenericBlock;
class RedBird;

class RopeJointDemo
{
private:
	int segmentCount;
	StickWood** pStickArray;
	StickWood** pStickArray2;

	RedBird* bird;

	GenericBlock* pCeiling;

public:
	RopeJointDemo();
	~RopeJointDemo();
};

#endif _RopeJointDemo
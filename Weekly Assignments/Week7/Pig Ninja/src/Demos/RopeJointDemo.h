// Rope Joint Demo
// AB 04/18

#ifndef _RopeJointDemo
#define _RopeJointDemo

class StickWood;
class GenericBlock;

class RopeJointDemo
{
private:
	int segmentCount;
	StickWood** pStickArray;

	GenericBlock* pCeiling;

public:
	RopeJointDemo();
	~RopeJointDemo();
};

#endif _RopeJointDemo
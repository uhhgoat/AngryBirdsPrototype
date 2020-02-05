// Joint Demo
// Andre Berthiaume, April 2017

#ifndef _JointDemo
#define _JointDemo

class Pig;
class GenericBlock;

class DistanceJointDemo
{
public:
	DistanceJointDemo();
	~DistanceJointDemo();

	Pig* pPig;
	GenericBlock* pBase;
	GenericBlock* pPlatform;
};


#endif _JointDemo

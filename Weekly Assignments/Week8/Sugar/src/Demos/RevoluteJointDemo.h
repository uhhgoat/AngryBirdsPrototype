// Revolute Joint Demo
// AB 04/18

#ifndef _RevoluteJointDemo
#define _RevoluteJointDemo

class StickWood;
class GenericBlock;

class RevoluteJointDemo
{
private:
	StickWood * pStick1;
	GenericBlock* pCeiling;

public:
	RevoluteJointDemo();
	~RevoluteJointDemo();
};

#endif _RevoluteJointDemo
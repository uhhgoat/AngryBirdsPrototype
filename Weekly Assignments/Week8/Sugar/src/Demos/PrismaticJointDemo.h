// Prismatic Joint Demo
// AB 04/18

#ifndef _PrismaticJointDemo
#define _PrismaticJointDemo

class BlockWoodLong;
class b2PrismaticJoint;
class GenericBlock;
class Pig;

class PrismaticJointDemo
{
public:
	PrismaticJointDemo();
	~PrismaticJointDemo();

	void Update();

private:
	BlockWoodLong* pFrame;
	GenericBlock* pPiston;
	b2PrismaticJoint* pPrisJoint;
	GenericBlock* pmarkerTop;
	GenericBlock* pmarkerBot;
	Pig* pPig;
};

#endif _PrismaticJointDemo

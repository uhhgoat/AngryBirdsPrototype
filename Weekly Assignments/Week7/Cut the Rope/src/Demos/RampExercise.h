// Ramp Exercise
// AB 04/18

#ifndef _RampExercise
#define _RampExercise

class BlockWoodLong;
class b2PrismaticJoint;

class RampExercise
{
public:
	RampExercise();

	void Update();

	void Solution();

private:
	BlockWoodLong* pFrame;

	b2PrismaticJoint* pPrisJoint;

	b2PrismaticJoint* npPrisJoint;
};

#endif _RampExercise
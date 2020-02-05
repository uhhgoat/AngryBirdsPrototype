// Piston Exercise
// AB 04/18

#ifndef _PistonExercise
#define _PistonExercise

class b2MouseJoint;
class b2PrismaticJoint;
class Gear;
class BlockWoodLong;

class PistonExercise
{
public:
	PistonExercise();

	void Solution();

	void Update();

private:
	b2MouseJoint* pMouseJoint;

	Gear* pBigGear;
	BlockWoodLong* pGround;
};

#endif _PistonExercise

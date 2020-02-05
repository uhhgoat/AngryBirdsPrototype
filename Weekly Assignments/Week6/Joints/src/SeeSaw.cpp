#include "SeeSaw.h"
SeeSaw::SeeSaw(b2World &world)
{
	
	pGround = new GlassBlockLong(1500, 10, 0, world);
	GameObjectMan::Add(pGround, GameObjectName::MainGroup);

	pivot = new EtherealBlock(1500, -100, MATH_PI2, world);
	GameObjectMan::Add(pivot, GameObjectName::MainGroup);

	b2RevoluteJointDef pivjoint;
	pivjoint.Initialize(pGround->GetBody(), pivot->GetBody(), pivot->GetPosWorld());

	b2Joint* pPivJoint = Game::GetB2World()->CreateJoint(&pivjoint);
	pPivJoint; // Shutting up the compiler

	lever = new WoodBlockLong(1500, 150, 0, world);
	GameObjectMan::Add(lever, GameObjectName::MainGroup);

	
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pGround->GetBody(), lever->GetBody(), lever->GetPosWorld());

	b2Joint* pMainGearJoint = Game::GetB2World()->CreateJoint(&rjdef);
	pMainGearJoint; // Shutting up the compiler

	block1 = new WoodBlockShort(1850, 150, 0, world);
	GameObjectMan::Add(block1, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef.Initialize(lever->GetBody(), block1->GetBody(), block1->GetPosWorld());
	rjdef.enableMotor = false;

	b2Joint* pStickJoint = Game::GetB2World()->CreateJoint(&rjdef);

	pStickJoint; // Shutting up the compiler
				 //*/

				 //*
				 // Add Gear Joint
	b2GearJointDef gjdef;
	gjdef.bodyA = lever->GetBody();
	gjdef.bodyB = block1->GetBody();
	gjdef.joint1 = pMainGearJoint;
	gjdef.joint2 = pStickJoint;
	gjdef.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef);

	block2 = new WoodBlockShort(1150, 150, 0, world);
	GameObjectMan::Add(block2, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef.Initialize(lever->GetBody(), block2->GetBody(), block2->GetPosWorld());
	rjdef.enableMotor = false;

	b2Joint* pStickJoint2 = Game::GetB2World()->CreateJoint(&rjdef);

	pStickJoint2; // Shutting up the compiler
				 //*/

				 //*
				 // Add Gear Joint
	b2GearJointDef gjdef2;
	gjdef2.bodyA = lever->GetBody();
	gjdef2.bodyB = block2->GetBody();
	gjdef2.joint1 = pMainGearJoint;
	gjdef2.joint2 = pStickJoint2;
	gjdef2.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef2);

	pig1 = new KingPig(1150, 200, 0, world, true);
	GameObjectMan::Add(pig1, GameObjectName::MainGroup);
	pig2 = new KingPig(1850, 1500, 0, world, true);
	GameObjectMan::Add(pig2, GameObjectName::MainGroup);
}

SeeSaw::~SeeSaw()
{
	delete pGround;

	delete block1;
	delete block2;

	delete pivot;
	delete lever;

	delete pig1;
	delete pig2;
}
#include "FerrisWheel.h"
FerrisWheel::FerrisWheel(b2World &world)
{
	pGround = new GlassBlockLong(350, 10, 0, world);
	GameObjectMan::Add(pGround, GameObjectName::MainGroup);

	eBlock1 = new EtherealBlock(400, 300, 0, world);
	GameObjectMan::Add(eBlock1, GameObjectName::EffectsGroup);

	// Add Revolute Joints
	// Main gear
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pGround->GetBody(), eBlock1->GetBody(), eBlock1->GetPosWorld());
	//*
	rjdef.enableMotor = true;
	rjdef.motorSpeed = -0.5f;
	rjdef.maxMotorTorque = 2000;
	//*/

	b2Joint* pMainGearJoint = Game::GetB2World()->CreateJoint(&rjdef);
	pMainGearJoint; // Shutting up the compiler
	//-------------------------------------------------------
	eBlock2 = new EtherealBlock(400, 300, MATH_PI3, world);
	GameObjectMan::Add(eBlock2, GameObjectName::MainGroup);

	// Add Revolute Joints
	// Main gear
	b2RevoluteJointDef rjdef2;
	rjdef2.Initialize(pGround->GetBody(), eBlock2->GetBody(), eBlock2->GetPosWorld());
	/*
	rjdef2.enableMotor = true;
	rjdef2.motorSpeed = -1;
	rjdef2.maxMotorTorque = 1000;
	//*/

	b2Joint* pMainGearJoint2 = Game::GetB2World()->CreateJoint(&rjdef2);
	pMainGearJoint2; // Shutting up the compiler

	b2GearJointDef gjdef01;
	gjdef01.bodyA = eBlock1->GetBody();
	gjdef01.bodyB = eBlock2->GetBody();
	gjdef01.joint1 = pMainGearJoint;
	gjdef01.joint2 = pMainGearJoint2;
	gjdef01.ratio = -1;

	Game::GetB2World()->CreateJoint(&gjdef01);
	//-------------------------------------------------------
	eBlock3 = new EtherealBlock(400, 300, MATH_2PI3, world);
	GameObjectMan::Add(eBlock3, GameObjectName::MainGroup);

	// Add Revolute Joints
	// Main gear
	b2RevoluteJointDef rjdef3;
	rjdef3.Initialize(pGround->GetBody(), eBlock3->GetBody(), eBlock3->GetPosWorld());
	/*
	rjdef3.enableMotor = true;
	rjdef3.motorSpeed = -1;
	rjdef3.maxMotorTorque = 1000;
	//*/

	b2Joint* pMainGearJoint3 = Game::GetB2World()->CreateJoint(&rjdef3);
	pMainGearJoint3; // Shutting up the compiler

	b2GearJointDef gjdef02;
	gjdef02.bodyA = eBlock1->GetBody();
	gjdef02.bodyB = eBlock3->GetBody();
	gjdef02.joint1 = pMainGearJoint;
	gjdef02.joint2 = pMainGearJoint3;
	gjdef02.ratio = -1;

	Game::GetB2World()->CreateJoint(&gjdef02);

	//----------------------NOW THE PLATFORMS--------------------------

	block1 = new WoodBlockShort(175, 300, 0, world);
	GameObjectMan::Add(block1, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef.Initialize(eBlock1->GetBody(), block1->GetBody(), block1->GetPosWorld());
	rjdef.enableMotor = false;

	b2Joint* pStickJoint = Game::GetB2World()->CreateJoint(&rjdef);

	pStickJoint; // Shutting up the compiler
				 //*/

				 //*
				 // Add Gear Joint
	b2GearJointDef gjdef;
	gjdef.bodyA = eBlock1->GetBody();
	gjdef.bodyB = block1->GetBody();
	gjdef.joint1 = pMainGearJoint;
	gjdef.joint2 = pStickJoint;
	gjdef.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef);
	//----------------------------------------
	block2 = new WoodBlockShort(625, 300, 0, world);
	GameObjectMan::Add(block2, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef.Initialize(eBlock1->GetBody(), block2->GetBody(), block2->GetPosWorld());
	rjdef.enableMotor = false;

	b2Joint* pStickJoint2 = Game::GetB2World()->CreateJoint(&rjdef);

	pStickJoint2; // Shutting up the compiler
				 //*/

				 //*
				 // Add Gear Joint
	b2GearJointDef gjdef2;
	gjdef2.bodyA = eBlock1->GetBody();
	gjdef2.bodyB = block2->GetBody();
	gjdef2.joint1 = pMainGearJoint;
	gjdef2.joint2 = pStickJoint2;
	gjdef2.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef2);
	//---------------------------------------------
	block3 = new WoodBlockShort(275, 100, 0, world);
	GameObjectMan::Add(block3, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef2.Initialize(eBlock2->GetBody(), block3->GetBody(), block3->GetPosWorld());
	rjdef2.enableMotor = false;

	b2Joint* pStickJoint3 = Game::GetB2World()->CreateJoint(&rjdef2);

	pStickJoint3; // Shutting up the compiler
				 //*/

				 //*
				 // Add Gear Joint
	b2GearJointDef gjdef3;
	gjdef3.bodyA = eBlock2->GetBody();
	gjdef3.bodyB = block3->GetBody();
	gjdef3.joint1 = pMainGearJoint2;
	gjdef3.joint2 = pStickJoint3;
	gjdef3.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef3);
	//----------------------------------------
	block4 = new WoodBlockShort(525, 500, 0, world);
	GameObjectMan::Add(block4, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef2.Initialize(eBlock2->GetBody(), block4->GetBody(), block4->GetPosWorld());
	rjdef2.enableMotor = false;

	b2Joint* pStickJoint4 = Game::GetB2World()->CreateJoint(&rjdef2);

	pStickJoint4; // Shutting up the compiler
				  //*/

				  //*
				  // Add Gear Joint
	b2GearJointDef gjdef4;
	gjdef4.bodyA = eBlock2->GetBody();
	gjdef4.bodyB = block4->GetBody();
	gjdef4.joint1 = pMainGearJoint2;
	gjdef4.joint2 = pStickJoint4;
	gjdef4.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef4);
	//---------------------------------------------
	block5 = new WoodBlockShort(275, 500, 0, world);
	GameObjectMan::Add(block5, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef3.Initialize(eBlock3->GetBody(), block5->GetBody(), block5->GetPosWorld());
	rjdef3.enableMotor = false;

	b2Joint* pStickJoint5 = Game::GetB2World()->CreateJoint(&rjdef3);

	pStickJoint5; // Shutting up the compiler
				  //*/

				  //*
				  // Add Gear Joint
	b2GearJointDef gjdef5;
	gjdef5.bodyA = eBlock3->GetBody();
	gjdef5.bodyB = block5->GetBody();
	gjdef5.joint1 = pMainGearJoint3;
	gjdef5.joint2 = pStickJoint5;
	gjdef5.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef5);
	//---------------------------------------------
	block6 = new WoodBlockShort(525, 100, 0, world);
	GameObjectMan::Add(block6, GameObjectName::Structure);

	// Small gear/stick (coupled)
	rjdef3.Initialize(eBlock3->GetBody(), block6->GetBody(), block6->GetPosWorld());
	rjdef3.enableMotor = false;

	b2Joint* pStickJoint6 = Game::GetB2World()->CreateJoint(&rjdef3);

	pStickJoint6; // Shutting up the compiler
				  //*/

				  //*
				  // Add Gear Joint
	b2GearJointDef gjdef6;
	gjdef6.bodyA = eBlock3->GetBody();
	gjdef6.bodyB = block6->GetBody();
	gjdef6.joint1 = pMainGearJoint3;
	gjdef6.joint2 = pStickJoint6;
	gjdef6.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef6);

	

	pig = new KingPig(175, 400, 0, world, true);
	GameObjectMan::Add(pig, GameObjectName::MainGroup);
}

FerrisWheel::~FerrisWheel()
{
	delete pGround;
	
	delete block1;
	delete block2;
	delete block3;
	delete block4;
	delete block5;
	delete block6;

	delete eBlock1;
	delete eBlock2;
	delete eBlock3;

	delete pig;
}
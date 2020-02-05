#include "PistonExercise.h"
#include "Box2D.h"
#include "BlockWoodLong.h"
#include "GameObjectMan.h"
#include "Gear.h"
#include "Game.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "InputTest.h"
#include "StickWood.h"
#include "Pig.h"
#include "Demos\GetMouseWorld.h"
#include "GenericBlock.h"

PistonExercise::PistonExercise()
{
	pMouseJoint = nullptr;

	b2Vec2 framePos(400, 10);
	pGround = new BlockWoodLong(framePos.x, framePos.y, 0);
	GameObjectMan::Add(pGround, GameObjectName::MainGroup);

	GenericBlock* pCrank = new GenericBlock(400, 130, 0, 10, 130, GameObjectName::Block, ImageName::Long_Wood_Block);
	GameObjectMan::Add(pCrank, GameObjectName::MainGroup);
	//pCrank->GetBody()->SetType(b2_staticBody);

	GenericBlock* pPiston = new GenericBlock(400, 190, 0, 70, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPiston, GameObjectName::MainGroup);
	//pPiston->GetBody()->SetType(b2_staticBody);

	pBigGear = new Gear(400, 100, 0, 50, GameObjectName::GearLarge, ImageName::GearLarge);
	GameObjectMan::Add(pBigGear, GameObjectName::MainGroup);
	//pBigGear->GetBody()->SetType(b2_staticBody);

	/*
	Pig* pPig = new Pig(420, 350, 0);
	GameObjectMan::Add(pPig, GameObjectName::BirdGroup);
	//*/

	// Add Revolute Joints
	/*
	b2RevoluteJointDef GearFrameRJDef;

	

	b2Joint* pGearFrameJoint = Game::GetB2World()->CreateJoint(&GearFrameRJDef);
	pGearFrameJoint;
	//*/

	/*
	b2RevoluteJointDef GearCrankJointDef;



	b2Joint* pGearCrankJoint = Game::GetB2World()->CreateJoint(&GearCrankJointDef);
	pGearCrankJoint; // Shutting up the compiler
	//*/

	/*
	b2RevoluteJointDef CrankPistonJointDef;



	b2Joint* pCrankPistonJoint = Game::GetB2World()->CreateJoint(&CrankPistonJointDef);
	pCrankPistonJoint; // Shutting up the compiler
	//*/

	/*
	// Add Prismatic Joint
	b2PrismaticJointDef pjdef;



	b2PrismaticJoint* pPrisJoint = (b2PrismaticJoint*) Game::GetB2World()->CreateJoint(&pjdef);
	pPrisJoint; // Shutting up the compiler
	//*/

	Solution();
}

void PistonExercise::Update()
{
	// Mouse joint Drag
	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		b2Vec2 mouseInWorld = GetMouseWorld();

		DebugMsg::out("Drag\n");

		// start click?
		if (pMouseJoint == nullptr)
		{
			// On the main gear?
			if (pBigGear->GetBody()->GetFixtureList()->TestPoint(mouseInWorld))
			{
				b2MouseJointDef mjd;
				mjd.bodyA = pGround->GetBody();  // Actually not used, but can't be nullptr and can't be bodyB... (this joint is a debug hack)
				mjd.bodyB = pBigGear->GetBody();
				mjd.target = mouseInWorld;
				mjd.maxForce = 500;

				pMouseJoint = (b2MouseJoint*)Game::GetB2World()->CreateJoint(&mjd);
			}
		}
		else // dragging the mouse after a click on the big gear
		{
			pMouseJoint->SetTarget(mouseInWorld); // Updating the target
		}
	}
	else // releasing the mouse
	{
		if (pMouseJoint != nullptr)
		{
			Game::GetB2World()->DestroyJoint(pMouseJoint); // clear the joint
			pMouseJoint = nullptr;
		}
	}
}

void PistonExercise::Solution()
{
	// ***** Solution ****
	b2Vec2 framePos(600, 10);
	BlockWoodLong* npGround = new BlockWoodLong(framePos.x, framePos.y, 0);
	GameObjectMan::Add(npGround, GameObjectName::MainGroup);

	GenericBlock* pCrank = new GenericBlock(600, 130, 0, 10, 130, GameObjectName::Block, ImageName::Long_Wood_Block);
	GameObjectMan::Add(pCrank, GameObjectName::MainGroup);
	pCrank->GetBody()->SetType(b2_dynamicBody);

	GenericBlock* pPiston = new GenericBlock(600, 190, 0, 70, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPiston, GameObjectName::MainGroup);
	pPiston->GetBody()->SetType(b2_dynamicBody);

	Gear* npBigGear = new Gear(600, 100, 0, 50, GameObjectName::GearLarge, ImageName::GearLarge);
	GameObjectMan::Add(npBigGear, GameObjectName::MainGroup);
	npBigGear->GetBody()->SetType(b2_dynamicBody);

	npBigGear;

	// Add Revolute Joints
	//*
	b2RevoluteJointDef GearFrameRJDef;

	GearFrameRJDef.Initialize(npGround->GetBody(), npBigGear->GetBody(), npBigGear->GetPosWorld());
	GearFrameRJDef.enableMotor = true;
	GearFrameRJDef.motorSpeed = 2;
	GearFrameRJDef.maxMotorTorque = 300;

	b2Joint* pGearFrameJoint = Game::GetB2World()->CreateJoint(&GearFrameRJDef);
	pGearFrameJoint; // Shutting up the compiler
	//*/

	//*
	b2RevoluteJointDef GearCrankJointDef;

	b2Vec2 anchor = pCrank->GetBody()->GetWorldPoint(b2Vec2(0, PixelToMeter(-65)));
	GearCrankJointDef.Initialize(npBigGear->GetBody(), pCrank->GetBody(), anchor);

	b2Joint* pGearCrankJoint = Game::GetB2World()->CreateJoint(&GearCrankJointDef);
	pGearCrankJoint; // Shutting up the compiler
	//*/

	//*
	b2RevoluteJointDef CrankPistonJointDef;

	CrankPistonJointDef.Initialize(pPiston->GetBody(), pCrank->GetBody(), pPiston->GetPosWorld());

	b2Joint* pCrankPistonJoint = Game::GetB2World()->CreateJoint(&CrankPistonJointDef);
	pCrankPistonJoint; // Shutting up the compiler
	//*/

	//*
	// Add Prismatic Joint
	b2PrismaticJointDef pjdef;

	b2Vec2 Axis(0, 1);
	pjdef.Initialize(npGround->GetBody(), pPiston->GetBody(), npGround->GetPosWorld(), Axis);

	b2PrismaticJoint* pPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&pjdef);
	pPrisJoint; // Shutting up the compiler
	//*/
	
	//*
	pjdef.bodyA = npGround->GetBody();
	pjdef.bodyB = pPiston->GetBody();
	pjdef.localAnchorA = b2Vec2(0, 0);
	pjdef.localAnchorB = b2Vec2(0, 0);
	pjdef.localAxisA = Axis;

	pPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&pjdef);

	pPrisJoint; // Shutting up the compiler
	//*/
}
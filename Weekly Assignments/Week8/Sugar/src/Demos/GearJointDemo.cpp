#include "GearJointDemo.h"
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

GearJointDemo::GearJointDemo()
{
	pMouseJoint = nullptr;
	pBigGear = nullptr;
	pSmallGear = nullptr;
	pGround = nullptr;
	pStick = nullptr;
	pPig = nullptr;

	b2Vec2 groundPos(350, 10);
	pGround = new BlockWoodLong(groundPos.x, groundPos.y, 0);
	GameObjectMan::Add(pGround, GameObjectName::MainGroup);

	pBigGear = new Gear(400, 300, 0, 150, GameObjectName::GearLarge, ImageName::GearLarge);
	GameObjectMan::Add(pBigGear, GameObjectName::MainGroup);

	// Add Revolute Joints
	// Main gear
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pGround->GetBody(), pBigGear->GetBody(), pBigGear->GetPosWorld());
	/*
	rjdef.enableMotor = true;
	rjdef.motorSpeed = -1;
	rjdef.maxMotorTorque = 500;
	//*/

	b2Joint* pMainGearJoint = Game::GetB2World()->CreateJoint(&rjdef);
	pMainGearJoint; // Shutting up the compiler


	// ************ Small gear demo ***********
	/*
	pSmallGear = new Gear(190, 300, 0, 50, GameObjectName::GearSmall, ImageName::GearSmall);
	GameObjectMan::Add(pSmallGear, GameObjectName::MainGroup);
	//*/

	/*
	// Small gear (uncoupled)
	rjdef.Initialize(pGround->GetBody(), pSmallGear->GetBody(), pSmallGear->GetPosWorld());
	//
	//rjdef.enableMotor = true;
	//rjdef.motorSpeed = 3;
	//rjdef.maxMotorTorque = 500;
	//
	b2Joint* pSmallGearJoint = Game::GetB2World()->CreateJoint(&rjdef);
	
	pSmallGearJoint; // Shutting up the compiler
	//*/

	/*
	// Small gear (coupled)
	rjdef.Initialize(pBigGear->GetBody(), pSmallGear->GetBody(), pSmallGear->GetPosWorld());
	rjdef.enableMotor = false;
	rjdef.motorSpeed = 1;
	rjdef.maxMotorTorque = 300;
	b2Joint* pSmallGearJoint = Game::GetB2World()->CreateJoint(&rjdef);
	
	pSmallGearJoint; // Shutting up the compiler
	//*/

	/*
	// Add Gear Joint
	b2GearJointDef gjdef;
	gjdef.bodyA = pBigGear->GetBody();
	gjdef.bodyB = pSmallGear->GetBody();
	gjdef.joint1 = pMainGearJoint;
	gjdef.joint2 = pSmallGearJoint;
	gjdef.ratio = .3f;

	Game::GetB2World()->CreateJoint(&gjdef);
	//*/
	
	// ***************** Stick and platform demo
	
	/*
	pStick = new StickWood(175, 300, 0, 70, 15);
	GameObjectMan::Add(pStick, GameObjectName::MainGroup);
	
	// Small gear/stick (coupled)
	rjdef.Initialize(pBigGear->GetBody(), pStick->GetBody(), pStick->GetPosWorld());
	rjdef.enableMotor = false;

	b2Joint* pStickJoint = Game::GetB2World()->CreateJoint(&rjdef);

	pStickJoint; // Shutting up the compiler
	//*/

	/*
	// Add Gear Joint
	b2GearJointDef gjdef;
	gjdef.bodyA = pBigGear->GetBody();
	gjdef.bodyB = pStick->GetBody();
	gjdef.joint1 = pMainGearJoint;
	gjdef.joint2 = pStickJoint;
	gjdef.ratio = 1;

	Game::GetB2World()->CreateJoint(&gjdef);
	//*/
	
	/*
	pPig = new Pig(175, 320, 0);
	GameObjectMan::Add(pPig, GameObjectName::BirdGroup);
	//*/

}

void GearJointDemo::Update()
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

GearJointDemo::~GearJointDemo()
{
	//delete pMouseJoint;
	if (pBigGear) GameObjectMan::Delete( pBigGear );
	if (pSmallGear) GameObjectMan::Delete(pSmallGear);
	if (pGround) GameObjectMan::Delete(pGround);
	if (pStick) GameObjectMan::Delete(pStick);
	if (pPig) GameObjectMan::Delete(pPig);
}
#include "RampExercise.h"
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
#include "GenericBlock.h"

RampExercise::RampExercise()
{
	b2Vec2 framePos(400, 100);
	pFrame = new BlockWoodLong(framePos.x, framePos.y, 0);
	GameObjectMan::Add(pFrame, GameObjectName::BirdGroup);

	GenericBlock* pRamp = new GenericBlock(framePos.x, framePos.y + 10, 0, 200, 20, GameObjectName::Block, ImageName::Long_Wood_Block);
	GameObjectMan::Add(pRamp, GameObjectName::MainGroup);
	pRamp->GetBody()->SetType(b2_dynamicBody);

	pPrisJoint = nullptr;
	npPrisJoint = nullptr;

	// Joint Creation
	/*
	b2RevoluteJointDef RJDef;
	RJDef.Initialize(
		pFrame->GetBody(),
		pRamp->GetBody(),
		pRamp->GetBody()->GetWorldPoint(b2Vec2(PixelToMeter(-100), 0))
	);
	//RJDef.enableLimit = true;
	//RJDef.lowerAngle = 0;
	//RJDef.upperAngle = MATH_PI2;
	Game::GetB2World()->CreateJoint(&RJDef);
	//*/

	/*
	// Prismatic joint (not necessarily good)
	b2PrismaticJointDef PJDef;
	PJDef.Initialize(
			pFrame->GetBody(),
			pRamp->GetBody(),
			pRamp->GetBody()->GetWorldCenter() + b2Vec2( 0, PixelToMeter(pRamp->origWidth)) ,
			b2Vec2(-1, 1)
			);
	PJDef.enableMotor = true;
	PJDef.maxMotorForce = 10000;
	pPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&PJDef);
	//*/

	/*
	// Second Try: adding block with pin joints
	// pin block for ramp
	GenericBlock* pPinBlockRamp = new GenericBlock(pRamp->posX + pRamp->origWidth / 2, pRamp->posY, 0, 15, 15, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPinBlockRamp, GameObjectName::EffectsGroup);
	pPinBlockRamp->GetBody()->SetType(b2_dynamicBody);

	// pin block for frame
	GenericBlock* pPinBlockFrame = new GenericBlock(framePos.x + pRamp->origWidth / 2, framePos.y, 0, 15, 15, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPinBlockFrame, GameObjectName::EffectsGroup);
	pPinBlockFrame->GetBody()->SetType(b2_dynamicBody);
	//*/

	/*
	// revolute joints for both pin blocks
	//b2RevoluteJointDef RJDef;
	RJDef.Initialize(pRamp->GetBody(), pPinBlockRamp->GetBody(), pPinBlockRamp->GetBody()->GetWorldCenter());
	Game::GetB2World()->CreateJoint(&RJDef);
	RJDef.Initialize(pFrame->GetBody(), pPinBlockFrame->GetBody(), pPinBlockFrame->GetBody()->GetWorldCenter());
	Game::GetB2World()->CreateJoint(&RJDef);
	//*/

	/*
	// Now we can add the prismatic joint between the pin blocks
	b2PrismaticJointDef PJDef;
	//*
	PJDef.Initialize(
		pPinBlockFrame->GetBody(),
		pPinBlockRamp->GetBody(),
		pPinBlockRamp->GetBody()->GetWorldCenter(),
		b2Vec2(0, 1)
	);
	//*/

	/*
	PJDef.bodyA = pPinBlockFrame->GetBody();
	PJDef.bodyB = pPinBlockRamp->GetBody();
	PJDef.localAnchorA = b2Vec2(0, 0);
	PJDef.localAnchorB = b2Vec2(0, 0);
	PJDef.localAxisA = b2Vec2(0, 1);
	//*/

	/*
	PJDef.enableMotor = true;
	PJDef.maxMotorForce = 10000;
	pPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&PJDef);
	//*/

	Solution();
}

void RampExercise::Update()
{
	if (pPrisJoint != nullptr)  // Only because of lecture struture.
	{
		// keyboard piston control
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
		{
			pPrisJoint->SetMotorSpeed(1);
			pPrisJoint->SetMaxMotorForce(300);
		}
		else 	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
		{
			pPrisJoint->SetMotorSpeed(-1);
			pPrisJoint->SetMaxMotorForce(300);
		}
		else
		{
			pPrisJoint->SetMotorSpeed(0);
		}
	}

	// Solution control
	if (npPrisJoint != nullptr)  // Only because of lecture struture.
	{
		// keyboard piston control
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
		{
			npPrisJoint->SetMotorSpeed(1);
			npPrisJoint->SetMaxMotorForce(300);
		}
		else 	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
		{
			npPrisJoint->SetMotorSpeed(-1);
			npPrisJoint->SetMaxMotorForce(300);
		}
		else
		{
			npPrisJoint->SetMotorSpeed(0);
		}
	}
}

void RampExercise::Solution()
{
	b2Vec2 framePos(400, 400);
	BlockWoodLong* npFrame = new BlockWoodLong(framePos.x, framePos.y, 0);
	GameObjectMan::Add(npFrame, GameObjectName::BirdGroup);

	GenericBlock* pRamp = new GenericBlock(framePos.x, framePos.y + 10, 0, 200, 20, GameObjectName::Block, ImageName::Long_Wood_Block);
	GameObjectMan::Add(pRamp, GameObjectName::MainGroup);
	pRamp->GetBody()->SetType(b2_dynamicBody);

	// Joint Creation
	//*
	b2RevoluteJointDef RJDef;
	RJDef.Initialize(
		npFrame->GetBody(),
		pRamp->GetBody(),
		pRamp->GetBody()->GetWorldPoint(b2Vec2(PixelToMeter(-100), 0))
	);
	//RJDef.enableLimit = true;
	//RJDef.lowerAngle = 0;
	//RJDef.upperAngle = MATH_PI2;
	Game::GetB2World()->CreateJoint(&RJDef);
	//*/

	//*
	// Second Try: adding block with pin joints
	// pin block for ramp
	GenericBlock* pPinBlockRamp = new GenericBlock(pRamp->posX + pRamp->origWidth / 2, pRamp->posY, 0, 15, 15, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPinBlockRamp, GameObjectName::EffectsGroup);
	pPinBlockRamp->GetBody()->SetType(b2_dynamicBody);
	pPinBlockRamp->SetDrawDebug(false);
	pPinBlockRamp->SetDrawSprite(false);

	// pin block for frame
	GenericBlock* pPinBlockFrame = new GenericBlock(framePos.x + pRamp->origWidth / 2, framePos.y, 0, 15, 15, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPinBlockFrame, GameObjectName::EffectsGroup);
	pPinBlockFrame->GetBody()->SetType(b2_dynamicBody);
	pPinBlockFrame->SetDrawDebug(false);
	pPinBlockFrame->SetDrawSprite(false);
	//*/

	//*
	// revolute joints for both pin blocks
	//b2RevoluteJointDef RJDef;
	RJDef.Initialize(pRamp->GetBody(), pPinBlockRamp->GetBody(), pPinBlockRamp->GetBody()->GetWorldCenter());
	Game::GetB2World()->CreateJoint(&RJDef);
	RJDef.Initialize(npFrame->GetBody(), pPinBlockFrame->GetBody(), pPinBlockFrame->GetBody()->GetWorldCenter());
	Game::GetB2World()->CreateJoint(&RJDef);
	//*/

	//*
	// Now we can add the prismatic joint between the pin blocks
	b2PrismaticJointDef PJDef;
	/*
	PJDef.Initialize(
	pPinBlockFrame->GetBody(),
	pPinBlockRamp->GetBody(),
	pPinBlockRamp->GetBody()->GetWorldCenter(),
	b2Vec2(0, 1)
	);
	//*/

	//*
	PJDef.bodyA = pPinBlockFrame->GetBody();
	PJDef.bodyB = pPinBlockRamp->GetBody();
	PJDef.localAnchorA = b2Vec2(0, 0);
	PJDef.localAnchorB = b2Vec2(0, 0);
	PJDef.localAxisA = b2Vec2(0, 1);
	//*/

	//*
	PJDef.enableMotor = true;
	PJDef.maxMotorForce = 10000;
	npPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&PJDef);
	//*/

}
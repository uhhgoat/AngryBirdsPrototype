#include "PrismaticJointDemo.h"
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

PrismaticJointDemo::PrismaticJointDemo()
{
	pPig = nullptr;
	pmarkerBot = nullptr;
	pmarkerTop = nullptr;
	pPiston = nullptr;
	pPrisJoint = nullptr;
	pFrame = nullptr;

	b2Vec2 framePos(400, 200);
	pFrame = new BlockWoodLong(framePos.x, framePos.y, 0);
	GameObjectMan::Add(pFrame, GameObjectName::MainGroup);

	pPiston = new GenericBlock(400, 300, 0, 70, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	GameObjectMan::Add(pPiston, GameObjectName::MainGroup);
	//pPiston->pBody->SetType(b2_staticBody);

	//*
	// Add Prismatic Joint
	b2PrismaticJointDef pjdef;
	b2Vec2 Axis(0, 1);
	
	// I prefer NOT using the 'initialize' version
	//*
	pjdef.bodyA = pFrame->GetBody();
	pjdef.bodyB = pPiston->GetBody();
	pjdef.localAnchorA = pFrame->GetBody()->GetLocalPoint( pPiston->GetBody()->GetWorldCenter() );
	//pjdef.localAnchorA = b2Vec2(0, 0);
	pjdef.localAnchorB = b2Vec2(0, 0);
	pjdef.localAxisA = Axis;
	//*/

	// When visualizing the joints, the anchor points are very odd using initialize
	//pjdef.Initialize(pFrame->GetBody(), pPiston->GetBody(), pFrame->GetPosWorld(), Axis);

	pjdef.enableLimit = true;
	pjdef.upperTranslation = 3; // in meters!
	pjdef.lowerTranslation = 1; // in meters!
	pjdef.enableMotor = true;

	pPrisJoint = (b2PrismaticJoint*)Game::GetB2World()->CreateJoint(&pjdef);
	//*/
	
	// translation markers to visualize the limits
	pmarkerBot = new GenericBlock(500, 350, 0, 70, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	pmarkerBot->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pmarkerBot, GameObjectName::MainGroup);

	pmarkerTop = new GenericBlock(500, 450, 0, 70, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	pmarkerTop->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pmarkerTop, GameObjectName::MainGroup);
	
	/*
	pPig = new Pig(425, 350, 0);
	GameObjectMan::Add(pPig, GameObjectName::BirdGroup);
	//*/
}

void PrismaticJointDemo::Update()
{
	// keyboard pistoin control
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		pPrisJoint->SetMotorSpeed(1);
		pPrisJoint->SetMaxMotorForce(300);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		pPrisJoint->SetMotorSpeed(-1);
		pPrisJoint->SetMaxMotorForce(300);
	}
	else
	{
		pPrisJoint->SetMotorSpeed(0);
	}
}

PrismaticJointDemo::~PrismaticJointDemo()
{
	if (pPig) GameObjectMan::Delete( pPig );
	GameObjectMan::Delete(pmarkerBot);
	GameObjectMan::Delete(pmarkerTop);
	GameObjectMan::Delete(pPiston);
	GameObjectMan::Delete(pFrame);
}
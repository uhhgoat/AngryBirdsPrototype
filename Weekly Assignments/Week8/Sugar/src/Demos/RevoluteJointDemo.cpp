#include "RevoluteJointDemo.h"
#include "BlockWoodLong.h"
#include "GameObjectMan.h"
#include "PixelToMeter.h"
#include "Game.h"
#include "StickWood.h"
#include "GenericBlock.h"
#include "Pig.h"

RevoluteJointDemo::RevoluteJointDemo()
{
	b2Vec2 ceilingPos(400, 580);
	pCeiling = new GenericBlock(ceilingPos.x, ceilingPos.y, 0, 600, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	pCeiling->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pCeiling, GameObjectName::MainGroup);

	// dropped block
	float stickwidth = 200;
	float stickheight = 10;

	pStick1 = new StickWood(ceilingPos.x, ceilingPos.y - stickwidth / 2, MATH_PI2, stickwidth, stickheight);
	//pStick1 = new StickWood(500, 500, MATH_PI2, stickwidth, stickheight);
	//pStick1 = new StickWood(400, 300, MATH_PI2, stickwidth, stickheight);
	GameObjectMan::Add(pStick1, GameObjectName::Block);
	pStick1->GetBody()->SetType(b2_dynamicBody);

	// Revolute Joint
	b2RevoluteJointDef rjdef;  // https://en.wikipedia.org/wiki/Revolute_joint
	rjdef.Initialize(
		pCeiling->GetBody(),
		pStick1->GetBody(),
		pCeiling->GetBody()->GetWorldCenter() // + b2Vec2(1, 0)
	);

	/*
	// Joint starts at 0 degree!
	rjdef.enableLimit = true;
	rjdef.lowerAngle = -45 * MATH_PI_180;
	rjdef.upperAngle = 45 * MATH_PI_180;
	//*/

	/*
	rjdef.enableMotor = true;
	rjdef.motorSpeed = -1;			// Radians per sec
	rjdef.maxMotorTorque = 500;		// in Newton * meter
	//*/

	Game::GetB2World()->CreateJoint(&rjdef);

	/*
	// ************ Adding a second part  ****************
	StickWood* pStick2 = new StickWood(ceilingPos.x, ceilingPos.y - 3 * stickwidth/2, MATH_PI2, stickwidth, stickheight);
	GameObjectMan::Add(pStick2, GameObjectName::Block);

	rjdef.Initialize(
		pStick1->GetBody(),
		pStick2->GetBody(),
		pStick2->GetBody()->GetWorldPoint( b2Vec2(PixelToMeter( stickwidth / 2.0f), 0))
	);

	// Alternatively, using parameters directly
	//rjdef.bodyA = pStick1->GetBody();
	//rjdef.bodyB = pStick2->GetBody();
	//rjdef.localAnchorA = b2Vec2(PixelToMeter( - stickwidth / 2.0f), 0); // leftmost end of pStick1
	//rjdef.localAnchorB = b2Vec2(PixelToMeter( + stickwidth / 2.0f), 0); // rightmost end of pStick2

	Game::GetB2World()->CreateJoint(&rjdef);
	//*/


}

RevoluteJointDemo::~RevoluteJointDemo()
{
	GameObjectMan::Delete( pStick1);
	GameObjectMan::Delete( pCeiling);
}
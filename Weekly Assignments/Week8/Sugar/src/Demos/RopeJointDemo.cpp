#include "RopeJointDemo.h"
#include "BlockWoodLong.h"
#include "GameObjectMan.h"
#include "PixelToMeter.h"
#include "Game.h"
#include "StickWood.h"
#include "GenericBlock.h"
#include "Pig.h"

RopeJointDemo::RopeJointDemo()
{
	b2Vec2 ceilingPos(400, 580);
	pCeiling = new GenericBlock(ceilingPos.x, ceilingPos.y, 0, 600, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	pCeiling->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pCeiling, GameObjectName::MainGroup);

	// ************** Rope *************** http://stackoverflow.com/questions/16122355/box2d-compromise-between-rope-and-distance-joint-features
	segmentCount = 15;
	pStickArray = new StickWood*[segmentCount];

	b2Body* prevBody = pCeiling->GetBody();
	b2Body* currBody = nullptr;
	StickWood* pStick;
	float stickwidth = 20;
	float stickheight = 9;
	
	b2Vec2 StickPos;
	b2RevoluteJointDef rjdef;
	b2RopeJointDef ropejdef;

	for (int i = 0; i < segmentCount; i++)
	{
		// Compute position of new stick
		StickPos = ceilingPos - b2Vec2(0, i*stickwidth + stickwidth / 2);

		// create new stick
		pStick = new StickWood(StickPos.x, StickPos.y, MATH_PI2, stickwidth, stickheight);
		pStickArray[i] = pStick;
		GameObjectMan::Add(pStick, GameObjectName::MainGroup);
		currBody = pStick->GetBody();

		// Link it up with previous body
		//*
		rjdef.Initialize(
			prevBody,
			currBody,
			currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickwidth / 2.0f), 0))
		);

		//rjdef.enableLimit = true;
		//rjdef.lowerAngle = -4 * MATH_PI_180;
		//rjdef.upperAngle = 4 * MATH_PI_180;

		Game::GetB2World()->CreateJoint(&rjdef);
		//*/

		/*
		// rope joint: Attempt #1 (bad)
		ropejdef.bodyA = prevBody;
		ropejdef.bodyB = currBody;
		ropejdef.localAnchorA.Set(PixelToMeter(-stickwidth / 2.0f), 0);
		ropejdef.localAnchorB.Set(PixelToMeter(+stickwidth / 2.0f), 0);
		ropejdef.maxLength = 0.2f; // length in meters!

		Game::GetB2World()->CreateJoint(&ropejdef);
		//*/

		/*
		// rope joint: Attempt #2 (better)
		ropejdef.bodyA = pCeiling->GetBody();		// all reference from _ceiling_
		ropejdef.bodyB = currBody;
		ropejdef.localAnchorA.Set(0, 0);
		ropejdef.localAnchorB.Set(0, 0);
		ropejdef.maxLength = PixelToMeter((float)(i + 1) * stickwidth); // length in meters!

		Game::GetB2World()->CreateJoint(&ropejdef);
		//*/

		// prepare for next joint
		prevBody = currBody;
		currBody = nullptr;
	}

}

RopeJointDemo::~RopeJointDemo()
{
	GameObjectMan::Delete(pCeiling);

	for (int i = 0; i < segmentCount; i++)
	{
		GameObjectMan::Delete( pStickArray[i] );
	}

	delete[] pStickArray;
}
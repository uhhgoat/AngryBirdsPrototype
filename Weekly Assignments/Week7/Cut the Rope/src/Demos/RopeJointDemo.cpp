#include "RopeJointDemo.h"
#include "BlockWoodLong.h"
#include "GameObjectMan.h"
#include "PixelToMeter.h"
#include "Game.h"
#include "StickWood.h"
#include "GenericBlock.h"
#include "Pig.h"
#include "RedBird.h"

RopeJointDemo::RopeJointDemo()
{
	b2Vec2 ceilingPos(400, 580);
	pCeiling = new GenericBlock(ceilingPos.x, ceilingPos.y, 0, 600, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
	pCeiling->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pCeiling, GameObjectName::MainGroup);

	// ************** Rope *************** http://stackoverflow.com/questions/16122355/box2d-compromise-between-rope-and-distance-joint-features
	segmentCount = 15;
	pStickArray = new StickWood*[segmentCount];
	pStickArray2 = new StickWood*[segmentCount];

	b2Body* prevBody = pCeiling->GetBody();
	b2Body* currBody = nullptr;
	StickWood* pStick;
	float stickwidth = 20;
	float stickheight = 9;
	
	b2Vec2 StickPos;
	b2RevoluteJointDef rjdef;
	b2RopeJointDef ropejdef;

	b2Vec2 currPos;
	b2Vec2 prevPos = ceilingPos - b2Vec2(200 + stickwidth / 2, 0);
	//*
	for (int i = 0; i < segmentCount; i++)
	{
		// Compute position of new stick
		StickPos = ceilingPos - b2Vec2(200 - ((float)i / (float)segmentCount) * 200.0f , i*stickwidth/1.5f + stickwidth / 2);
		currPos = StickPos;
		float rotation = atan2(prevPos.y - currPos.y, prevPos.x - currPos.x);

		// create new stick
		pStick = new StickWood(StickPos.x, StickPos.y, rotation, stickwidth, stickheight);
		pStickArray[i] = pStick;
		GameObjectMan::Add(pStick, GameObjectName::MainGroup);
		currBody = pStick->GetBody();

		// Link it up with previous body
		
		rjdef.Initialize(
			prevBody,
			currBody,
			currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickwidth / 2.0f), 0))
		);

		

		b2RevoluteJoint* j = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);
		pStickArray[i]->SetJoint(j);
		

		// prepare for next joint
		prevBody = currBody;
		currBody = nullptr;
		prevPos = currPos;
	}
	//*/
	prevBody = pCeiling->GetBody();
	prevPos = ceilingPos - b2Vec2(-200 - stickwidth/2, 0);

	for (int i = 0; i < segmentCount; i++)
	{
		// Compute position of new stick
		StickPos = ceilingPos - b2Vec2(-200 + ((float)i / (float)segmentCount) * 200.0f, i*stickwidth/1.5f + stickwidth / 2);
		currPos = StickPos;
		float rotation = atan2(prevPos.y - currPos.y, prevPos.x - currPos.x);

		// create new stick
		pStick = new StickWood(StickPos.x, StickPos.y, rotation, stickwidth, stickheight);
		pStickArray2[i] = pStick;
		GameObjectMan::Add(pStick, GameObjectName::MainGroup);
		currBody = pStick->GetBody();

		// Link it up with previous body

		rjdef.Initialize(
			prevBody,
			currBody,
			currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickwidth / 2.0f), 0))
		);



		b2RevoluteJoint* j = (b2RevoluteJoint*) Game::GetB2World()->CreateJoint(&rjdef);
		pStickArray2[i]->SetJoint(j);


		// prepare for next joint
		prevBody = currBody;
		currBody = nullptr;
		prevPos = currPos;
	}

	StickPos = ceilingPos - b2Vec2(0, segmentCount*stickwidth + stickwidth / 2);
	//create a bird attached to the ends of both ropes
	bird = new RedBird(400, 375, 0);
	bird->GetBody()->SetActive(true);
	GameObjectMan::Add(bird, GameObjectName::MainGroup);

	currBody = bird->GetBody();

	prevBody = pStickArray[segmentCount - 1]->GetBody();

	rjdef.Initialize(
		prevBody,
		currBody,
		currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickwidth / 2.0f), 0))
	);

	Game::GetB2World()->CreateJoint(&rjdef);

	prevBody = pStickArray2[segmentCount - 1]->GetBody();

	rjdef.Initialize(
		prevBody,
		currBody,
		currBody->GetWorldPoint(b2Vec2(PixelToMeter(stickwidth / 2.0f), 0))
	);

	Game::GetB2World()->CreateJoint(&rjdef);

}

RopeJointDemo::~RopeJointDemo()
{
	GameObjectMan::Delete(pCeiling);

	for (int i = 0; i < segmentCount; i++)
	{
		GameObjectMan::Delete( pStickArray[i] );
	}

	delete[] pStickArray;

	for (int i = 0; i < segmentCount; i++)
	{
		GameObjectMan::Delete(pStickArray2[i]);
	}

	delete[] pStickArray2;
}
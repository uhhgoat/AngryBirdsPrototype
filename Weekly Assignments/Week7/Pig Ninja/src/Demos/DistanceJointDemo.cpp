#include "DistanceJointDemo.h"
#include "BlockWoodLong.h"
#include "GameObjectMan.h"
#include "PixelToMeter.h"
#include "Game.h"
#include "StickWood.h"
#include "GenericBlock.h"
#include "Pig.h"

DistanceJointDemo::DistanceJointDemo()
{
	pPig = nullptr;

	pBase = new GenericBlock(400, 180, 0, 75, 75, GameObjectName::Block, ImageName::Short_Stone_Block);
	pBase->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pBase, GameObjectName::MainGroup);

	pPlatform = new GenericBlock(400, 350, 0, 75, 20, GameObjectName::Block, ImageName::Long_Wood_Block);
	pPlatform->GetBody()->SetType(b2_dynamicBody);
	GameObjectMan::Add(pPlatform, GameObjectName::MainGroup);

	/*
	// Using the Initialize method (simpler)
	b2DistanceJointDef djdef;
	djdef.Initialize(pBase->GetBody(),
					 pPlatform->GetBody(),
					 pBase->GetBody()->GetWorldCenter(),		// given on world coord
					 pPlatform->GetBody()->GetWorldCenter()		// given on world coord
		);

	b2DistanceJoint* pMyJoint = (b2DistanceJoint*)Game::GetB2World()->CreateJoint(&djdef);
	pMyJoint;  // shutting up the compiler for demo
	//*/
	
	/*
	// Using a Joint Definition (more versatile/cleaner)
	b2DistanceJointDef djdef;
	djdef.bodyA = pBase->GetBody();
	djdef.bodyB = pPlatform->GetBody();
	djdef.localAnchorA = b2Vec2(0, 0);	// given in A's local coord
	djdef.localAnchorB = b2Vec2(0, 0);	// given in B's local coord
	//djdef.localAnchorB = b2Vec2(0.1f, 0);
	djdef.length = 3;

	djdef.frequencyHz = 1;			// 'strength' of the spring. keep < 30 
	//djdef.dampingRatio = .15f;		// how quickly to stop the oscillations.

	b2DistanceJoint* pMyJoint = (b2DistanceJoint*) Game::GetB2World()->CreateJoint(&djdef);
	
	pMyJoint;	// shutting up the compiler for demo
	//*/

	/*
	pPig = new Pig(400, 400, 0);
	GameObjectMan::Add( pPig, GameObjectName::BirdGroup);
	//*/
}

DistanceJointDemo::~DistanceJointDemo()
{
	if (pPig) GameObjectMan::Delete( pPig );
	GameObjectMan::Delete( pBase );
	GameObjectMan::Delete( pPlatform );

}
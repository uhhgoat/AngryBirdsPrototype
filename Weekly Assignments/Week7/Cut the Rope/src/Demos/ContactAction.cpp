#include "ContactAction.h"
#include "Box2D.h"
#include "BlockWoodLong.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"
#include "Bang.h"
#include "AudioManager.h"
#include "YellowBird.h"
#include "RedBird.h"
#include "Pig.h"

void ContactAction::ContactPair(RedBird& bird, BlockWoodLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird; 

	if (pImpulse)
	{
		NormalImpulseDamage(block, pImpulse);
	}
	else
	{
		ShowBang(pContact);
		AudioManager::BirdSquawk();
	}
}

void ContactAction::ContactPair(RedBird& bird, Pig& pig, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	pContact;
	pImpulse;
	bird.MarkForDelete();
	pig.MarkForDelete();
	DebugMsg::out("\n YOU WIN \n");
}

void ContactAction::ShowBang(b2Contact* pContact)
{
	//normal manifold contains all info...
	int numPoints = pContact->GetManifold()->pointCount;

	//...world manifold is helpful for getting locations
	b2WorldManifold worldManifold;
	pContact->GetWorldManifold(&worldManifold);

	DebugMsg::out("Drawing %i Bangs\n", numPoints);

	//draw collision points
	for (int i = 0; i < numPoints; i++)
	{
		Bang* pBang = new Bang(MeterToPixel(worldManifold.points[i].x), MeterToPixel(worldManifold.points[i].y), 0);
		GameObjectMan::Add(pBang, GameObjectName::EffectsGroup);
	}
}

void ContactAction::NormalImpulseDamage(BlockWoodLong& B, const b2ContactImpulse* pImpulse)
{
	for (int i = 0; i < pImpulse->count; i++)
	{
		DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);

		// Record Damage
		B.AddDamage(pImpulse->normalImpulses[i]);
	}
}

void ContactAction::ContactPair(YellowBird& bird, BlockWoodLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bird;

	bird.SetPointing(false);

	if (pImpulse)
	{
		NormalImpulseDamage(block, pImpulse);
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode())
		{
			pContact->SetEnabled(false);	// killed the other block's collision response
			block.AddDamage(10000);			// destroy the block (needs a better call method)
			ShowBang(pContact);				// Just for demo

											// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}

	}
}
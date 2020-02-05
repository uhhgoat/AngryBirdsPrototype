#include "ContactAction.h"
#include "Includes.h"

void ContactAction::ShowBang(b2Contact* pContact)
{
	//...world manifold is helpful for getting locations from local to World coord.
	b2WorldManifold worldManifold;
	pContact->GetWorldManifold(&worldManifold);

	float totalTime = Game::GetTotalTime();

	//draw collision points
	int numPoints = pContact->GetManifold()->pointCount;
	for (int i = 0; i < numPoints; i++)
	{
		DebugMsg::out("\tcontact #%d: %f %f  time: %f  \n",
			i,
			(float)MeterToPixel(worldManifold.points[i].x),
			(float)MeterToPixel(worldManifold.points[i].y),
			totalTime);

		// Sloppiest, most wasteful way to visualize these impact points...
		// This is just to illustrate the mechanism.
		GraphicsObject_Sprite *pGraphics_Sprite;
		Rect r = Rect(
			MeterToPixel(worldManifold.points[i].x),
			MeterToPixel(worldManifold.points[i].y),
			25, 25
		);
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Bang, r);
		GameObject2D *pBang = new GameObject2D(GameObjectName::Bang, pGraphics_Sprite);
		//GameObjectMan::Add(pBang, GameObjectName::MainGroup);
		GameObjectMan::Add(pBang, GameObjectName::EffectsGroup);
		pBang->MarkForDelete();


	}
}


//////////////////////////////////////////////////////////////////  RedBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(RedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if(totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 1250)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 1250)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 1250)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 1250)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RedBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 1250)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  BigRedBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(BigRedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if(totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();
		
	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BigRedBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  BlackBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(BlackBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlackBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  BlueBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(BlueBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 300)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 300)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 300)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 300)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 300)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(BlueBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  GreenBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(GreenBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(GreenBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  WhiteBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(WhiteBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 700)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(WhiteBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}

//////////////////////////////////////////////////////////////////  YellowBird  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(YellowBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage * 0.75f);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 600)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(YellowBird& bird, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
		if (totalImpulse > 200)
			AudioManager::BirdSquawk();

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 900)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			block.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}


//////////////////////////////////////////////////////////////////  BACKGROUND  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(Background& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, BigRedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, BlackBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, BlueBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GreenBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, RedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WhiteBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, YellowBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}


//////////////////////////////////////////////////////////////////  REGULARPIG  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(RegularPig& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(RegularPig& bg, BigRedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, BlackBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, BlueBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, GreenBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, RedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, WhiteBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, YellowBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(RegularPig& bg, Egg& egg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	egg;
}
void ContactAction::ContactPair(RegularPig& bg, Blast& blast, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	blast;
}


//////////////////////////////////////////////////////////////////  HELMETPIG  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(HelmetPig& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	block;
}
void ContactAction::ContactPair(HelmetPig& bg, BigRedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, BlackBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, BlueBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, GreenBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, RedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, WhiteBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, YellowBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		b2Vec2 vel = bird.GetBody()->GetLinearVelocity();
		float punchDamage = bird.GetBody()->GetMass() * vel.Length();
		bird.AddPunchDamage(punchDamage);

		if (bird.GetPunchMode() && punchDamage > 500)
		{
			pContact->SetEnabled(false);

			//CREATE DESTROY METHOD IN BLOCKS
			bg.TakeImpact(10000);
			ShowBang(pContact);

			// Slow the bird down by some factor
			bird.GetBody()->ApplyLinearImpulse(.5f *bird.GetBody()->GetMass() * (-vel), bird.GetBody()->GetWorldCenter(), true);
		}
	}
	bird.SetPointing(false);
}
void ContactAction::ContactPair(HelmetPig& bg, Egg& egg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	egg;
}
void ContactAction::ContactPair(HelmetPig& bg, Blast& blast, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			//DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		bg.TakeImpact(totalImpulse);

	}
	else
	{
		ShowBang(pContact);
	}
	blast;
}


//////////////////////////////////////////////////////////////////  BLAST  //////////////////////////////////////////////////////////////////



void ContactAction::ContactPair(Blast& bl, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag*5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bl.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	block.TakeImpact(mag * 5);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, Background& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bl;
	bg;
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bl, Platform& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bl;
	bg;
	pImpulse;
	pContact;
}



//////////////////////////////////////////////////////////////////  EGG  //////////////////////////////////////////////////////////////////



void ContactAction::ContactPair(Egg& egg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, Background& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	bg;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Egg& egg, Platform& bg, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	egg.Explode();
	bg;
	pContact;
	pImpulse;
}


//////////////////////////////////////////////////////////////////  PLATFORM  //////////////////////////////////////////////////////////////////


void ContactAction::ContactPair(Platform& bg, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, StoneBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, StoneBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, StoneBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockTiny& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WoodBlockSquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, GlassBlockTinySquare& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, GlassBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, StoneBlockMedThick& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, StoneCircle& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	block;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, BigRedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, BlackBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, BlueBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, GreenBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, RedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, WhiteBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Platform& bg, YellowBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird.SetPointing(false);
	pContact;
	pImpulse;
}
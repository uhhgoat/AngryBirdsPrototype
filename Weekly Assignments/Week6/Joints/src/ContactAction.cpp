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


	}
}

//RedBird
void ContactAction::ContactPair(RedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(RedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(RedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//BigRed bird
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BigRedBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BigRedBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//BlackBird
void ContactAction::ContactPair(BlackBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlackBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlackBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//BlueBird
void ContactAction::ContactPair(BlueBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlueBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(BlueBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//GreenBird
void ContactAction::ContactPair(GreenBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(GreenBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(GreenBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//WhiteBird
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(WhiteBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(WhiteBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
//YellowBird
void ContactAction::ContactPair(YellowBird& bird, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(YellowBird& bird, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
void ContactAction::ContactPair(YellowBird& bird, GlassBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	if (pImpulse)
	{
		// Accumulate Block Damage.
		float totalImpulse = 0;
		for (int i = 0; i < pImpulse->count; i++)
		{
			DebugMsg::out("\tPoint %i:\timpulse along normal = %f, \t along tangent = %f\n", i, pImpulse->normalImpulses[i], pImpulse->tangentImpulses[i]);
			totalImpulse += pImpulse->normalImpulses[i];
		}
		block.TakeImpact(totalImpulse);
	}
	else
	{
		ShowBang(pContact);
	}
	bird;
}
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
void ContactAction::ContactPair(Background& bg, BigRedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, BlackBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, BlueBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, GreenBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, RedBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, WhiteBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Background& bg, YellowBird& bird, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	bg;
	bird;
	pContact;
	pImpulse;
}
void ContactAction::ContactPair(Blast& bg, WoodBlockShort& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bg.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bg, WoodBlockMed& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bg.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	pImpulse;
	pContact;
}
void ContactAction::ContactPair(Blast& bg, WoodBlockLong& block, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	float mag = 300.0f;
	b2Vec2 pos = bg.GetBody()->GetWorldCenter();
	b2Vec2 otherPos = block.GetBody()->GetWorldCenter();
	b2Vec2 dir = (otherPos - pos);
	dir.Normalize();
	dir *= mag;
	block.GetBody()->ApplyLinearImpulse(dir, otherPos, true);
	pImpulse;
	pContact;
}
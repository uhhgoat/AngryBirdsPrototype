#include <assert.h>
#include "PixelToMeter.h"
#include "AzulStopWatch.h"
#include "GameObject2D.h"
#include "AngryContactListener.h"
#include "DebugOut.h"
#include "GameObjectMan.h"
#include "Game.h"

AngryContactListener::AngryContactListener()
	:b2ContactListener()
{
}

AngryContactListener::~AngryContactListener()
{

}

// Called when two fixtures begin to touch.
void AngryContactListener::BeginContact(b2Contact* pContact)
{
	GameObject2D *gObjA = (GameObject2D *)pContact->GetFixtureA()->GetUserData();
	GameObject2D *gObjB = (GameObject2D *)pContact->GetFixtureB()->GetUserData();


	gObjA->CollideAccept(*gObjB, pContact, nullptr);


	static int count = 0;
	//DebugMsg::out("------------- Contact Listener Call #%d:\n\tFrame Contacts:\n", count++);

	

}

// Called when two fixtures cease to touch.
void AngryContactListener::EndContact(b2Contact* contact)
{
	B2_NOT_USED(contact);

	//DebugMsg::out("End\n");
}

// This is called after a contact is updated. This allows you to inspect a
// contact before it goes to the solver. If you are careful, you can modify the
// contact manifold (e.g. disable contact).
// A copy of the old manifold is provided so that you can detect changes.
// Note: this is called only for awake bodies.
// Note: this is called even when the number of contact points is zero.
// Note: this is not called for sensors.
// Note: if you set the number of contact points to zero, you will not
// get an EndContact callback. However, you may get a BeginContact callback
// the next step.
void AngryContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{
	B2_NOT_USED(contact);
	B2_NOT_USED(oldManifold);
}

// This lets you inspect a contact after the solver is finished. This is useful
// for inspecting impulses.
// Note: the contact manifold does not include time of impact impulses, which can be
// arbitrarily large if the sub-step is small. Hence the impulse is provided explicitly
// in a separate data structure.
// Note: this is only called for contacts that are touching, solid, and awake.
void AngryContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{
	//DebugMsg::out("\tPostSolve: \n");
	GameObject2D* goHit1 = static_cast<GameObject2D*>(contact->GetFixtureA()->GetUserData());
	GameObject2D* goHit2 = static_cast<GameObject2D*>(contact->GetFixtureB()->GetUserData());
	goHit1->CollideAccept(*goHit2, contact, impulse);

	//...world manifold is helpful for getting locations
	b2WorldManifold worldManifold;
	contact->GetWorldManifold(&worldManifold);
	//DebugMsg::out("\tNormal vector (%f, %f)\n", worldManifold.normal.x, worldManifold.normal.y);
	
}

#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class BlackBird : public GameObject2D
{
private:

public:
	
	BlackBird(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~BlackBird() = default;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse)
	{
		other.CollideVisit(*this, contact, impulse);
	};
	virtual void CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

};
#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class Blast : public GameObject2D
{
private:
	int frames = 180;
public:

	Blast(float x, float y, float rot, b2World &world, bool showDebugShape = false);
	~Blast() = default;

	virtual void Update(float currentTume) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse)
	{
		
		other.CollideVisit(*this, contact, impulse);
		
	};
	virtual void CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

};
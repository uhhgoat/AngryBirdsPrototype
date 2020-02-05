#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class WoodBlockMed : public GameObject2D
{
private:
	int hitPoints;
public:
	WoodBlockMed(float x, float y, float rot, b2World &world);
	~WoodBlockMed() = default;
	virtual void TakeImpact(float damage) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse)
	{
		other.CollideVisit(*this, contact, impulse);
	};
	virtual void CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
};
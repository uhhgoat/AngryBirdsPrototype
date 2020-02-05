#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class Background : public GameObject2D
{
private:
	GameObject2D* floor;
public:
	Background();
	~Background() = default;
	Background(const Background&) = delete;
	Background& operator=(const Background&) = delete;

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

	virtual void CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
};
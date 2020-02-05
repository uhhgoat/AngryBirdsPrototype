#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class Platform : public GameObject2D, public AwakeListenerBase
{
private:

public:
	Platform(float x, float y, float rot);
	Platform() = default;
	~Platform() = default;
	Platform(const Platform&) = delete;
	Platform& operator=(const Platform&) = delete;

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
	virtual void CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse) override;


};
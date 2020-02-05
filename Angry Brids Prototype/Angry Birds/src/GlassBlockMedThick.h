#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class GlassBlockMedThick : public GameObject2D, public AwakeListenerBase
{
private:
	int hitPoints;
public:
	GlassBlockMedThick(float x, float y, float rot);
	GlassBlockMedThick() = default;
	~GlassBlockMedThick() = default;
	GlassBlockMedThick(const GlassBlockMedThick&) = delete;
	GlassBlockMedThick& operator=(const GlassBlockMedThick&) = delete;

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
	virtual void CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

	// Called when body is first awaken
	virtual void BeginAwake(b2Body* _body) override;

	// Called when body is first set to sleep
	virtual void EndAwake(b2Body* _body) override;

};
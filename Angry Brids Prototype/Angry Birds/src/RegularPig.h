#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
#include "Includes.h"
class RegularPig : public GameObject2D, public AwakeListenerBase
{
private:
	int hitPoints;
	Level* myLevel;
	int invincibility;
public:
	RegularPig(float x, float y, float rot);
	RegularPig() = default;
	~RegularPig() = default;
	RegularPig(const RegularPig&) = delete;
	RegularPig& operator=(const RegularPig&) = delete;

	virtual void TakeImpact(float damage) override;

	void SetLevel(Level* l);

	virtual void Update(float t) override;

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

	virtual void CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

	// Called when body is first awaken
	virtual void BeginAwake(b2Body* _body) override;

	// Called when body is first set to sleep
	virtual void EndAwake(b2Body* _body) override;

};
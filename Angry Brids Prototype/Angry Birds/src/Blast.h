#pragma once
#include "GameObject2D.h"
#include "FilterCategory.h"
class Blast : public GameObject2D
{
private:
	int frames = 60;
public:

	Blast(float x, float y, float rot, bool showDebugShape = false);
	Blast() = default;
	~Blast() = default;
	Blast(const Blast&) = delete;
	Blast& operator=(const Blast&) = delete;

	virtual void Update(float currentTume) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse)
	{
		
		other.CollideVisit(*this, contact, impulse);
		
	};
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
	virtual void CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse) override;
	virtual void CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

};
// BlockWoodLong
// Andre Berthiaume March 2016

#ifndef _BlockWoodLong
#define _BlockWoodLong

#include "GameObject2D.h"

class BlockWoodLong : public GameObject2D
{
public:
	BlockWoodLong() = delete;
	~BlockWoodLong();
	BlockWoodLong(const BlockWoodLong&) = delete;
	BlockWoodLong& operator=(const BlockWoodLong&) = delete;

	BlockWoodLong(float posx, float posy, float ang);

	void AddDamage(float d);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	//virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) override { DebugMsg::out("BlockWoodLong hit RedBird\n"); };
	virtual void CollideVisit(RedBird& other, b2Contact* pcontact, const b2ContactImpulse* pimpulse) override;

private:
	float DamageTotal;

	const float MAX_DAMAGE = 300;
};

#endif _BlockWoodLong

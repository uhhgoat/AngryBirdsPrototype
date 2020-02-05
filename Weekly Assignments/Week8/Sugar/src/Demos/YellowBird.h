// YellowBird
// Andre Berthiaume, May 2017

#ifndef _YellowBird
#define _YellowBird

#include "GameObject2D.h"
#include "TrailPuffFactory.h"
#include "ExplosionYellowFeathers.h"

class YellowBird : public GameObject2D
{
public: // hacky, but just for the demo
	TrailPuffFactory PuffFact;
	bool TrailOn;
	void KillTrail();

	ExplosionYellowFeathers ExplosionFeathers;

private:
	bool IsPointing;

	static const int MaxPunchImpulse = 200;
	float TotalPunchImpulse;
	bool PunchMode;
	
	int numShrapnel = 0;

public:
	YellowBird() = delete;
	~YellowBird() {};
	YellowBird(const YellowBird&) = delete;
	YellowBird& operator=(const YellowBird&) = delete;

	YellowBird(float posx, float posy, float ang);

	virtual void Update(float t) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	//virtual void CollideVisit(BlockWoodLong&, b2Contact*, const b2ContactImpulse*) { DebugMsg::out("RedBird hit BlockWoodLong\n"); };
	virtual void CollideVisit(BlockWoodLong&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(GenericBlock&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Shrapnel&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	void Move(float dx, float dy);

	void SetPointing(bool b) { this->IsPointing = b; }

	void AddPunchDamage(float d);
	bool GetPunchMode() { return PunchMode; }

	bool CollectShrapnel(Color::Type col);
};

#endif _YellowBird

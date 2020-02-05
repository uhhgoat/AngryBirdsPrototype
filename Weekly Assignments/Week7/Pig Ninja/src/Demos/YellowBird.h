// YellowBird
// Andre Berthiaume, May 2017

#ifndef _YellowBird
#define _YellowBird

#include "GameObject2D.h"

class YellowBird : public GameObject2D
{
private:
	bool IsPointing;

	static const int MaxPunchImpulse = 200;
	float TotalPunchImpulse;
	bool PunchMode;

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

	void Move(float dx, float dy);

	void SetPointing(bool b) { this->IsPointing = b; }

	void AddPunchDamage(float d);
	bool GetPunchMode() { return PunchMode; }
};

#endif _YellowBird

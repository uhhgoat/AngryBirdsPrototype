// Shrapnel
// Andre Berthiaume, May 2017

#ifndef _Shrapnel
#define _Shrapnel

#include "GameObject2D.h"

class ManagedPool;
class TerminateCallbackCmd;
class Pig;
class YellowBird;

class Shrapnel : public GameObject2D
{
private:
	ManagedPool* pPool;
	float speedMag;
	TerminateCallbackCmd* pTermCmd;
	Color::Type color;

public:
	Shrapnel() = delete;
	~Shrapnel();
	Shrapnel(const Shrapnel&) = delete;
	Shrapnel& operator=(const Shrapnel&) = delete;

	void SetPosAng(float wx, float wy, float ang);

	virtual void Update(float t) override;

	Shrapnel(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	virtual void CollideVisit(Pig&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(YellowBird&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(ColorFilter&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	Color::Type GetColor();
	void TurnGreen();

	virtual void ManagedSceneExit() override;

	void TerminateCallback();
};

#endif _Shrapnel
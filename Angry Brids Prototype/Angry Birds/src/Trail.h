#ifndef _Trail
#define _Trail

#include "GameObject2D.h"

class ManagedPool;

class Trail : public GameObject2D
{
private:
	ManagedPool * pPuffObjectPool;

public:
	Trail() = delete;
	~Trail() {};
	Trail(const Trail&) = delete;
	Trail& operator=(const Trail&) = delete;

	void SetPosAng(float pixx, float pixy, float ang);

	Trail(ManagedPool* pool);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };

	virtual void ManagedSceneExit() override;
};

#endif _YellowBird

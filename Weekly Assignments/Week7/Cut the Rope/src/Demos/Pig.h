// Pig
// Andre Berthiaume, Arpil 2017

#ifndef _Pig
#define _Pig

#include "GameObject2D.h"

class Pig : public GameObject2D
{
public:
	Pig() = delete;
	~Pig() {};
	Pig(const Pig&) = delete;
	Pig& operator=(const Pig&) = delete;

	Pig(float posx, float posy, float ang);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	virtual void CollideVisit(RedBird&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void Update(float t) override;
	float delta;
};


#endif _Pig

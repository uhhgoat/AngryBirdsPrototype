// Pig
// Andre Berthiaume, Arpil 2017

#ifndef _Pig
#define _Pig

#include "GameObject2D.h"

class Pig : public GameObject2D
{
private:

	int numShrapnel = 0;

public:
	Pig() = delete;
	~Pig() {};
	Pig(const Pig&) = delete;
	Pig& operator=(const Pig&) = delete;

	Pig(float posx, float posy, float ang);

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	virtual void CollideVisit(Shrapnel&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

	bool CollectShrapnel(Color::Type col);
};


#endif _Pig

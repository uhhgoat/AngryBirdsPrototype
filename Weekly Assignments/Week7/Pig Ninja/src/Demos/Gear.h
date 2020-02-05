// Gear
// Andre Berthiaume, April 2017

#ifndef _Gear
#define _Gear

#include "GameObject2D.h"


class Gear : public GameObject2D
{
public:
	Gear() = delete;
	virtual ~Gear() = default;
	Gear(const Gear&) = delete;
	Gear& operator=(const Gear&) = delete;

	Gear(float posx, float posy, float ang, float rad, GameObjectName::Name objname, ImageName::Name imgname );


	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other.CollideVisit(*this, contact, pimpulse); };

};


#endif _Gear

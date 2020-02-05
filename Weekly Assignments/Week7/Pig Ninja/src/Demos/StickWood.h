// StickWood
// Andre Berthiaume March 2016

#ifndef _StickWoodMedium
#define _StickWoodMedium

#include "GameObject2D.h"

class StickWood : public GameObject2D
{
public:
	StickWood() = delete;
	StickWood(const StickWood&) = delete;
	StickWood& operator=(const StickWood&) = delete;

	StickWood(float posx, float posy, float ang, float w, float h);


	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other.CollideVisit(*this, contact, pimpulse); };
};

#endif _StickWoodMedium

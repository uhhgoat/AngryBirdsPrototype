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

	virtual void Update(float t) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other.CollideVisit(*this, contact, pimpulse); };
	virtual void SetJoint(b2RevoluteJoint* joint) override { rjdef = joint; };
	virtual b2RevoluteJoint* GetJoint() override { return rjdef; };
private:
	b2RevoluteJoint* rjdef;
};

#endif _StickWoodMedium

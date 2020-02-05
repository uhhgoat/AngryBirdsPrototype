#pragma once
#include "GameObject2D.h"
class ColorFilter : public GameObject2D
{
private:
	int frames = 180;
public:

	ColorFilter(float posx, float posy, float ang);
	~ColorFilter() = default;

	virtual void Update(float currentTume) override;

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse)
	{
		other.CollideVisit(*this, contact, impulse);
	};
	virtual void CollideVisit(Shrapnel& other, b2Contact* contact, const b2ContactImpulse* impulse) override;

};
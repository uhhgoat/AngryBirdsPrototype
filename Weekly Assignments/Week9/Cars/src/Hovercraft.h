#ifndef _Hovercraft
#define _Hovercraft

#include "GameObject2D.h"
#include "Box2D.h"

class Hovercraft : public GameObject2D, public b2RayCastCallback
{
private:
	float Acceleration;
	float HoverHeight;
	float SpringConstant;
	const float MaxSpeed = 15;

	bool GroundDetected;
	b2Vec2 GroundPoint;

public:
	Hovercraft() = delete;
	virtual ~Hovercraft() = default;
	Hovercraft(const Hovercraft&) = delete;
	Hovercraft& operator=(const Hovercraft&) = delete;

	Hovercraft(float posx, float posy);

	virtual void Update(float t) override;

	virtual float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;


};


#endif _Hovercraft
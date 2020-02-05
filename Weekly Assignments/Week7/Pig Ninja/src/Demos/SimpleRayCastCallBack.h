// SimpleRayCastCallBack
// Andre Berthiaume, May 2017

#ifndef _SimpleRayCastCallBack
#define _SimpleRayCastCallBack

#include "Box2D.h"
#include <list>

class SimpleRayCastCallBack : public b2RayCastCallback
{
public:
	virtual float32 ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction) override;

	void ClearList();
	void ProcessList();

private:
	using ListFixtures = std::list<b2Fixture*>;
	ListFixtures lstFixtures;

};

#endif _SimpleRayCastCallBack
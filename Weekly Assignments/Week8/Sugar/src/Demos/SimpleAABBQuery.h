// SimpleAABBQuery
// Andre Berthiaume, May 2017

#ifndef _SimpleAABBQuery
#define _SimpleAABBQuery

#include "Box2D.h"
#include <list>
#include "Color.h"

class GraphicsObject_Box;

class SimpleAABBQuery : public b2QueryCallback
{
public: 
	SimpleAABBQuery();
	~SimpleAABBQuery();

	virtual bool ReportFixture(b2Fixture* fixture) override;

	void ClearList();
	void ProcessList();

private:
	using ListFixtures = std::list<b2Fixture*>;
	ListFixtures lstFixtures;

	GraphicsObject_Box* pbox;
};

#endif _SimpleAABBQuery


#include "SimpleAABBQuery.h"

#include "GraphicsObject_Box.h"
#include "GameObject2D.h"
#include "PixelToMeter.h"
#include "DebugOut.h"

#include "Visualizer.h"

SimpleAABBQuery::SimpleAABBQuery()
{
	pbox = new GraphicsObject_Box(Rect(0, 0, 1, 1));
}

SimpleAABBQuery::~SimpleAABBQuery()
{
	delete pbox;
}

bool SimpleAABBQuery::ReportFixture(b2Fixture* fixture)
{
	lstFixtures.push_front(fixture);

	/*
	// Debug to inspect the gap issue
	b2AABB ab = (*lstFixtures.begin())->GetAABB(0);
	//*/

	return true;
}

void SimpleAABBQuery::ClearList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* potherbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		potherbox->color = Color::Type::Yellow;
	}

	lstFixtures.clear();

	// Clearing the Visualizer's AABB
	Visualizer::ClearAABBs();

}

void SimpleAABBQuery::ProcessList()
{
	for (ListFixtures::iterator it = lstFixtures.begin(); it != lstFixtures.end(); it++)
	{
		GameObject2D* pgobj = (GameObject2D*)((*it)->GetUserData());
		GraphicsObject_Box* potherbox = (GraphicsObject_Box*)pgobj->getGraphicsObject_Collision();
		potherbox->color = Color::Type::Red;

		// Making the AABB visible for demo
		b2AABB ab = pgobj->GetBody()->GetFixtureList()->GetAABB(0);
		Visualizer::AddAABB(ab, Color::Type::Black);
	}
}


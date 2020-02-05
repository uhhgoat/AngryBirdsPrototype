// TrailPuffFactory
// Andre Berthiaume, May 2017

#ifndef _TrailPuffFactory
#define _TrailPuffFactory

#include "ManagedPool.h"
#include "Box2D.h"

class TrailPuff;
class GameSortBucket;

class TrailPuffFactory : public ManagedPool
{
public:
	TrailPuffFactory();
	virtual ~TrailPuffFactory();
	TrailPuffFactory(const TrailPuffFactory&) = delete;
	TrailPuffFactory& operator=(const TrailPuffFactory&) = delete;

	void Create( float pixx, float pixy, float ang);

	void RecallTrail();

private:
	GameObjectName::Name SortName;
	GameSortBucket* pSort;

	virtual GameObject2D* CreateNew() override;
};

#endif _TrailPuffFactory
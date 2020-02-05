#ifndef _TrailFactory
#define _TrailFactory

#include "ManagedPool.h"
#include "Box2D.h"

class Trail;
class GameSortBucket;

class TrailFactory : public ManagedPool
{
public:
	TrailFactory();
	virtual ~TrailFactory();
	TrailFactory(const TrailFactory&) = delete;
	TrailFactory& operator=(const TrailFactory&) = delete;

	Trail* Create(float pixx, float pixy, float ang, float scale = 1.0f);

	void RecallTrail();

private:
	GameObjectName::Name SortName;
	GameSortBucket* pSort;

	virtual GameObject2D* CreateNew() override;
};

#endif _TrailFactory
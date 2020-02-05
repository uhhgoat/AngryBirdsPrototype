#ifndef _ManagedPool
#define _ManagedPool

#include "GameObjectName.h"
#include "MFStack.h"

class GameObject2D;

class ManagedPool
{
public:
	ManagedPool();
	virtual ~ManagedPool();
	ManagedPool(const ManagedPool&) = delete;
	ManagedPool& operator=(const ManagedPool&) = delete;

	// to return an object back to the pool
	void Recycle(GameObject2D* pEnt);

protected:
	MFStack pRecycledPool;
	MFStack pEmptyContainers;

	// To request a new object from the pool
	GameObject2D* GetNew();

private:
	// How to create a new ABEntity (when no old ones available)
	virtual GameObject2D* CreateNew() = 0;
};


#endif _ManagedPool

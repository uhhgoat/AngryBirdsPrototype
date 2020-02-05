// ExplosionShrapnel
// Andre Berthiaume

#ifndef _ExplosionShrapnel
#define _ExplosionShrapnel

#include "ManagedPool.h"
class CreateShrapnelCmd;

class ExplosionShrapnel : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;
	CreateShrapnelCmd* pShrapCmd;
public:
	ExplosionShrapnel() {};
	virtual ~ExplosionShrapnel() {};
	ExplosionShrapnel(const ExplosionShrapnel&) = delete;
	ExplosionShrapnel& operator=(const ExplosionShrapnel&) = delete;

	void Create(float wx, float wy);

	// Note: missing stuff to add
	// - recall live shrapnel and 
	// - delete may leak if feathers sill active
};


#endif _ExplosionShrapnel

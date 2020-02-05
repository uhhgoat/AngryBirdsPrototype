// ExplosionYellowFeathers
// Andre Berthiaume, May 2017

#ifndef _ExplosionYellowFeathers
#define _ExplosionYellowFeathers

#include "ManagedPool.h"

class FeatherYellow;
class GameObject2D;

class ExplosionYellowFeathers : public ManagedPool
{
private:
	virtual GameObject2D* CreateNew() override;

public:
	ExplosionYellowFeathers() = default;
	virtual ~ExplosionYellowFeathers() = default;
	ExplosionYellowFeathers(const ExplosionYellowFeathers&) = delete;
	ExplosionYellowFeathers& operator=(const ExplosionYellowFeathers&) = delete;

	void Create(float pixx, float pixy);

	// Note: missing stuff to add
	// - recall live feathers and 
	// - delete may leak if feathers sill active
};


#endif _ExplosionYellowFeathers

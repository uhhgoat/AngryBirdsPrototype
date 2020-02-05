#include "ExplosionYellowFeathers.h"
#include "FeatherYellow.h"
#include "GameObjectMan.h"

GameObject2D* ExplosionYellowFeathers:: CreateNew()
{
	return new FeatherYellow(this);
}

void ExplosionYellowFeathers::Create(float pixx, float pixy)
{
	FeatherYellow* p;
	
	for (int i = 0; i < 5; i++)
	{
		p = (FeatherYellow*) this->GetNew();
		p->SetPosAng(pixx, pixy);

		GameObjectMan::Add(p, GameObjectName::EffectsGroup);
	}
}
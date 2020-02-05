#include "ExplosionShrapnel.h"
#include "Shrapnel.h"
#include "GameObjectMan.h"
#include "CreateShrapnelCmd.h"
#include "TimerMan.h"

GameObject2D* ExplosionShrapnel::CreateNew()
{
	return new Shrapnel(this);
}

void ExplosionShrapnel::Create(float pixx, float pixy)
{
	pShrapCmd = new CreateShrapnelCmd(this, pixx, pixy);
	Shrapnel* p;

	//int count = 30;
	//float angStep = MATH_2PI / count;
	
	//for (int i = 0; i < count; i++)
	//{
	//	p = (Shrapnel*) this->GetNew();
	//	p->SetPosAng(pixx, pixy, i * angStep);
	//	GameObjectMan::Add(p, GameObjectName::EffectsGroup);
	//}
	p = (Shrapnel*)this->GetNew();
	p->SetPosAng(pixx, pixy, 0);
	GameObjectMan::Add(p, GameObjectName::EffectsGroup);
	TimerMan::AddEvent(0.05f, pShrapCmd);
}

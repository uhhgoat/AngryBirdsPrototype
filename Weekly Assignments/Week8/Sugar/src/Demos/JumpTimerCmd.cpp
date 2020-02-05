#include "JumpTimerCmd.h"
#include "Box2D.h"
#include "GameObject2D.h"
#include "TimerMan.h"

JumpTimerCmd::JumpTimerCmd(GameObject2D* pObj)
{
	this->pGo2d = pObj;
}

void JumpTimerCmd::Execute(float currTime) 
{
	currTime;

	b2Body* body = pGo2d->GetBody();

	// Give the bird a slight kick upwards
	b2Vec2 unitVect(0.0f, 1.0f);
	float accel = 3.0f;
	b2Vec2 imp = body->GetMass() * accel * unitVect;
	b2Vec2 appPoint = body->GetWorldCenter();

	body->ApplyLinearImpulse(imp, appPoint, true);
	body->SetActive(true);

	// We want to repeat this command
	TimerMan::AddEvent(4.0f, this);
}
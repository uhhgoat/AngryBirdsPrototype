#ifndef _CreateShrapnelCmd
#define _CreateShrapnelCmd

#include <assert.h>
#include "TimerEvent.h"
#include "Demos/ExplosionShrapnel.h"
#include "TimerMan.h"
#include "DebugOut.h"

class CreateShrapnelCmd : public TimerEvent
{
private:
	ExplosionShrapnel * pEnt;
	float myX;
	float myY;

public:
	CreateShrapnelCmd(ExplosionShrapnel* pEn, float x, float y)
	{
		this->pEnt = pEn;
		this->myX = x;
		this->myY = y;
	}

	virtual void Execute(float currTime) override
	{
		currTime;

		pEnt->Create(myX, myY);
	}
};

#endif _CreateShrapnelCmd


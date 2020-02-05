// TerminateCallbackCmd
// Andre Berthiaume, May 2017

#ifndef _TerminateCallbackCmd
#define _TerminateCallbackCmd

#include <assert.h>
#include "TimerEvent.h"
#include "Shrapnel.h"
#include "TimerMan.h"
#include "DebugOut.h"

class TerminateCallbackCmd : public TimerEvent
{
private:
	Shrapnel* pEnt;

public:
	TerminateCallbackCmd(Shrapnel* pEn)
	{
		this->pEnt = pEn;
	}

	virtual void Execute(float currTime) override
	{
		currTime;

		pEnt->TerminateCallback();
	}
};

#endif _TerminateCallbackCmd


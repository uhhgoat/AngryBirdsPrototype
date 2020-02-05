// SpriteChangeTimerCmd
// Andre Berhtiaume, May 2017

#ifndef _SpriteChangeTimerCmd
#define _SpriteChangeTimerCmd

#include "TimerEvent.h"
#include "RedBird.h"
#include "TimerMan.h"

class SpriteChangeTimerCmd : public TimerEvent
{
private:
	RedBird *pBird;		// Should really be a base class for all sprite changing entities

public:
	SpriteChangeTimerCmd(RedBird *pObj);

	virtual void Execute(float currTime) override;
};


#endif _SpriteChangeTimerCmd

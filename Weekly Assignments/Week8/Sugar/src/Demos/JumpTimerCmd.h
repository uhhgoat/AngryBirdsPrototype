// JumpTimerCmd
// AB 4/18
// 
#ifndef _EventJump
#define _EventJump

#include "TimerEvent.h"

class GameObject2D;

class JumpTimerCmd : public TimerEvent
{
private:
	GameObject2D* pGo2d;

public:
	JumpTimerCmd(GameObject2D* pObj);

	virtual void Execute(float currTime) override;
};



#endif _EventJump
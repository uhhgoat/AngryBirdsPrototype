#pragma once
#include "Time.h"
#include "Timer.h"
#include "TimerEvent.h"
#include "TimerMan.h"

class LaunchTimerCmd : public TimerEvent
{
	virtual void Execute(float currTime) override;
};
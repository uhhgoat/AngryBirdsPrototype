#ifndef TIMER_EVENT_H
#define TIMER_EVENT_H

class TimerLink
{
public:
	TimerLink()
		:next(0), prev(0)
	{

	}

	TimerLink *next;
	TimerLink *prev;
};


class TimerEvent : public TimerLink
{
public:
	virtual void Execute(float currTime) = 0;

	float TriggerTime;
};


#endif
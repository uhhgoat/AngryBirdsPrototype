#ifndef TIMER_MAN_H
#define TIMER_MAN_H

#include "TimerEvent.h"

class TimerMan
{
private:
	static TimerMan* ptrInstance;

	TimerMan();
	~TimerMan();
	TimerMan(const TimerMan&) = delete;
	TimerMan& operator=(const TimerMan&) = delete;

	static TimerMan& Instance()
	{
		if (!ptrInstance)
			ptrInstance = new TimerMan();

		return *ptrInstance;
	}

public:
	static void AddEvent(float TimeInSec, TimerEvent *pEvent);
	static void RemoveEvent(TimerEvent *pEvent);
	static void Update();
	static void Terminate() { delete ptrInstance; }

private:
	void privAddToFront(TimerEvent *pEvent);
	void privRemoveFromList(TimerEvent *pEvent);
	TimerEvent *pHead;
	float currTime;
};



#endif
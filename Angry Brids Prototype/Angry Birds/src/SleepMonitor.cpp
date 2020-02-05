#include "SleepMonitor.h"
#include "Box2D.h"
#include "DebugOut.h"

SleepMonitor* SleepMonitor::ptrInstance = nullptr;

SleepMonitor::SleepMonitor()
{
	currAwakeCount = 0;
	AllSleep = false;
}

bool SleepMonitor::isEveryoneAsleep()
{
	// If true, report only once
	bool ans = Instance().AllSleep;
	Instance().AllSleep = false;
	return ans;
}

void SleepMonitor::ReportWakeState(b2Body* _pbod)
{
	Instance().privReportWakeState(_pbod);
}

void SleepMonitor::privReportWakeState(b2Body* _pbod)
{
	if (_pbod->IsAwake())
	{
		currAwakeCount++;
	}
	else
	{
		currAwakeCount--;
	}

	// AllSleep toggle
	AllSleep = (!AllSleep) && (currAwakeCount == 0);

	//if (! Instance().AllSleep)
	DebugMsg::out("Awake count: %i\n", Instance().currAwakeCount);
}


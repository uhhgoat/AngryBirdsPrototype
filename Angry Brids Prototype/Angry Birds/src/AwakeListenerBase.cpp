#include "AwakeListenerBase.h"

AwakeListenerBase::AwakeListenerBase()
{
	currState = WakeState::AWAKE;
}

void AwakeListenerBase::TriggerCallback(b2Body* _pBod)
{
	bool BodyAwake = _pBod->IsAwake();

	if (BodyAwake && currState == WakeState::ASLEEP)
	{   // Transition from sleep to awake
		currState = WakeState::AWAKE;
		BeginAwake(_pBod);
	}
	else if (!BodyAwake && currState == WakeState::AWAKE)
	{   // transition from awake to asleep
		currState = WakeState::ASLEEP;
		EndAwake(_pBod);
	}
}
#ifndef _AwakeListenerBase
#define _AwakeListenerBase

#include "AwakeListenerEmpty.h"

#include "Box2D.h"

class AwakeListenerBase : public AwakeListenerEmpty
{
	friend class GameObject2D;
private:
	enum WakeState { ASLEEP, AWAKE };
	WakeState currState;

	// Now the Trigger performs a real action
	virtual void TriggerCallback(b2Body* _pBod) final;

public:
	AwakeListenerBase();
	virtual ~AwakeListenerBase() = default;

	AwakeListenerBase(const AwakeListenerBase&) = delete;
	AwakeListenerBase& operator=(const AwakeListenerBase&) = delete;

	// Called when body is first awaken
	virtual void BeginAwake(b2Body* _body)
	{
		_body;
	};

	// Called when body is first set to sleep
	virtual void EndAwake(b2Body* _body)
	{
		_body;
	};
};

#endif _b2ModAwakeListener

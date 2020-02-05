#include "LaunchTimerCmd.h"
#include  "Demos/RedBird.h"
#include  "Demos/Pig.h"
#include "GameObjectMan.h"

void LaunchTimerCmd::Execute(float currTime)
{
	currTime;
	float xStart = (float)(rand() % 500 + 200);
	int odds = rand() % 100;
	if (odds > 75)
	{
		
		GameObjectMan::Add(new RedBird(xStart, -50, 0), GameObjectName::BirdGroup);
	}
	else
	{
		GameObjectMan::Add(new Pig(xStart, -50, 0), GameObjectName::BirdGroup);
	}
	
	float nextTimer = (rand() % 10) / 8.0f;

	TimerMan::AddEvent(nextTimer, this);
}
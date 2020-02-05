#include "Level.h"
#include "AudioManager.h"

void Level::ReportDeadPig()
{
	numPigs--;
	if (numPigs <= 0)
	{
		AudioManager::Win();
	}
}

void Level::ReportAddPig()
{
	numPigs++;
}
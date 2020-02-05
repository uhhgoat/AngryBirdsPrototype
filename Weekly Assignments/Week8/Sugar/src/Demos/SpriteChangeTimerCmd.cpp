#include "SpriteChangeTimerCmd.h"

SpriteChangeTimerCmd::SpriteChangeTimerCmd(RedBird *pObj)
{
	this->pBird = pObj;
}

void SpriteChangeTimerCmd::Execute(float currTime) 
{
	currTime;
	pBird->NextSprite();
}
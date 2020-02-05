#include "Trail.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "TrailFactory.h"

Trail::Trail(ManagedPool* pool)
	: GameObject2D(
		GameObjectName::Trail,
		new GraphicsObject_Sprite(ImageName::Trail, Rect(0, 0, 15, 15))
	)
{
	this->currAngle = 0;
	this->SetDrawSprite(true);

	this->pBody = nullptr;

	this->ManagedNoDelete = true;
	this->pPuffObjectPool = pool;
}

void Trail::SetPosAng(float pixx, float pixy, float ang)
{
	this->posX = pixx;
	this->posY = pixy;
	this->origAngle = ang;
}

void Trail::ManagedSceneExit()
{
	pPuffObjectPool->Recycle(this);
}
#include "TrailPuff.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "TrailPuffFactory.h"

TrailPuff::TrailPuff(ManagedPool* pool)
	: GameObject2D(
		GameObjectName::TrailPuff,
		new GraphicsObject_Sprite(ImageName::TrailPuff, Rect(0, 0, 15, 15))
	)
{
	this->currAngle = 0;
	this->SetDrawSprite(true);

	this->pBody = nullptr;	

	this->ManagedNoDelete = true;
	this->pPuffObjectPool = pool;
}

void TrailPuff::SetPosAng(float pixx, float pixy, float ang)
{
	this->posX = pixx;
	this->posY = pixy;
	this->origAngle = ang;
}

void TrailPuff::ManagedSceneExit()
{
	pPuffObjectPool->Recycle(this);
}
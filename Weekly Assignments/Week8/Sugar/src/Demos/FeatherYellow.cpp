#include "FeatherYellow.h"
#include "ManagedPool.h"
#include "GameObjectMan.h"
#include "TimerMan.h"
#include "Matrix.h"

FeatherYellow::FeatherYellow(ManagedPool* pool)
	: pPool(pool),
	GameObject2D(
		GameObjectName::FeatherYellow,
		new GraphicsObject_Sprite(ImageName::FeatherYellow, Rect(0, 0, 15, 45))
	)
{
	this->currAngle = 0;
	this->SetDrawDebug(false);
	this->SetDrawSprite(true);
	this->pBody = nullptr;
	this->ManagedNoDelete = true;

	ScaleFactor = .97f;
	this->speedang = .1f;
	this->speedMag = .51f;
}

FeatherYellow::~FeatherYellow()
{

}

void FeatherYellow::Update(float t)
{
	this->posX += speedx;
	this->posY += speedy;
	this->currAngle += speedang;
	this->scaleX *= ScaleFactor;
	this->scaleY *= ScaleFactor;

	if (this->scaleX <= .1f)
	{
		this->MarkForDelete();
	}

	GameObject2D::Update(t);
}

void FeatherYellow::SetPosAng(float pixx, float pixy)
{
	this->posX = pixx;
	this->posY = pixy;

	// randomize direction
	float ang = (rand() % 360) * MATH_PI_180;
	Matrix Rot(ROT_Z, ang);
	Vect dir = speedMag * Vect(1,0,0) * Rot;

	// Note: Non-physical movement!  Much cheaper!
	this->origAngle = ang;
	this->speedx = dir[x];
	this->speedy = dir[y];

	this->scaleX = 1;
	this->scaleY = 1;
}


void FeatherYellow::ManagedSceneExit()
{
	pPool->Recycle(this);
}

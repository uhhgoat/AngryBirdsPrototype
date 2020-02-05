#include "Bang.h"

Bang::Bang(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::Bang,
		new GraphicsObject_Sprite(ImageName::Bang, Rect(posx, posy, 25, 25))
	)
{
	this->currAngle = ang;
}


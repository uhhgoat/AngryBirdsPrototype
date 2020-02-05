#include "BigRedBird.h"


BigRedBird::BigRedBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::BigRedBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BigRedBird, Rect(x, y, 150, 150));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 150, 150)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

BigRedBird::BigRedBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::BigRedBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BigRedBird, Rect(x, y, 150, 150));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 150, 150)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void BigRedBird::AddScale(float s)
//{
//}
//float BigRedBird::GetScale()
//{
//}
//void BigRedBird::Rotate(float a)
//{
//
//}
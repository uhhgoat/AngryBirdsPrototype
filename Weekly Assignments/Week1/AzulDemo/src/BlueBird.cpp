#include "BlueBird.h"


BlueBird::BlueBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::BlueBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlueBird, Rect(x, y, 50, 50));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 50, 50)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

BlueBird::BlueBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::BlueBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlueBird, Rect(x, y, 50, 50));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 50, 50)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void BlueBird::AddScale(float s)
//{
//}
//float BlueBird::GetScale()
//{
//}
//void BlueBird::Rotate(float a)
//{
//
//}
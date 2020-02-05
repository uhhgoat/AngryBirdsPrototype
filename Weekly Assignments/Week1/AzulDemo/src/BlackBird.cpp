#include "BlackBird.h"


BlackBird::BlackBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::BlackBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlackBird, Rect(x, y, 125, 150));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 125, 150)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

BlackBird::BlackBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::BlackBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlackBird, Rect(x, y, 125, 150));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 125, 150)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void BlackBird::AddScale(float s)
//{
//}
//float BlackBird::GetScale()
//{
//}
//void BlackBird::Rotate(float a)
//{
//
//}
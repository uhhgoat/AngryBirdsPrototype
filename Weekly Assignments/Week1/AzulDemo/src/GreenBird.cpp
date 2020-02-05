#include "GreenBird.h"


GreenBird::GreenBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::GreenBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GreenBird, Rect(x, y, 175, 140));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 175, 140)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

GreenBird::GreenBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::GreenBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GreenBird, Rect(x, y, 175, 140));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 175, 140)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void GreenBird::AddScale(float s)
//{
//}
//float GreenBird::GetScale()
//{
//}
//void GreenBird::Rotate(float a)
//{
//
//}
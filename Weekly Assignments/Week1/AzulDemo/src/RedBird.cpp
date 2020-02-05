#include "RedBird.h"


RedBird::RedBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::RedBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::RedBird, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

RedBird::RedBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::RedBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::RedBird, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void RedBird::AddScale(float s)
//{
//}
//float RedBird::GetScale()
//{
//}
//void RedBird::Rotate(float a)
//{
//
//}
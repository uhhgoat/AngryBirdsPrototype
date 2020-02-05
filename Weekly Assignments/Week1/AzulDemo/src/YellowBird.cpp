#include "YellowBird.h"


YellowBird::YellowBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::YellowBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::YellowBird, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

YellowBird::YellowBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::YellowBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::YellowBird, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void YellowBird::AddScale(float s)
//{
//}
//float YellowBird::GetScale()
//{
//}
//void YellowBird::Rotate(float a)
//{
//
//}
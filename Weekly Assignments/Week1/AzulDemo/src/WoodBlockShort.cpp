#include "WoodBlockShort.h"


WoodBlockShort::WoodBlockShort(float x, float y, float rot)
	:GameObject2D(GameObjectName::WoodBlockShort)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WoodBlockShort, Rect(x, y, 200, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 200, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void WoodBlockShort::AddScale(float s)
//{
//}
//float WoodBlockShort::GetScale()
//{
//}
//void WoodBlockShort::Rotate(float a)
//{
//
//}
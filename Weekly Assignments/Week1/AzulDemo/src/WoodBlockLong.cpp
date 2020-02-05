#include "WoodBlockLong.h"


WoodBlockLong::WoodBlockLong(float x, float y, float rot)
	:GameObject2D(GameObjectName::WoodBlockLong)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WoodBlockLong, Rect(x, y, 500, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 500, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void WoodBlockLong::AddScale(float s)
//{
//}
//float WoodBlockLong::GetScale()
//{
//}
//void WoodBlockLong::Rotate(float a)
//{
//
//}
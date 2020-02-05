#include "WoodBlockMed.h"


WoodBlockMed::WoodBlockMed(float x, float y, float rot)
	:GameObject2D(GameObjectName::WoodBlockMed)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WoodBlockMed, Rect(x, y, 400, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 400, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void WoodBlockMed::AddScale(float s)
//{
//}
//float WoodBlockMed::GetScale()
//{
//}
//void WoodBlockMed::Rotate(float a)
//{
//
//}
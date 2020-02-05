#include "GlassBlockLong.h"


GlassBlockLong::GlassBlockLong(float x, float y, float rot)
	:GameObject2D(GameObjectName::GlassBlockLong)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockLong, Rect(x, y, 500, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 500, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void GlassBlockLong::AddScale(float s)
//{
//}
//float GlassBlockLong::GetScale()
//{
//}
//void GlassBlockLong::Rotate(float a)
//{
//
//}
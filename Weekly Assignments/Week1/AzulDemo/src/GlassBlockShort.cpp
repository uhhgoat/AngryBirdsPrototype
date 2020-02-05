#include "GlassBlockShort.h"


GlassBlockShort::GlassBlockShort(float x, float y, float rot)
	:GameObject2D(GameObjectName::GlassBlockShort)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockShort, Rect(x, y, 200, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 200, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void GlassBlockShort::AddScale(float s)
//{
//}
//float GlassBlockShort::GetScale()
//{
//}
//void GlassBlockShort::Rotate(float a)
//{
//
//}
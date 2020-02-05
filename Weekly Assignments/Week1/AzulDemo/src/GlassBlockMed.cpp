#include "GlassBlockMed.h"


GlassBlockMed::GlassBlockMed(float x, float y, float rot)
	:GameObject2D(GameObjectName::GlassBlockMed)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockMed, Rect(x, y, 400, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 400, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

//void GlassBlockMed::AddScale(float s)
//{
//}
//float GlassBlockMed::GetScale()
//{
//}
//void GlassBlockMed::Rotate(float a)
//{
//
//}
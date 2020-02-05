#include "KingPig.h"


KingPig::KingPig(float x, float y, float rot)
	:GameObject2D(GameObjectName::KingPig)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::KingPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

KingPig::KingPig(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::KingPig)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::KingPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void KingPig::AddScale(float s)
//{
//}
//float KingPig::GetScale()
//{
//}
//void KingPig::Rotate(float a)
//{
//
//}
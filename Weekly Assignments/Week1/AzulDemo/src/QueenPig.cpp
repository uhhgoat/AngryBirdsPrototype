#include "QueenPig.h"


QueenPig::QueenPig(float x, float y, float rot)
	:GameObject2D(GameObjectName::QueenPig)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::QueenPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

QueenPig::QueenPig(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::QueenPig)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::QueenPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void QueenPig::AddScale(float s)
//{
//}
//float QueenPig::GetScale()
//{
//}
//void QueenPig::Rotate(float a)
//{
//
//}
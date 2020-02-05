#include "WhiteBird.h"


WhiteBird::WhiteBird(float x, float y, float rot)
	:GameObject2D(GameObjectName::WhiteBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WhiteBird, Rect(x, y, 150, 160));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 150, 160)));
	SetDrawDebug(false);
	SetDrawSprite(true);
}

WhiteBird::WhiteBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::WhiteBird)
{
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WhiteBird, Rect(x, y, 150, 160));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	posX = x;
	posY = y;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 150, 160)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);
}

//void WhiteBird::AddScale(float s)
//{
//}
//float WhiteBird::GetScale()
//{
//}
//void WhiteBird::Rotate(float a)
//{
//
//}
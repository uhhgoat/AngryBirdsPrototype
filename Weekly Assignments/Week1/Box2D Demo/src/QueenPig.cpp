#include "QueenPig.h"


QueenPig::QueenPig(float x, float y, float rot, b2World &world)
	:GameObject2D(GameObjectName::QueenPig)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::QueenPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(false);
	SetDrawSprite(true);
	
	//BOX2D STUFF
	// Body Def
	b2BodyDef BirdDef;
	BirdDef.type = b2_dynamicBody;
	BirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BirdDef.angle = currAngle;

	// Body
	b2Body *pBirdBody = world.CreateBody(&BirdDef);

	// Shape
	b2PolygonShape BirdBox;
	BirdBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 10.0f;
	BirdFixtureDef.friction = 0.3f;
	BirdFixtureDef.restitution = 0.50f;
	BirdFixtureDef.userData = this;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);
}

QueenPig::QueenPig(float x, float y, float rot, bool showDebugShape, b2World &world)
	:GameObject2D(GameObjectName::QueenPig)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::QueenPig, Rect(x, y, 300, 300));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 300, 300)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);

	//BOX2D STUFF
	// Body Def
	b2BodyDef BirdDef;
	BirdDef.type = b2_dynamicBody;
	BirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BirdDef.angle = currAngle;

	// Body
	b2Body *pBirdBody = world.CreateBody(&BirdDef);

	// Shape
	b2PolygonShape BirdBox;
	BirdBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 10.0f;
	BirdFixtureDef.friction = 0.3f;
	BirdFixtureDef.restitution = 0.50f;
	BirdFixtureDef.userData = this;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);
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
#include "BlueBird.h"




BlueBird::BlueBird(float x, float y, float rot, b2World &world, bool showDebugShape)
	:GameObject2D(GameObjectName::BlueBird)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlueBird, Rect(x, y, 50, 50));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 50, 50)));
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

	BirdFixtureDef.filter.categoryBits = FilterCategory::BIRD;
	BirdFixtureDef.filter.maskBits = FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);
}

//void BlueBird::AddScale(float s)
//{
//}
//float BlueBird::GetScale()
//{
//}
//void BlueBird::Rotate(float a)
//{
//
//}
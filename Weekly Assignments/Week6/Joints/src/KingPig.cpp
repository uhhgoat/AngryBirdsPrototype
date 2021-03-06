#include "KingPig.h"




KingPig::KingPig(float x, float y, float rot, b2World &world, bool showDebugShape)
	:GameObject2D(GameObjectName::Pigs)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::KingPig, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	/*
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	//*/

	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 100, 100)));

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
	//b2PolygonShape BirdBox;
	//BirdBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));

	b2CircleShape BirdBox;
	BirdBox.m_p = b2Vec2(0, 0);
	BirdBox.m_radius = PixelToMeter(this->origWidth * 0.5f);

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 10.0f;
	BirdFixtureDef.friction = 0.9f;
	BirdFixtureDef.restitution = 0.01f;
	BirdFixtureDef.userData = this;

	BirdFixtureDef.filter.categoryBits = FilterCategory::PIG;
	BirdFixtureDef.filter.maskBits = FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);
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
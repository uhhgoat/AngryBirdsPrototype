#include "WoodBlockLong.h"


WoodBlockLong::WoodBlockLong(float x, float y, float rot, b2World &world)
	:GameObject2D(GameObjectName::WoodBlockLong)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WoodBlockLong, Rect(x, y, 500, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 500, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);

	//BOX2D STUFF
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_staticBody;  // Default value, but I show it here explicitly
	GroundBoxDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	GroundBoxDef.angle = currAngle;

	// Body
	b2Body *pGroundBoxBody = world.CreateBody(&GroundBoxDef);  // Bodies manage their own fixtures

																 // Shape
	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));


	// Fixture
	b2FixtureDef GroundFixtureDef;
	GroundFixtureDef.shape = &GroundBox;
	GroundFixtureDef.friction = 0.8f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = FilterCategory::WOODBLOCK;
	GroundFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);
	hitPoints = 1000;
}

void WoodBlockLong::TakeImpact(float damage)
{
	hitPoints -= (int)damage;

	//Need to start with death at 0 or less first
	if (hitPoints < 250)
	{
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockLong4, Rect(x, y, 500, 40)));
	}
	else if (hitPoints < 500)
	{
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockLong3, Rect(x, y, 500, 40)));
	}
	else if (hitPoints < 750)
	{
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockLong2, Rect(x, y, 500, 40)));
	}
}
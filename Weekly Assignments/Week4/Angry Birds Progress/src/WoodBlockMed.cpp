#include "WoodBlockMed.h"
#include "Includes.h"


WoodBlockMed::WoodBlockMed(float x, float y, float rot, b2World &world)
	:GameObject2D(GameObjectName::WoodBlockMed)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WoodBlockMed, Rect(x, y, 400, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 400, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);

	//BOX2D STUFF
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_dynamicBody;  // Default value, but I show it here explicitly
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
	GroundFixtureDef.density = 10.0f;
	GroundFixtureDef.restitution = 0.05f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = FilterCategory::WOODBLOCK;
	GroundFixtureDef.filter.maskBits = FilterCategory::BLAST | FilterCategory::GROUND | FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);
	hitPoints = 1000;
}

void WoodBlockMed::TakeImpact(float damage)
{
	hitPoints -= (int)damage;

	//Need to start with death at 0 or less first
	if (hitPoints < 0)
	{
		MarkForDelete();
	}
	else if (hitPoints < 250)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockMed4, Rect(x, y, 400, 40)));
	}
	else if (hitPoints < 500)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockMed3, Rect(x, y, 400, 40)));
	}
	else if (hitPoints < 750)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WoodBlockMed2, Rect(x, y, 400, 40)));
	}
}


void WoodBlockMed::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WoodBlockMed::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
}; 
void WoodBlockMed::CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
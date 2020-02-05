#include "Background.h"
#include "Includes.h"
#include "Game.h"

Background::Background()
	:GameObject2D(GameObjectName::Background)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Background, Rect(0, 0, 3840, 1500));
	SetGameSprite(pGraphics_Sprite);
	currAngle = 0;
	origAngle = 0;
	posX = 960;
	posY = 540;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(0, 0, 3840, 1500)));
	SetDrawDebug(false);
	SetDrawSprite(true);

	//BOX2D STUFF
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_staticBody;  // Default value, but I show it here explicitly
	GroundBoxDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	GroundBoxDef.angle = currAngle;

	// Body
	b2Body *pGroundBoxBody = Game::GetB2World()->CreateBody(&GroundBoxDef);  // Bodies manage their own fixtures

															   // Shape
	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(PixelToMeter(origWidth), PixelToMeter(origHeight),
		b2Vec2(PixelToMeter(0), PixelToMeter(0)), 
		origAngle);



	// Fixture
	b2FixtureDef GroundFixtureDef;
	GroundFixtureDef.shape = &GroundBox;
	GroundFixtureDef.friction = 0.3f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = 0;
	GroundFixtureDef.filter.maskBits = 0;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);


	floor = new GameObject2D(GameObjectName::Background, new GraphicsObject_Sprite(ImageName::Background,
								Rect(1920, 350, 3840, 1)), new GraphicsObject_Box(Rect(1920, 350, 3840, 1)));
	floor->SetDrawSprite(false);
	floor->SetDrawDebug(false);
	GameObjectMan::Add(floor, GameObjectName::Background);

	//BOX2D STUFF
	

	// Shape
	b2PolygonShape GroundBox2;
	GroundBox2.SetAsBox(PixelToMeter(floor->origWidth), PixelToMeter(floor->origHeight),
		b2Vec2(PixelToMeter(0), PixelToMeter(-275)),
		floor->origAngle);


	// Fixture
	b2FixtureDef GroundFixtureDef2;
	GroundFixtureDef2.shape = &GroundBox2;
	GroundFixtureDef2.friction = 0.3f;
	GroundFixtureDef2.userData = this;

	GroundFixtureDef2.filter.categoryBits = FilterCategory::GROUND;
	GroundFixtureDef2.filter.maskBits = FilterCategory::BIRD | FilterCategory::BLOCK | FilterCategory::PIG;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef2);

	// GameObject points to Body
	floor->SetBody(pGroundBoxBody);
	
}



void Background::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};

void Background::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Background::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
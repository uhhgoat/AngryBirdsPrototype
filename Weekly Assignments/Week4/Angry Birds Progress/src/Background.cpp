#include "Background.h"
#include "Includes.h"

Background::Background(b2World &world)
	:GameObject2D(GameObjectName::Background)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Background, Rect(0, 0, 1920, 1080));
	SetGameSprite(pGraphics_Sprite);
	currAngle = 0;
	origAngle = 0;
	posX = 960;
	posY = 540;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(0, 0, 1920, 436)));
	SetDrawDebug(true);
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
	GroundBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(436 * 0.5f),
		b2Vec2(PixelToMeter(0), PixelToMeter(0)), 
		origAngle);



	// Fixture
	b2FixtureDef GroundFixtureDef;
	GroundFixtureDef.shape = &GroundBox;
	GroundFixtureDef.friction = 0.3f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = FilterCategory::GROUND;
	GroundFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);
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
#include "SlashLine.h"

#include "Game.h"
#include "PixelToMeter.h"

SlashLine::SlashLine(float posx, float posy, float ang, float width, float height, GameObjectName::Name objname, ImageName::Name imgname)
	: GameObject2D(
		objname,
		new GraphicsObject_Sprite(imgname, Rect(posx, posy, width, height)),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	this->SetDrawDebug(false);

	// BodyDef
	b2BodyDef BodyDef;
	BodyDef.type = b2_staticBody;
	BodyDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BodyDef.angle = ang;

	// Body
	this->pBody = Game::GetB2World()->CreateBody(&BodyDef);

	// Shape
	b2PolygonShape Shape;
	Shape.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);

	// We must use a Fixture Definition
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	//FixtureDef.density = 1;
	//FixtureDef.restitution = 1.0f;
	//FixtureDef.friction = .9f;
	FixtureDef.userData = this;

	//FixtureDef.filter.categoryBits = 0;
	//FixtureDef.filter.maskBits = 0;

	this->pBody->CreateFixture(&FixtureDef);


}
void SlashLine::Update(float t)
{
	//lifetime -= 1;
	if (lifetime <= 0)
	{
		MarkForDelete();
	}
	GameObject2D::Update(t);
}
#include "CarBodyCasual.h"

#include "Game.h"
#include "PixelToMeter.h"

CarBodyCasual::CarBodyCasual(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::MainGroup,
		new GraphicsObject_Sprite(ImageName::CarCasualBody, Rect(posx, posy, 275, 80)),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	SetDrawDebug(true);

	// BodyDef
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
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
	FixtureDef.density = 1;
	//FixtureDef.restitution = 1.0f;
	FixtureDef.friction = .9f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);


}
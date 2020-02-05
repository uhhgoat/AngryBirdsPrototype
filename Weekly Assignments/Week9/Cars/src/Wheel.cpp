#include "Wheel.h"
#include "Game.h"
#include "PixelToMeter.h"

Wheel::Wheel(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::MainGroup,
		new GraphicsObject_Sprite(ImageName::Wheel, Rect(posx, posy, 44, 44)),
		GameObject2D::Circle
	)
{
	this->origAngle = ang;
	SetDrawDebug(true);

	// BodyDef
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	BodyDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BodyDef.angle = ang;

	// Body
	this->pBody = Game::GetB2World()->CreateBody(&BodyDef);

	// Shape
	b2CircleShape Shape;
	Shape.m_p = b2Vec2(0, 0);
	Shape.m_radius = PixelToMeter(origWidth/2);

	// We must use a Fixture Definition
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.density = 1;
	FixtureDef.friction = .95f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);


}
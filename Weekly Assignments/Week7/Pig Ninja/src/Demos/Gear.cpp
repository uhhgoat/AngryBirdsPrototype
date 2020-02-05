#include "Gear.h"
#include "Game.h"
#include "PixelToMeter.h"

Gear::Gear(float posx, float posy, float ang, float rad, GameObjectName::Name objname, ImageName::Name imgname)
	: GameObject2D(
		objname,
		new GraphicsObject_Sprite(imgname, Rect(posx, posy, 2*rad, 2*rad)),
		GameObject2D::Circle
	)
{
	this->origAngle = ang;
	//this->drawDebug = true;

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
	Shape.m_radius = PixelToMeter(rad);

	// We must use a Fixture Definition
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.density = 1;
	FixtureDef.friction = .5f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);


}
#include "Pig.h"
#include "Box2D.h"
#include "Game.h"
#include "PixelToMeter.h"
#include "Shrapnel.h"
#include "ContactAction.h"

Pig::Pig(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::Pig,
		new GraphicsObject_Sprite(ImageName::Pig, Rect(posx, posy, 47, 47)),
		GameObject2D::Box
		//GameObject2D::Circle
	)
{
	this->origAngle = ang;
	this->SetDrawDebug(true);

	// BodyDef
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	BodyDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BodyDef.angle = ang;

	// Body
	this->pBody = Game::GetB2World()->CreateBody(&BodyDef);

	// Shape
	/*
	b2CircleShape Shape;
	Shape.m_p = b2Vec2(0, 0);
	Shape.m_radius = PixelToMeter(this->origWidth * 0.5f);
	//*/
	//*
	b2PolygonShape Shape;
	Shape.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);
	//*/

	// We must use a Fixture Definition
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.density = 1;
	FixtureDef.friction = .09f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);
}
void Pig::CollideVisit(Shrapnel& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

bool Pig::CollectShrapnel(Color::Type col)
{
	if (col != Color::Type::Green)
		return false;
	if (numShrapnel > 100)
	{
		DebugMsg::out("\n Pig is Full! \n");
		return false;
	}
	else
	{
		numShrapnel++;
		DebugMsg::out("\n %d Shrapnel in PIG! \n", numShrapnel);
		return true;
	}
}
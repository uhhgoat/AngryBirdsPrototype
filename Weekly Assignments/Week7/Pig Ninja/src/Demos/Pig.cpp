#include "Pig.h"
#include "Box2D.h"
#include "Game.h"
#include "PixelToMeter.h"

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
	FixtureDef.friction = .9f;
	//FixtureDef.restitution = 1.0f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);

	float horz = (rand() % 50 - 25) / 100.0f;
	b2Vec2 direction(horz, 1);
	direction.Normalize();

	this->pBody->ApplyLinearImpulseToCenter(15 * direction, true);
}

void Pig::Update(float t)
{
	

	if (this->posX < -100)
	{
		MarkForDelete();
	}
	GameObject2D::Update(t);
}

void Pig::GetSliced()
{
	//adjust score POSITIVE
	Game::SCORE += 10;
	DebugMsg::out("\n SCORE: %d \n", Game::SCORE);
	MarkForDelete();
}
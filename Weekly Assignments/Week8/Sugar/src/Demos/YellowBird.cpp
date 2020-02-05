#include "YellowBird.h"
#include "../PixelToMeter.h"
#include "Game.h"
#include "BlockWoodLong.h"
#include "ContactAction.h"
#include "Shrapnel.h"

YellowBird::YellowBird(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::RedBird,
		new GraphicsObject_Sprite(ImageName::YellowBird, Rect(posx, posy, 52, 52)),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	this->SetDrawDebug(true);
	this->SetDrawSprite(true);

	this->IsPointing = true;

	// Body Def
	b2BodyDef BirdDef;
	BirdDef.type = b2_dynamicBody;
	BirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BirdDef.angle = 0; // leave this as 0 and change the angle using the shape parameter instead

						  // Body
	b2Body *pBirdBody = Game::GetB2World()->CreateBody(&BirdDef);

	pBirdBody->SetActive(true);

	// Shape
	//*
	b2PolygonShape BirdBox;
	BirdBox.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);
	//*/

	/*
	b2CircleShape RedBirdBox;
	RedBirdBox.m_radius = PixelToMeter(25);
	RedBirdBox.m_p = b2Vec2(0, 0);
	//*/

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 10.0f;
	BirdFixtureDef.friction = 0.3f;
	BirdFixtureDef.restitution = 0.50f;
	BirdFixtureDef.userData = this;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	this->pBody = pBirdBody;

	TotalPunchImpulse = 0;
	PunchMode = true; // normal set by click action
}

void YellowBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("Yellow punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		PunchMode = false;
	}
}

void YellowBird::Update(float t)
{
	// orient the bird towards its motion
	//if (IsPointing)
	//{
	//	float angle = atan2f(pBody->GetLinearVelocity().y, pBody->GetLinearVelocity().x);
	//	pBody->SetTransform(pBody->GetWorldCenter(), angle);
	//}
	/*
	// Trail Control
	static int count = 0;
	if (TrailOn)
	{
		if (pBody->IsActive() && count > 5)
		{
			count = 0;
			b2Vec2 pos = pBody->GetPosition();
			//PuffFact.Create(MeterToPixel(pos.x), MeterToPixel(pos.y), pBody->GetAngle());

			// Feathers!
			this->ExplosionFeathers.Create(MeterToPixel(pos.x), MeterToPixel(pos.y));
		}
		count++;
	}
	*/

	// **** IMPORTANT ****: Don't forget to call the base class Update!!!!!!!!
	GameObject2D::Update(t);
}

void YellowBird::CollideVisit(BlockWoodLong& other, b2Contact* pcontact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pcontact, pImpulse);
}

void YellowBird::CollideVisit(GenericBlock& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

void YellowBird::CollideVisit(Shrapnel& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(*this, other, pContact, pImpulse);
}

bool YellowBird::CollectShrapnel(Color::Type col)
{
	if (col != Color::Type::Yellow)
		return false;
	if (numShrapnel > 100)
	{
		DebugMsg::out("\n Yellow Bird is Full! \n");
		return false;
	}
	else
	{
		numShrapnel++;
		DebugMsg::out("\n %d Shrapnel in YELLOW BIRD! \n", numShrapnel);
		return true;
	}
}


void YellowBird::Move(float dx, float dy)
{
	b2Vec2 pos = pBody->GetPosition();
	pos.x += dx;
	pos.y += dy;
	float ang = pBody->GetAngle();

	pBody->SetTransform(pos, ang);
}

void YellowBird::KillTrail()
{
	this->PuffFact.RecallTrail();
}

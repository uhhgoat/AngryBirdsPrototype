#include "Shrapnel.h"
#include "Box2D.h"
#include "Game.h"
#include "GameObjectMan.h"
#include "ManagedPool.h"
#include "TimerMan.h"
#include "TerminateCallbackCmd.h"
#include "YellowBird.h"
#include "Pig.h"
#include "ContactAction.h"

Shrapnel::Shrapnel(ManagedPool* pool)
	: pPool(pool),
	GameObject2D(
		GameObjectName::Shrapnel,
		new GraphicsObject_Sprite(ImageName::TrailPuff, Rect(0, 0, 1, 1)),
		GameObject2D::Circle
	)
{
	this->color = Color::Type::Yellow;
	this->currAngle = 0;
	this->SetDrawDebug(true);
	this->SetDrawSprite(false);
	this->SetDebugColor(color);

	this->ManagedNoDelete = true;
	this->speedMag = 20;

	// Box2D definition
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	//BodyDef.gravityScale = 0;
	BodyDef.linearDamping = 3;

	b2CircleShape Shape;
	Shape.m_radius = PixelToMeter( origWidth/2);
	Shape.m_p = b2Vec2(0, 0);

	// Fixture
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.density = 1.0f;
	FixtureDef.friction = 0.3f;
	FixtureDef.restitution = 0.1f;
	FixtureDef.userData = this;
	//FixtureDef.filter.groupIndex = -1;

	this->pBody = Game::GetB2World()->CreateBody(&BodyDef);
	this->pBody->CreateFixture(&FixtureDef);

	pTermCmd = new TerminateCallbackCmd(this);
}
Color::Type Shrapnel::GetColor()
{
	return color;
}

void Shrapnel::Update(float t)
{
	if (this->posY < 0)
	{
		TerminateCallback();
	}
	GameObject2D::Update(t);
}

Shrapnel::~Shrapnel()
{
	//Game::GetB2World()->DestroyBody(this->pBody);
	delete pTermCmd;
}

void Shrapnel::SetPosAng(float wx, float wy, float ang)
{
	this->pBody->SetTransform(b2Vec2(wx, wy), ang);
	//this->pBody->SetLinearVelocity(speedMag * b2Vec2(cosf(ang), sinf(ang)));
	this->pBody->SetActive(true);
	this->color = Color::Type::Yellow;
	this->SetDebugColor(color);

	//TimerMan::AddEvent(1, pTermCmd);
}

void Shrapnel::ManagedSceneExit()
{
	this->pBody->SetActive(false);
	this->pPool->Recycle(this);
}

void Shrapnel::TerminateCallback()
{
	this->MarkForDelete();
}

void Shrapnel::CollideVisit(Pig& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}

void Shrapnel::CollideVisit(YellowBird& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}
void Shrapnel::CollideVisit(ColorFilter& other, b2Contact* pContact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pContact, pImpulse);
}
void Shrapnel::TurnGreen()
{
	this->color = Color::Type::Green;
	this->SetDebugColor(color);
}
#include "StoneCircle.h"
#include "Includes.h"
#include "Game.h"


StoneCircle::StoneCircle(float x, float y, float rot)
	:GameObject2D(GameObjectName::StoneCircle)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::StoneCircle, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;

	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 100, 100)));
	SetDrawDebug(false);
	SetDrawSprite(true);

	//BOX2D STUFF
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_dynamicBody;  // Default value, but I show it here explicitly
	GroundBoxDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	GroundBoxDef.angle = currAngle;

	// Body
	b2Body *pGroundBoxBody = Game::GetB2World()->CreateBody(&GroundBoxDef);  // Bodies manage their own fixtures

																			 // Shape
	b2CircleShape GroundBox;
	GroundBox.m_p = b2Vec2(0, 0);
	GroundBox.m_radius = PixelToMeter(this->origWidth * 0.5f);


	// Fixture
	b2FixtureDef GroundFixtureDef;
	GroundFixtureDef.shape = &GroundBox;
	GroundFixtureDef.friction = 0.9f;
	GroundFixtureDef.density = 30;
	GroundFixtureDef.restitution = 0.05f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GroundFixtureDef.filter.maskBits = FilterCategory::BLAST | FilterCategory::GROUND | FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);
	hitPoints = 1500;

	SetAwakeListener(this);

	SleepMonitor::ReportWakeState(this->pBody);

	myAwake = pBody->IsAwake();
}

void StoneCircle::TakeImpact(float damage)
{
	hitPoints -= (int)damage;
	if (damage > 200)
		AudioManager::Stone();

	//Need to start with death at 0 or less first
	if (hitPoints < 0)
	{
		pBody->SetAwake(false);
		EndAwake(pBody);
		MarkForDelete();
	}
	else if (hitPoints < 375)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneCircle4, Rect(x, y, 100, 100)));
	}
	else if (hitPoints < 750)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneCircle3, Rect(x, y, 100, 100)));
	}
	else if (hitPoints < 1125)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneCircle2, Rect(x, y, 100, 100)));
	}
}


void StoneCircle::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneCircle::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};

void StoneCircle::BeginAwake(b2Body*)
{
	if (!myAwake)
	{
		this->SetDebugColor(Color::Type::Yellow);
		DebugMsg::out("StoneCircle awake\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = true;
	}
}

void StoneCircle::EndAwake(b2Body*)
{
	if (myAwake)
	{
		this->SetDebugColor(Color::Type::Black);
		DebugMsg::out("StoneCircle asleep\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = false;
	}
}
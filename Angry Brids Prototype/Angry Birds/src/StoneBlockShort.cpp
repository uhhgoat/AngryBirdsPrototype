#include "StoneBlockShort.h"
#include "Includes.h"
#include "Game.h"


StoneBlockShort::StoneBlockShort(float x, float y, float rot)
	:GameObject2D(GameObjectName::StoneBlockShort)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::StoneBlockShort, Rect(x, y, 100, 25));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 25)));
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
	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));


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

void StoneBlockShort::TakeImpact(float damage)
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
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneBlockShort4, Rect(x, y, 100, 25)));
	}
	else if (hitPoints < 750)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneBlockShort3, Rect(x, y, 100, 25)));
	}
	else if (hitPoints < 1125)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::StoneBlockShort2, Rect(x, y, 100, 25)));
	}
}


void StoneBlockShort::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void StoneBlockShort::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};

void StoneBlockShort::BeginAwake(b2Body*)
{
	if (!myAwake)
	{
		this->SetDebugColor(Color::Type::Yellow);
		DebugMsg::out("StoneBlockShort awake\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = true;
	}
}

void StoneBlockShort::EndAwake(b2Body*)
{
	if (myAwake)
	{
		this->SetDebugColor(Color::Type::Black);
		DebugMsg::out("StoneBlockShort asleep\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = false;
	}
}
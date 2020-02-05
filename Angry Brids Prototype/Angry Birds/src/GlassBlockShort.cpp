#include "GlassBlockShort.h"
#include "Includes.h"
#include "Game.h"


GlassBlockShort::GlassBlockShort(float x, float y, float rot)
	:GameObject2D(GameObjectName::GlassBlockShort)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockShort, Rect(x, y, 100, 25));
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
	GroundFixtureDef.friction = 0.4f;
	GroundFixtureDef.density = 7.5f;
	GroundFixtureDef.restitution = 0.05f;
	GroundFixtureDef.userData = this;

	GroundFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GroundFixtureDef.filter.maskBits = FilterCategory::BLAST | FilterCategory::GROUND | FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGroundBoxBody->CreateFixture(&GroundFixtureDef);

	// GameObject points to Body
	SetBody(pGroundBoxBody);
	hitPoints = 750;

	SetAwakeListener(this);

	SleepMonitor::ReportWakeState(this->pBody);

	myAwake = pBody->IsAwake();
}

void GlassBlockShort::TakeImpact(float damage)
{
	hitPoints -= (int)damage;
	if (damage > 200)
		AudioManager::Glass();

	//Need to start with death at 0 or less first
	if (hitPoints < 0)
	{
		pBody->SetAwake(false);
		EndAwake(pBody);
		MarkForDelete();
	}
	else if (hitPoints < 187)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::GlassBlockShort4, Rect(x, y, 100, 25)));
	}
	else if (hitPoints < 375)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::GlassBlockShort3, Rect(x, y, 100, 25)));
	}
	else if (hitPoints < 563)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::GlassBlockShort2, Rect(x, y, 100, 25)));
	}
}


void GlassBlockShort::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GlassBlockShort::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};

void GlassBlockShort::BeginAwake(b2Body*)
{
	if (!myAwake)
	{
		this->SetDebugColor(Color::Type::Yellow);
		DebugMsg::out("GlassBlockShort awake\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = true;
	}
}

void GlassBlockShort::EndAwake(b2Body*)
{
	if (myAwake)
	{
		this->SetDebugColor(Color::Type::Black);
		DebugMsg::out("GlassBlockShort asleep\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = false;
	}
}
#include "HelmetPig.h"
#include "Includes.h"
#include "Game.h"


HelmetPig::HelmetPig(float x, float y, float rot)
	:GameObject2D(GameObjectName::HelmetPig)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::HelmetPig, Rect(x, y, 100, 100));
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
	invincibility = 120;

	SetAwakeListener(this);

	SleepMonitor::ReportWakeState(this->pBody);

	myAwake = pBody->IsAwake();
	myLevel = nullptr;
}

void HelmetPig::Update(float t)
{
	invincibility--;
	if (invincibility <= 0)
		invincibility = 0;
	GameObject2D::Update(t);
}

void HelmetPig::TakeImpact(float damage)
{
	if (invincibility > 0)
		return;
	hitPoints -= (int)damage;
	if(damage > 200)
		AudioManager::Snort();

	//Need to start with death at 0 or less first
	if (hitPoints < 0)
	{
		pBody->SetAwake(false);
		EndAwake(pBody);
		MarkForDelete();

		myLevel->ReportDeadPig();

		//REPORT BACK TO LEVEL TO KNOW HOW MANY ARE DEAD
	}
	else if (hitPoints < 500)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::HelmetPig3, Rect(x, y, 100, 100)));
	}
	else if (hitPoints < 1000)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::HelmetPig2, Rect(x, y, 100, 100)));
	}
}

void HelmetPig::SetLevel(Level* l)
{
	myLevel = l;
	l->ReportAddPig();
}


void HelmetPig::CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void HelmetPig::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};

void HelmetPig::BeginAwake(b2Body*)
{
	if (!myAwake)
	{
		this->SetDebugColor(Color::Type::Yellow);
		DebugMsg::out("HelmetPig awake\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = true;
	}
}

void HelmetPig::EndAwake(b2Body*)
{
	if (myAwake)
	{
		this->SetDebugColor(Color::Type::Black);
		DebugMsg::out("HelmetPig asleep\n");
		SleepMonitor::ReportWakeState(this->pBody);
		myAwake = false;
	}
}
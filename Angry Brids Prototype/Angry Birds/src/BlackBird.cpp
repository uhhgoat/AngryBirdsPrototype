#include "BlackBird.h"
#include "Includes.h"
#include "Game.h"



BlackBird::BlackBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Birds)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BlackBird, Rect(x, y, 62.5f, 75));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 62.5f, 62.5f)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);

	//BOX2D STUFF
	// Body Def
	b2BodyDef BirdDef;
	BirdDef.type = b2_dynamicBody;
	BirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BirdDef.angle = currAngle;

	// Body
	b2Body *pBirdBody = Game::GetB2World()->CreateBody(&BirdDef);

	// Shape
	b2CircleShape BirdBox;
	BirdBox.m_p = b2Vec2(0, 0);
	BirdBox.m_radius = PixelToMeter(this->origWidth * 0.5f);

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 20.0f;
	BirdFixtureDef.friction = 0.3f;
	BirdFixtureDef.restitution = 0.50f;
	BirdFixtureDef.userData = this;

	BirdFixtureDef.filter.categoryBits = FilterCategory::BIRD;
	BirdFixtureDef.filter.maskBits = FilterCategory::GROUND | FilterCategory::BLOCK | FilterCategory::PIG;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);

	this->isPointing = true;
	TotalPunchImpulse = 0;
	specialUsed = false;
}

void BlackBird::SetFlying()
{
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::BlackBirdFlying, Rect(x, y, 62.5f, 75)));
	idle = false;
}

void BlackBird::SetPointing(bool b)
{
	this->isPointing = b;
	this->specialUsed = true;
	this->trailOn = false;
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::BlackBirdDamaged, Rect(x, y, 62.5f, 75)));
}

void BlackBird::Update(float t)
{
	if (idle)
	{
		frame++;
		if (frame >= rand() % 300 + 60 && !blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::BlackBirdBlink, Rect(x, y, 62.5f, 75)));
			frame = 0;
			blinking = true;
		}
		else if (frame >= 20 && blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::BlackBird, Rect(x, y, 62.5f, 75)));
			frame = 0;
			blinking = false;
		}
	}

	if (isPointing)
	{
		float angle = atan2f(pBody->GetLinearVelocity().y, pBody->GetLinearVelocity().x);
		pBody->SetTransform(pBody->GetWorldCenter(), angle);
	}
	if (exploding)
	{
		//CREATE A BLAST
		Blast *b = new Blast(posX, posY, 0.0f);
		GameObjectMan::Add(b, GameObjectName::MainGroup);
		SetDrawSprite(false);
		pBody->SetActive(false);
		exploding = false;
		//DELETE SELF
		//MarkForDelete();
	}

	// Trail Control
	static int count = 0;
	if (trailOn)
	{
		if (pBody->IsActive() && count > 3)
		{
			count = 0;
			b2Vec2 pos = pBody->GetPosition();
			factory.Create(MeterToPixel(pos.x), MeterToPixel(pos.y), pBody->GetAngle());

		}
		count++;
	}

	GameObject2D::Update(t);
}

void BlackBird::KillTrail()
{
	this->factory.RecallTrail();
}

void BlackBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("Blue punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		punchMode = false;
	}
}

bool BlackBird::GetPunchMode()
{
	return punchMode;
}

GameObject2D* BlackBird::SpecialAction()
{
	if (!specialUsed)
	{
		exploding = true;
		specialUsed = true;
	}
	return this;
}


void BlackBird::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BlackBird::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BlackBird::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BlackBird::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BlackBird::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
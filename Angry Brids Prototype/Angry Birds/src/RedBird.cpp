#include "RedBird.h"
#include "Includes.h"
#include "Game.h"


RedBird::RedBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Birds)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::RedBird, Rect(x, y, 50, 50));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 50, 50)));
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
	BirdFixtureDef.restitution = 0.10f;
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

void RedBird::SetFlying()
{
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::RedBirdFlying, Rect(x, y, 50, 50)));
	idle = false;
}


void RedBird::SetPointing(bool b)
{
	this->isPointing = b;
	this->specialUsed = true;
	this->trailOn = false;
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::RedBirdDamaged, Rect(x, y, 50, 50)));
}

void RedBird::Update(float t)
{
	if (idle)
	{
		frame++;
		if (frame >= rand() % 300 + 60 && !blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::RedBirdBlink, Rect(x, y, 50, 50)));
			frame = 0;
			blinking = true;
		}
		else if (frame >= 20 && blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::RedBird, Rect(x, y, 50, 50)));
			frame = 0;
			blinking = false;
		}
	}

	if (isPointing)
	{
		float angle = atan2f(pBody->GetLinearVelocity().y, pBody->GetLinearVelocity().x);
		pBody->SetTransform(pBody->GetWorldCenter(), angle);
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

void RedBird::KillTrail()
{
	this->factory.RecallTrail();
}

void RedBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("Red punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		punchMode = false;
	}
}

bool RedBird::GetPunchMode()
{
	return punchMode;
}

GameObject2D* RedBird::SpecialAction()
{
	if (!specialUsed)
	{
		//NONE, REAL GAME JUST HAS A NOISE
		specialUsed = true;
	}
	return this;
}


void RedBird::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void RedBird::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void RedBird::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void RedBird::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void RedBird::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
#include "BigRedBird.h"
#include "Includes.h"
#include "Game.h"



BigRedBird::BigRedBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Birds)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BigRedBird, Rect(x, y, 75, 75));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 75, 75)));
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

void BigRedBird::SetFlying()
{
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::BigRedBirdFlying, Rect(x, y, 75, 75)));
	idle = false;
}

void BigRedBird::SetPointing(bool b)
{
	this->isPointing = b;
	this->specialUsed = true;
	this->trailOn = false;
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::BigRedBirdDamaged, Rect(x, y, 75, 75)));
}

void BigRedBird::Update(float t)
{
	if (idle)
	{
		frame++;
		if (frame >= rand() % 300 + 60 && !blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::BigRedBirdBlink, Rect(x, y, 75, 75)));
			frame = 0;
			blinking = true;
		}
		else if (frame >= 20 && blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::BigRedBird, Rect(x, y, 75, 75)));
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

void BigRedBird::KillTrail()
{
	this->factory.RecallTrail();
}

void BigRedBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("BigRed punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		punchMode = false;
	}
}

bool BigRedBird::GetPunchMode()
{
	return punchMode;
}

GameObject2D* BigRedBird::SpecialAction()
{
	if (!specialUsed)
	{
		//NONE, REAL GAME JUST HAS A NOISE
		specialUsed = true;
	}
	return this;
}


void BigRedBird::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BigRedBird::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void BigRedBird::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BigRedBird::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void BigRedBird::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
#include "GreenBird.h"
#include "Includes.h"
#include "Game.h"



GreenBird::GreenBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Birds)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GreenBird, Rect(x, y, 87.5f, 70));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, 70, 70)));
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
	specialOn = false;
}

void GreenBird::SetFlying()
{
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::GreenBirdFlying, Rect(x, y, 87.5f, 70)));
	idle = false;
}

void GreenBird::SetPointing(bool b)
{
	this->isPointing = b;
	this->specialUsed = true;
	this->specialOn = false;
	this->trailOn = false;
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::GreenBirdDamaged, Rect(x, y, 87.5f, 70)));
}

void GreenBird::Update(float t)
{
	if (idle)
	{
		frame++;
		if (frame >= rand() % 300 + 60 && !blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::GreenBirdBlink, Rect(x, y, 87.5f, 70)));
			frame = 0;
			blinking = true;
		}
		else if (frame >= 20 && blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::GreenBird, Rect(x, y, 87.5f, 70)));
			frame = 0;
			blinking = false;
		}
	}

	if (isPointing)
	{
		float angle = atan2f(pBody->GetLinearVelocity().y, pBody->GetLinearVelocity().x);
		pBody->SetTransform(pBody->GetWorldCenter(), angle);
	}

	if (specialOn)
	{
		pBody->ApplyTorque(-100.0f, true);
		pBody->ApplyForceToCenter(1250 * b2Vec2(-1, 0), true);
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

void GreenBird::KillTrail()
{
	this->factory.RecallTrail();
}

void GreenBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("Blue punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		punchMode = false;
	}
}

bool GreenBird::GetPunchMode()
{
	return punchMode;
}

GameObject2D* GreenBird::SpecialAction()
{
	if (!specialUsed)
	{
		//BOOMERANG BACK AROUND
		specialOn = true;
		isPointing = false;
	}
	return this;
}


void GreenBird::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GreenBird::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void GreenBird::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GreenBird::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void GreenBird::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
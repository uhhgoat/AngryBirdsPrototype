#include "WhiteBird.h"
#include "Includes.h"
#include "Game.h"



WhiteBird::WhiteBird(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Birds)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::WhiteBird, Rect(x, y, 75, 80));
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

void WhiteBird::SetFlying()
{
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::WhiteBirdFlying, Rect(x, y, 75, 80)));
	idle = false;
}


void WhiteBird::SetPointing(bool b)
{
	this->isPointing = b;
	this->specialUsed = true;
	this->trailOn = false;
	delete this->GetGameSprite(); // delete current one
	SetGameSprite(new GraphicsObject_Sprite(ImageName::WhiteBirdDamaged, Rect(x, y, 75, 80)));
}

void WhiteBird::Update(float t)
{
	if (idle)
	{
		frame++;
		if (frame >= rand() % 300 + 60 && !blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::WhiteBirdBlink, Rect(x, y, 75, 80)));
			frame = 0;
			blinking = true;
		}
		else if (frame >= 20 && blinking)
		{
			delete this->GetGameSprite(); // delete current one
			SetGameSprite(new GraphicsObject_Sprite(ImageName::WhiteBird, Rect(x, y, 75, 80)));
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

void WhiteBird::KillTrail()
{
	this->factory.RecallTrail();
}

void WhiteBird::AddPunchDamage(float d)
{
	TotalPunchImpulse += d;
	DebugMsg::out("White punch = %f\n", TotalPunchImpulse);

	if (TotalPunchImpulse >= MaxPunchImpulse)
	{
		punchMode = false;
	}
}

bool WhiteBird::GetPunchMode()
{
	return punchMode;
}

GameObject2D* WhiteBird::SpecialAction()
{
	if (!specialUsed)
	{
		Egg* egg = new Egg(posX, posY, 0);
		GameObjectMan::Add(egg, GameObjectName::Birds);
		float magnitude = 100;
		b2Vec2 direction = b2Vec2(0, 1);
		direction.Normalize();
		this->GetBody()->ApplyLinearImpulseToCenter(magnitude * direction, true);
		//CHANGE SPRITE TO SHRIVELLED ONE--------------------------------------------
		isPointing = false;
		specialUsed = true;

		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::WhiteBirdShrivelled, Rect(x, y, 45, 50)));

		return egg;
	}
	return this;
}


void WhiteBird::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WhiteBird::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void WhiteBird::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WhiteBird::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void WhiteBird::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
#include "Blast.h"
#include "Includes.h"
#include "Game.h"



Blast::Blast(float x, float y, float rot, bool showDebugShape)
	:GameObject2D(GameObjectName::Blast)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Blast1, Rect(x, y, 50, 50));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = 250;
	origWidth = 250;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, origHeight, origWidth)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);

	//BOX2D STUFF
	// Body Def
	b2BodyDef BlastDef;
	BlastDef.type = b2_dynamicBody;
	BlastDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BlastDef.angle = currAngle;
	BlastDef.gravityScale = 0;

	// Body
	b2Body *pBlastBody = Game::GetB2World()->CreateBody(&BlastDef);

	// Shape
	b2CircleShape BlastBox;
	//BlastBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));
	BlastBox.m_radius = PixelToMeter(origHeight/2.0f);

	// Fixture
	b2FixtureDef BlastFixtureDef;
	BlastFixtureDef.shape = &BlastBox;
	BlastFixtureDef.userData = this;
	BlastFixtureDef.isSensor = true;

	BlastFixtureDef.filter.categoryBits = FilterCategory::BLAST;
	BlastFixtureDef.filter.maskBits = FilterCategory::BLOCK | FilterCategory::PIG;

	pBlastBody->CreateFixture(&BlastFixtureDef);

	// GameObject points to Body
	SetBody(pBlastBody);

	
}

void Blast::Update(float currentTime)
{
	frames--;
	if (frames < 1)
	{
		MarkForDelete();
	}
	if (frames == 50)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::Blast2, Rect(x, y, 100, 100)));
	}
	if (frames == 40)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::Blast3, Rect(x, y, 150, 150)));
	}
	if (frames == 30)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::Blast4, Rect(x, y, 200, 200)));
	}
	if (frames == 20)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::Blast5, Rect(x, y, 225, 225)));
	}
	if (frames == 10)
	{
		delete this->GetGameSprite(); // delete current one
		SetGameSprite(new GraphicsObject_Sprite(ImageName::Blast6, Rect(x, y, 250, 250)));
	}
	GameObject2D::Update(currentTime);
}

void Blast::CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(*this, other, contact, impulse);
};
void Blast::CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
void Blast::CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse)
{
	ContactAction::ContactPair(other, *this, contact, impulse);
};
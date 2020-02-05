#include "Blast.h"
#include "Includes.h"



Blast::Blast(float x, float y, float rot, b2World &world, bool showDebugShape)
	:GameObject2D(GameObjectName::Blast)
{
	//AZUL STUFF
	//GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::BigRedBird, Rect(x, y, 150, 150));
	//SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = 500;
	origWidth = 500;
	SetDebugShape(DEBUG_SHAPE::Circle);
	SetDebugSprite(new GraphicsObject_Circle(Rect(x, y, origHeight, origWidth)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(false);

	//BOX2D STUFF
	// Body Def
	b2BodyDef BlastDef;
	BlastDef.type = b2_dynamicBody;
	BlastDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BlastDef.angle = currAngle;
	BlastDef.gravityScale = 0;

	// Body
	b2Body *pBlastBody = world.CreateBody(&BlastDef);

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
	BlastFixtureDef.filter.maskBits = FilterCategory::GROUND | FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

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
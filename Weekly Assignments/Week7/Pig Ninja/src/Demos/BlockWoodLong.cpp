#include "BlockWoodLong.h"
#include "../PixelToMeter.h"
#include "Game.h"
#include "DebugOut.h"
#include "RedBird.h"
#include "ContactAction.h"

BlockWoodLong::BlockWoodLong(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::Block,
		new GraphicsObject_Sprite(ImageName::Long_Wood_Block, Rect(posx, posy, 400, 20)),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	this->SetDrawDebug(true);

	DamageTotal = 0;
	
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_staticBody;  // Default value, but I show it here explicitly
	GroundBoxDef.position.Set(PixelToMeter(posx), PixelToMeter(posy));
	GroundBoxDef.angle = ang;

	// Body
	b2Body *pGroundBoxBody = Game::GetB2World()->CreateBody(&GroundBoxDef);

	// Shape
	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),  // center of box relative to body position
		this->origAngle
	);

	// We must use a Fixture Definition
	b2FixtureDef GroundBoxFixtureDef;
	GroundBoxFixtureDef.shape = &GroundBox;
	GroundBoxFixtureDef.density = 1;
	GroundBoxFixtureDef.friction = .9f;
	GroundBoxFixtureDef.userData = this;

	pGroundBoxBody->CreateFixture(&GroundBoxFixtureDef);

	// GameObject points to Body
	this->pBody = pGroundBoxBody;
}

void BlockWoodLong::AddDamage(float d)
{
	DamageTotal += d;

	DebugMsg::out("Block Damage: %f\n", DamageTotal);

	if (DamageTotal >= MAX_DAMAGE)
	{
		this->MarkForDelete();
		DebugMsg::out("Block Death\n");

	}
	else if (DamageTotal > MAX_DAMAGE / 2)
	{
		delete this->GetGameSprite(); // delete the current one 
		this->SetGameSprite(new GraphicsObject_Sprite(ImageName::Long_Wood_Block3, Rect(400, 50, 400, 20)) );
	} 
	

}

BlockWoodLong::~BlockWoodLong()
{

}

//*
void BlockWoodLong::CollideVisit(RedBird& other, b2Contact* pcontact, const b2ContactImpulse* pImpulse)
{
	ContactAction::ContactPair(other, *this, pcontact, pImpulse);
}
//*/
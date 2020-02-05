#include  "StickWood.h"
#include "../PixelToMeter.h"
#include "Game.h"
#include "DebugOut.h"
#include "RedBird.h"
#include "ContactAction.h"

StickWood::StickWood(float posx, float posy, float ang, float w, float h)
	: GameObject2D(
		GameObjectName::Block,
		new GraphicsObject_Sprite(ImageName::Long_Wood_Block, Rect(posx, posy, w, h) ),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	//this->SetDrawDebug(true);

	// BodyDef
	b2BodyDef StickBoxDef;
	StickBoxDef.type = b2_dynamicBody;  // Default value, but I show it here explicitly
	StickBoxDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	StickBoxDef.angle = ang;

	// Body
	b2Body *pStickBody = Game::GetB2World()->CreateBody(&StickBoxDef);

	// Shape
	b2PolygonShape StickShape;
	StickShape.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),  // center of box relative to body position
		this->origAngle
	);

	// We must use a Fixture Definition
	b2FixtureDef StickFixtureDef;
	StickFixtureDef.shape = &StickShape;
	StickFixtureDef.density = 1;
	StickFixtureDef.friction = 0.9f;
	StickFixtureDef.restitution = 0.9f;
	StickFixtureDef.userData = this;
	StickFixtureDef.filter.categoryBits = 0;
	StickFixtureDef.filter.maskBits = 0;

	pStickBody->CreateFixture(&StickFixtureDef);


	// GameObject points to Body
	this->pBody = pStickBody;
}

void StickWood::Update(float t)
{
	if (this->posY < 0)
	{
		MarkForDelete();
	}
	GameObject2D::Update(t);
}
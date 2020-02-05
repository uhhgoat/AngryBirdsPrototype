#include "Thruster.h"
#include "Includes.h"

Thruster::Thruster(float x, float y, float rot, b2Body *birdBody, float offsetX, float offsetY, bool showDebugShape)
	:GameObject2D(GameObjectName::Thruster)
{

	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Thruster, Rect(x, y, 100, 20));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 20)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);

	xOff = offsetX;
	yOff = offsetY;

	//BOX2D STUFF
	
	// GameObject points to Body
	SetBody(birdBody);

	// Shape
	b2PolygonShape BirdBox;
	//BirdBox.SetAsBox(PixelToMeter(xOff), PixelToMeter(yOff));
	BirdBox.SetAsBox(
		PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(PixelToMeter(xOff), PixelToMeter(yOff)),
		this->origAngle
	);

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 0;
	BirdFixtureDef.friction = 0;
	BirdFixtureDef.restitution = 0;
	BirdFixtureDef.userData = this;

	BirdFixtureDef.filter.categoryBits = 0;
	BirdFixtureDef.filter.maskBits = 0;

	birdBody->CreateFixture(&BirdFixtureDef);

}

void Thruster::ApplyForce(float force)
{
	float ang = pBody->GetAngle() + origAngle;
	b2Vec2 dir(cosf(ang), sinf(ang));

	b2Vec2 ForcePoint(PixelToMeter(this->xOff), PixelToMeter(this->yOff));

	pBody->ApplyForce(
		pBody->GetMass() * force * dir,
		pBody->GetWorldPoint(ForcePoint),
		true);
	SetDrawSprite(true);
}
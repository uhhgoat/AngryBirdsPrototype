#include "RedBird.h"
#include "../PixelToMeter.h"
#include "Game.h"
#include "BlockWoodLong.h"
#include "ContactAction.h"

#include "JumpTimerCmd.h"
#include "TimerMan.h"
#include "SpriteChangeTimerCmd.h"

RedBird::RedBird(float posx, float posy, float ang)
	: GameObject2D(
		GameObjectName::RedBird,
		new GraphicsObject_Sprite(ImageName::RedBird, Rect(posx, posy, 50.0f, 50.0f)),
		GameObject2D::Box
	)
{
	this->currAngle = ang;
	this->SetDrawDebug(true);
	this->SetDrawSprite(true);
	
	this->DamageTotal = 0;

	// Body Def
	b2BodyDef RedBirdDef;
	RedBirdDef.type = b2_dynamicBody;
	RedBirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	RedBirdDef.angle = 0; // leave this as 0 and change the angle using the shape parameter instead

						  // Body
	b2Body *pRedBirdBody = Game::GetB2World()->CreateBody(&RedBirdDef);

	pRedBirdBody->SetActive(true);

	// Shape
	b2PolygonShape RedBirdBox;
	RedBirdBox.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);

	// Fixture
	b2FixtureDef RedBirdFixtureDef;
	RedBirdFixtureDef.shape = &RedBirdBox;
	RedBirdFixtureDef.density = 10.0f;
	RedBirdFixtureDef.friction = 0.3f;
	RedBirdFixtureDef.restitution = 0.50f;
	RedBirdFixtureDef.userData = this;

	pRedBirdBody->CreateFixture(&RedBirdFixtureDef);
	
	// GameObject points to Body
	this->pBody = pRedBirdBody;

	// needed for demo purposed only
	pJump = nullptr;
	pSpriteChangeCmd = nullptr;

	//  Jumping behavior
	/*
	pJump = new JumpTimerCmd(this);
	TimerMan::AddEvent(3, pJump);
	//*/

	// Animation
	/*
	// Sprite changes and timer cmd
	this->pSpriteArray = new GraphicsObject_Sprite*[SPRITECOUNT];

	this->pSpriteArray[0] = (GraphicsObject_Sprite*)this->getGraphicsObject();
	this->pSpriteArray[1] = new GraphicsObject_Sprite(ImageName::RedBird2, Rect(posx, posy, 50.0f, 50.0f));

	this->CurrentSpriteIndex = 0;

	this->pSpriteChangeCmd = new SpriteChangeTimerCmd(this);
	TimerMan::AddEvent(3, pSpriteChangeCmd);
	//*/
	float horz = (rand() % 50 - 25)/100.0f;
	b2Vec2 direction(horz, 1);
	direction.Normalize();

	this->pBody->ApplyLinearImpulseToCenter(150*direction, true);
}

void RedBird::Update(float t)
{
	// orient the bird towards its motion
	//float angle = atan2f(pBody->GetLinearVelocity().y, pBody->GetLinearVelocity().x);
	//pBody->SetTransform(pBody->GetWorldCenter(), angle);

	// **** IMPORTANT ****: Don't forget to call the base class Update!!!!!!!!

	if (this->posX < -100)
	{
		MarkForDelete();
	}
	GameObject2D::Update(t);
}

void RedBird::GetSliced()
{
	//adjust score NEGATIVE
	Game::SCORE -= 20;
	DebugMsg::out("\n SCORE: %d \n", Game::SCORE);
	
	MarkForDelete();
}

void RedBird::CollideVisit(BlockWoodLong& other, b2Contact* pcontact, const b2ContactImpulse* pImpulse)
{
	other;
	pcontact;
	pImpulse;
	//ContactAction::ContactPair(*this, other, pcontact, pImpulse);
}

RedBird::~RedBird()
{
	delete pJump;

	/*
	// deleted all the graphicsobject_sprites
	for (int i = 0; i < SPRITECOUNT; i++)
	{
	delete this->pSpriteArray[i];
	}
	delete[] pSpriteArray;
	//*/

	// Prevents double deletion from the base class
	//this->SetGameSprite(nullptr);

	delete pSpriteChangeCmd;
}

void RedBird::NextSprite()
{
	CurrentSpriteIndex = (CurrentSpriteIndex + 1) % SPRITECOUNT;

	this->SetGameSprite(pSpriteArray[CurrentSpriteIndex]);

	float t = rand() % 3 + 1.0f;
	TimerMan::AddEvent(t, pSpriteChangeCmd);
}
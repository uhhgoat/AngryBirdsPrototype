#include "FlyingBird.h"
#include "Includes.h"



FlyingBird::FlyingBird(float x, float y, float rot, b2World &world, bool showDebugShape)
	:GameObject2D(GameObjectName::FlyingBird)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::RedBird, Rect(x, y, 100, 100));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = rot;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 100, 100)));
	SetDrawDebug(showDebugShape);
	SetDrawSprite(true);

	//BOX2D STUFF
	// Body Def
	b2BodyDef BirdDef;
	BirdDef.type = b2_dynamicBody;
	BirdDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BirdDef.angle = currAngle;

	// Body
	b2Body *pBirdBody = world.CreateBody(&BirdDef);

	// Shape
	b2PolygonShape BirdBox;
	BirdBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));

	// Fixture
	b2FixtureDef BirdFixtureDef;
	BirdFixtureDef.shape = &BirdBox;
	BirdFixtureDef.density = 10.0f;
	BirdFixtureDef.friction = 0.3f;
	BirdFixtureDef.restitution = 0.50f;
	BirdFixtureDef.userData = this;

	BirdFixtureDef.filter.categoryBits = FilterCategory::BIRD;
	BirdFixtureDef.filter.maskBits = FilterCategory::WOODBLOCK | FilterCategory::GLASSBLOCK;

	pBirdBody->CreateFixture(&BirdFixtureDef);

	// GameObject points to Body
	SetBody(pBirdBody);

	
	acceleration = 12;
	angSpeed = 0;
	bottom = new Thruster(posX, posY, MATH_PI2, pBirdBody, 0, -50);
	GameObjectMan::Add(bottom, GameObjectName::MainGroup);
	left = new Thruster(posX, posY, 0.0f, pBirdBody, -50, 50);
	GameObjectMan::Add(left, GameObjectName::MainGroup);
	right = new Thruster(posX, posY, MATH_PI, pBirdBody, 50, 50);
	GameObjectMan::Add(right, GameObjectName::MainGroup);
}

void FlyingBird::FireUp()
{
	bottom->ApplyForce(acceleration);
}
void FlyingBird::TurnLeft()
{
	right->ApplyForce(acceleration * 0.5f);
}
void FlyingBird::TurnRight()
{
	left->ApplyForce(acceleration * 0.5f);
}
void FlyingBird::ControlFlight()
{
	bottom->SetDrawSprite(false);
	left->SetDrawSprite(false);
	right->SetDrawSprite(false);
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		FireUp();
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
	{
		TurnLeft();
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
	{
		TurnRight();
	}
}

FlyingBird::~FlyingBird()
{
	delete bottom;
	delete left;
	delete right;
}

void FlyingBird::TakeImpact(float damage)
{
	if (damage < 50)
	{
		DebugMsg::out("SAFE LANDING \n");
	}
	else if (damage < 125)
	{
		DebugMsg::out("MEDIUM LANDING \n");
	}
	else
	{
		DebugMsg::out("TERRIBLE LANDING \n");
	}

}

void FlyingBird::Update(float t)
{
	ControlFlight();
	GameObject2D::Update(t);
}
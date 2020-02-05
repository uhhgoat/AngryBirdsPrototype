#include "Hovercraft.h"
#include "Game.h"
#include "Keyboard.h"
#include "DebugOut.h"
#include "Visualizer.h"

Hovercraft::Hovercraft(float posx, float posy)
	: GameObject2D(
		GameObjectName::Hovercraft,
		new GraphicsObject_Sprite(ImageName::GlassBlockShort, Rect(posx, posy, 80, 30)),
		GameObject2D::Box
	)
{
	this->currAngle = 0;
	this->SetDrawDebug(true);
	this->SetDrawSprite(true);

	// Body Def
	b2BodyDef BodyDef;
	BodyDef.type = b2_dynamicBody;
	BodyDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	BodyDef.angle = 0; // leave this as 0 and change the angle using the shape parameter instead
					   //BodyDef.linearDamping = .6f;
					   //BodyDef.angularDamping = 2;
					   //BodyDef.fixedRotation = true;

					   // Body
	this->pBody = Game::GetB2World()->CreateBody(&BodyDef);

	// Shape
	b2PolygonShape Shape;
	Shape.SetAsBox(PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(0, 0),	 // center of box relative to body position
		this->origAngle
	);

	// Fixture
	b2FixtureDef FixtureDef;
	FixtureDef.shape = &Shape;
	FixtureDef.density = 10;
	FixtureDef.friction = 0;
	FixtureDef.restitution = 0.1f;
	FixtureDef.userData = this;

	this->pBody->CreateFixture(&FixtureDef);

	Acceleration = 10;
	HoverHeight = 2;
	SpringConstant = 125;

}

void Hovercraft::Update(float t)
{
	// Demoing the effect of the spring constant
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_EQUAL))
	{
		SpringConstant += 1;
		DebugMsg::out("Spring Constant: %4.0f\n", SpringConstant);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_MINUS))
	{
		SpringConstant -= 1;
		DebugMsg::out("Spring Constant: %4.0f\n", SpringConstant);
	}

	float Fmag = this->pBody->GetMass() * Acceleration;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_J))
	{
		this->pBody->ApplyForceToCenter(Fmag * b2Vec2(-1, 0), true);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_L))
	{
		this->pBody->ApplyForceToCenter(Fmag * b2Vec2(1, 0), true);
		
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		this->pBody->ApplyForceToCenter(Fmag * b2Vec2(0, 1), true);
		
	}
	//SET SPEED CAP
	b2Vec2 vel = pBody->GetLinearVelocity();
	if (vel.Length() > MaxSpeed)
	{
		vel.Normalize();
		pBody->SetLinearVelocity(MaxSpeed*vel);
	}

	this->SetDebugColor(Color::Type::Yellow);
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_I))
	{
		this->SetDebugColor(Color::Type::Red);
	}

	//* Hover force
	GroundDetected = false;
	b2Vec2 pos = this->pBody->GetPosition();
	b2Vec2 EndPoint = pos + b2Vec2(0, -HoverHeight);
	b2Vec2 EndPointLeft = pos + b2Vec2(-1, -HoverHeight/2);
	b2Vec2 EndPointRight = pos + b2Vec2(+1, -HoverHeight/2);

	float ExtraSpacing = 0;
	Game::GetB2World()->RayCast(this, pos, EndPointLeft);
	Game::GetB2World()->RayCast(this, pos, EndPointRight);
	if (GroundDetected)
	{
		ExtraSpacing = 1;
	}
	Game::GetB2World()->RayCast(this, pos, EndPoint);

	Visualizer::AddLineWorld(pos, EndPoint);
	Visualizer::AddLineWorld(pos, EndPointLeft);
	Visualizer::AddLineWorld(pos, EndPointRight);

	if (GroundDetected)
	{
		float dist = pos.y - GroundPoint.y;
		float pushDist = HoverHeight - dist + ExtraSpacing;

		Visualizer::AddMarkerWorld(pos - b2Vec2(0, dist));

		// Undamped spring
		//this->pBody->ApplyForceToCenter(b2Vec2(0, SpringConstant * pushDist), true);

		// Damped spring
		float dampingTerm = -3.0f * this->pBody->GetMass() * this->pBody->GetLinearVelocity().y;
		this->pBody->ApplyForceToCenter(b2Vec2(0, SpringConstant * pushDist + dampingTerm), true);
		//
	}
	//*/

	//*  Controls for extreme rotation 
	float CurrAngle = this->pBody->GetAngle();
	float ClampeAng = b2Clamp(CurrAngle, -45 * MATH_PI_180, 45 * MATH_PI_180);
	if (ClampeAng != CurrAngle)
	{
		this->pBody->SetTransform(this->pBody->GetPosition(), CurrAngle);
		this->pBody->SetAngularVelocity(0);
	}

	// Realign to 0 deg
	float totalRotation = -this->pBody->GetAngle(); // Note the minus sign 
	float change = 1 * MATH_PI_180; //allow 1 degree rotation per time step
	totalRotation = b2Clamp<float>(totalRotation, -change, change);
	float newAngle = this->pBody->GetAngle() + totalRotation;
	this->pBody->SetTransform(this->pBody->GetPosition(), newAngle);
	//*/

	// **** IMPORTANT ****: Don't forget to call the base class Update!!!!!!!!
	GameObject2D::Update(t);
}


float32 Hovercraft::ReportFixture(b2Fixture*, const b2Vec2& point, const b2Vec2&, float32 fraction)
{
	GroundDetected = true;
	GroundPoint = point;
	return fraction;  // find the closest point
}
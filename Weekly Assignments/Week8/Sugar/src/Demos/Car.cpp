#include "Car.h"
#include "GenericBlock.h"
#include "GameObjectMan.h"
#include "Gear.h"
#include "Game.h"
#include "Keyboard.h"

Car::Car(float x, float y)
{
	pCarBody = new GenericBlock(x,y,0, (float)CarWidth, (float)CarHeight,GameObjectName::Block,ImageName::Long_Wood_Block);
	GameObjectMan::Add(pCarBody, GameObjectName::MainGroup);
	//pCarBody->GetBody()->SetType(b2_staticBody);

	pRear = new Gear(x - .8f*CarWidth, y - 1.5f*CarHeight, 0, (float)WheelRadius, GameObjectName::Block, ImageName::GearSmall);
	GameObjectMan::Add(pRear, GameObjectName::MainGroup);
	//pRear->GetBody()->SetType(b2_staticBody);

	pFront = new Gear(x + .8f*CarWidth, y - 1.5f*CarHeight, 0, (float)WheelRadius, GameObjectName::Block, ImageName::GearSmall);
	GameObjectMan::Add(pFront, GameObjectName::MainGroup);
	//pFront->GetBody()->SetType(b2_staticBody);

	//*
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pCarBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	pRearWheel = (b2RevoluteJoint*) Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	pFrontWheel = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/

	/*
	b2WheelJointDef rjdef;
	rjdef.Initialize(pCarBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	rjdef.frequencyHz = 5;
	rjdef.dampingRatio = .19f;
	pRearWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	//rjdef.Initialize(pCarBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(-1, -1));
	rjdef.enableMotor = true;
	pFrontWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/


	speed = 0;
}

void Car::Update()
{
	DebugMsg::out("Wheel Speed: %f\n", speed);
	pFrontWheel->SetMotorSpeed(speed);
	pRearWheel->SetMotorSpeed(speed);
}

void Car::Forward()
{
	speed -= SpeedDelta;
}

void Car::Backward()
{
	speed += SpeedDelta;
}

void Car::Break()
{
	speed = 0;
}

void Car::Coast()
{
	speed = .95f * speed;
}

Car::~Car()
{
	GameObjectMan::Delete( pFront );
	GameObjectMan::Delete(pRear);
	GameObjectMan::Delete(pCarBody);
}
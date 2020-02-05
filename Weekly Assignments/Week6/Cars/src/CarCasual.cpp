#include "CarCasual.h"
#include "CarBodyCasual.h"
#include "GameObjectMan.h"
#include "Wheel.h"
#include "Game.h"
#include "Keyboard.h"

CarCasual::CarCasual(float x, float y)
{
	pCarCasualBody = new CarBodyCasual(x, y, 0);
	GameObjectMan::Add(pCarCasualBody, GameObjectName::MainGroup);
	//pCarCasualBody->GetBody()->SetType(b2_staticBody);

	pRear = new Wheel(x - .27f*CarCasualWidth, y - .35f*CarCasualHeight, 0);
	GameObjectMan::Add(pRear, GameObjectName::MainGroup);
	//pRear->GetBody()->SetType(b2_staticBody);

	pFront = new Wheel(x + .35f*CarCasualWidth, y - .35f*CarCasualHeight, 0);
	GameObjectMan::Add(pFront, GameObjectName::MainGroup);
	//pFront->GetBody()->SetType(b2_staticBody);

	//*
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pCarCasualBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	pRearWheel = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarCasualBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	pFrontWheel = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/

	/*
	b2WheelJointDef rjdef;
	rjdef.Initialize(pCarCasualBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	rjdef.frequencyHz = 5;
	rjdef.dampingRatio = .19f;
	pRearWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarCasualBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	//rjdef.Initialize(pCarCasualBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(-1, -1));
	rjdef.enableMotor = true;
	pFrontWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/


	speed = 0;
}

void CarCasual::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		Forward();
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		Backward();
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		Break();
	}
	else
	{
		Coast();
	}
	DebugMsg::out("Wheel Speed: %f\n", speed);
	pFrontWheel->SetMotorSpeed(speed);
	pRearWheel->SetMotorSpeed(speed);
}

GameObject2D* CarCasual::getBody()
{
	return pCarCasualBody;
}

void CarCasual::Forward()
{
	speed -= SpeedDelta;
	if (speed < -SpeedLimit)
		speed = -SpeedLimit;
}

void CarCasual::Backward()
{
	speed += SpeedDelta;
	if (speed > SpeedLimit / 2)
		speed = SpeedLimit / 2;
}

void CarCasual::Break()
{
	speed = 0;
}

void CarCasual::Coast()
{
	speed = .95f * speed;
}

CarCasual::~CarCasual()
{
	delete pFront;
	delete pRear;
	delete pCarCasualBody;
}
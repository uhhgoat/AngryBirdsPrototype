#include "CarOffroad.h"
#include "CarBodyOffroad.h"
#include "GameObjectMan.h"
#include "WheelBig.h"
#include "Game.h"
#include "Keyboard.h"

CarOffroad::CarOffroad(float x, float y)
{
	pCarOffroadBody = new CarBodyOffroad(x, y, 0);
	GameObjectMan::Add(pCarOffroadBody, GameObjectName::MainGroup);
	//pCarOffroadBody->GetBody()->SetType(b2_staticBody);

	pRear = new WheelBig(x - .34f*CarOffroadWidth, y - .525f*CarOffroadHeight, 0);
	GameObjectMan::Add(pRear, GameObjectName::MainGroup);
	//pRear->GetBody()->SetType(b2_staticBody);

	pFront = new WheelBig(x + .33f*CarOffroadWidth, y - .525f*CarOffroadHeight, 0);
	GameObjectMan::Add(pFront, GameObjectName::MainGroup);
	//pFront->GetBody()->SetType(b2_staticBody);

	/*
	b2RevoluteJointDef rjdef;
	rjdef.Initialize(pCarOffroadBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	pRearWheel = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarOffroadBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter());
	rjdef.enableMotor = true;
	pFrontWheel = (b2RevoluteJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/

	//*
	b2WheelJointDef rjdef;
	rjdef.Initialize(pCarOffroadBody->GetBody(), pRear->GetBody(), pRear->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	rjdef.enableMotor = true;
	rjdef.maxMotorTorque = 1000;
	rjdef.frequencyHz = 5;
	rjdef.dampingRatio = .19f;
	pRearWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);

	rjdef.Initialize(pCarOffroadBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(0, 1));
	//rjdef.Initialize(pCarOffroadBody->GetBody(), pFront->GetBody(), pFront->GetBody()->GetWorldCenter(), b2Vec2(-1, -1));
	rjdef.enableMotor = true;
	pFrontWheel = (b2WheelJoint*)Game::GetB2World()->CreateJoint(&rjdef);
	//*/


	speed = 0;
}

void CarOffroad::Update()
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

GameObject2D* CarOffroad::getBody()
{
	return pCarOffroadBody;
}

void CarOffroad::Forward()
{
	speed -= SpeedDelta;
	if (speed < -SpeedLimit)
		speed = -SpeedLimit;
}

void CarOffroad::Backward()
{
	speed += SpeedDelta;
	if (speed > SpeedLimit / 2)
		speed = SpeedLimit / 2;
}

void CarOffroad::Break()
{
	speed = 0;
}

void CarOffroad::Coast()
{
	speed = .95f * speed;
}

CarOffroad::~CarOffroad()
{
	delete pFront;
	delete pRear;
	delete pCarOffroadBody;
}
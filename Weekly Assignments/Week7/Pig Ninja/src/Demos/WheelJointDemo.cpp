#include "WheelJointDemo.h"
#include "Car.h"
#include "GenericBlock.h"
#include "GameObjectMan.h"
#include "Keyboard.h"

WheelJointDemo::WheelJointDemo()
{
	pGround = new GenericBlock(400, 50, 0.01f, 10000, 30, GameObjectName::Block, ImageName::Glass_Block);
	pGround->GetBody()->SetType(b2_staticBody);
	GameObjectMan::Add(pGround, GameObjectName::MainGroup);

	pCar = new Car(400, 300);
}

void WheelJointDemo::Update()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		pCar->Forward();
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		pCar->Backward();
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		pCar->Break();
	}
	else
	{
		pCar->Coast();
	}

	pCar->Update();
}

WheelJointDemo::~WheelJointDemo()
{
	delete pCar;
	GameObjectMan::Delete( pGround );
}
#include "AutoCam.h"
#include "Includes.h"
AutoCam::AutoCam(b2Vec2 start)
{
	manualLocation = start;
}

void AutoCam::SetAuto()
{
	currentState = AUTO;
}
void AutoCam::SetManual()
{
	currentState = MANUAL;
}
void AutoCam::Return()
{
	currentState = RETURNING;
}

void AutoCam::Update(b2Vec2 cen1, b2Vec2 cen2)
{
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);

	Vect camPos;
	Vect lookAt;
	Vect camUp;
	Vect camRight;
	pCam->getPos(camPos);
	pCam->getLookAt(lookAt);
	pCam->getUp(camUp);
	pCam->getRight(camRight);
	camUp = Vect(0, 1, 0);

	b2Vec2 manualCenter = manualLocation;

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		currentState = MANUAL;
		//shift left up to a point
		manualCenter.x -= scrollSpeed;
		if (manualCenter.x <= maxLeft)
			manualCenter.x = maxLeft;
		manualLocation = manualCenter;
		manualCenter.x -= pCam->getScreenWidth() / 2;
		manualCenter.y -= pCam->getScreenHeight() / 2;

		camPos.set(manualCenter.x, manualCenter.y, camPos.Z());
		lookAt.set(manualCenter.x, manualCenter.y, lookAt.Z());

		pCam->setOrientAndPosition(camUp, lookAt, camPos);
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		currentState = MANUAL;
		//shift right to a point
		manualCenter.x += scrollSpeed;
		if (manualCenter.x >= maxRight)
			manualCenter.x = maxRight;
		manualLocation = manualCenter;
		manualCenter.x -= pCam->getScreenWidth() / 2;
		manualCenter.y -= pCam->getScreenHeight() / 2;

		camPos.set(manualCenter.x, manualCenter.y, camPos.Z());
		lookAt.set(manualCenter.x, manualCenter.y, lookAt.Z());

		pCam->setOrientAndPosition(camUp, lookAt, camPos);
	}


	if (currentState == AUTO)
	{
		manualLocation = cen2;

		b2Vec2 center = 0.5f * (cen2 + cen1);

		if (manualLocation.x >= maxRight)
		{
			manualLocation.x = maxRight;
			center.x = maxRight;
			currentState = RETURNING;
		}
		if (manualLocation.x <= maxLeft - 200)
		{
			manualLocation.x = maxLeft;
			center.x = maxLeft;
			currentState = MANUAL;
		}
		center.x -= pCam->getScreenWidth() / 2;
		center.y -= pCam->getScreenHeight() / 2;
		camPos.set(center.x, center.y, camPos.Z());
		lookAt.set(center.x, center.y, lookAt.Z());


		pCam->setOrientAndPosition(camUp, lookAt, camPos);

	}

	if (currentState == RETURNING)
	{
		manualCenter.x -= scrollSpeed * 2;
		bool isBack = false;
		if (manualCenter.x <= maxLeft)
		{
			manualCenter.x = maxLeft;
			isBack = true;
		}
		manualLocation = manualCenter;
		manualCenter.x -= pCam->getScreenWidth() / 2;
		manualCenter.y -= pCam->getScreenHeight() / 2;

		camPos.set(manualCenter.x, manualCenter.y, camPos.Z());
		lookAt.set(manualCenter.x, manualCenter.y, lookAt.Z());

		pCam->setOrientAndPosition(camUp, lookAt, camPos);

		if (isBack)
		{
			currentState = AUTO;
		}
	}



}
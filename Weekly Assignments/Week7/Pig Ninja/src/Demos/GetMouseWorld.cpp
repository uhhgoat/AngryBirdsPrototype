#include "GetMouseWorld.h"
#include "Game.h"
#include "CameraMan.h"
#include "Mouse.h"
#include "PixelToMeter.h"

b2Vec2 GetMouseWorld()
{
	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(xPos, yPos);

	Vect campos;
	pCam->getPos(campos);

	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactorX = currwidth / pCam->getScreenWidth();
	xPos = ScaleFactorX * xPos - .5f * (currwidth - pCam->getScreenWidth()) + campos[x];

	float currheight = pCam->getMaxY() - pCam->getMinY();
	float ScaleFactorY = currheight / pCam->getScreenHeight();
	yPos = ScaleFactorY * yPos - .5f * (currheight - pCam->getScreenHeight()) + campos[y];

	//DebugMsg::out("Bird: x = %f, y = %f \tMouse: x = %f, y = %f\n", pGobj->posX, pGobj->posY, xPos, yPos );

	return b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));
}
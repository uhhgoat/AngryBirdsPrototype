#include <string>
#include "GameObject2D.h"
#include "CameraMan.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "DebugOut.h"
#include "InputTest.h"
#include "PixelToMeter.h"
#include "AudioManager.h"
#include "SimpleRayCastCallBack.h"
#include "GetMouseWorld.h"
#include "Visualizer.h"
#include "Game.h"
#include "SlashLine.h"
#include "GameObjectMan.h"
#include "GenericBlock.h"

void RayCastQuery(SimpleRayCastCallBack* rccb)
{
	static bool LeftButtonDown = false;
	static b2Vec2 prevPos;

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && !LeftButtonDown)
	{
		// begin capture
		prevPos = GetMouseWorld();		// Start of the line
		//DebugMsg::out("Line: Begin\n");
		LeftButtonDown = true;
	}
	else if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		// continue capture
		b2Vec2 WorldMousePos = GetMouseWorld(); // End of the line
		
												// If mouse has actually moved
		if ((WorldMousePos - prevPos).LengthSquared() > .01f)
		{

			//CREATE OBJECT BETWEEN prevPos and WORLDMOUSEPOS FOR LINE
			//calculate pos, width, angle
			b2Vec2 center = prevPos + (0.5f* (WorldMousePos - prevPos));
			center = b2Vec2(MeterToPixel(center.x), MeterToPixel(center.y));
			b2Vec2 widthVector = (WorldMousePos - prevPos);
			widthVector = b2Vec2(MeterToPixel(widthVector.x), MeterToPixel(widthVector.y));
			float width = widthVector.Length();
			float rotation = atan2(WorldMousePos.y - prevPos.y, WorldMousePos.x - prevPos.x);
	
			SlashLine* pGround = new SlashLine(center.x, center.y, rotation, width, 5, GameObjectName::Block, ImageName::Short_Stone_Block);
			GameObjectMan::Add(pGround, GameObjectName::MainGroup);


			// Debug view
			Visualizer::AddLineWorld(prevPos, WorldMousePos);

			// Query the line
			Game::GetB2World()->RayCast(rccb, prevPos, WorldMousePos);
			rccb->ProcessList();

			//DebugMsg::out("Line: (%.2f, %.2f) - (%.2f, %.2f)\n", prevPos.x, prevPos.y, WorldMousePos.x, WorldMousePos.y);
			LeftButtonDown = true;
			prevPos = WorldMousePos; // next line's start point
		}

	}
	else if (!Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		// end capture
		rccb->ClearList();

		//DebugMsg::out("Line: End\n");
		LeftButtonDown = false;

		// Debug view
		Visualizer::ClearLines();
	}
};

void MouseControlTest()
{
	static bool LeftButtonDown = false; // Should all be part of a proper input processor

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && !LeftButtonDown)
	{
		DebugMsg::out("Left Button: Begin\n");
		// Insert code for ‘begin’ operation
		LeftButtonDown = true;
	}
	else if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		DebugMsg::out("Left button held\n");
		// Insert code for ‘drag’ operation
	}
	else if (!Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && LeftButtonDown)
	{
		DebugMsg::out("Left Button: End\n");
		// Insert code for ‘end’ operation
		LeftButtonDown = false;
	}
};

void AudioTests()
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_M))
	{
		AudioManager::StartMusic();
	}

	static bool keydown = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_B) && !keydown)
	{
		AudioManager::BirdSquawk();
		keydown = true;
	}
	else
	{
		keydown = Keyboard::GetKeyState(AZUL_KEY::KEY_B);
	}
}

enum PositionState
{
	INSIDE,
	OUTSIDE,
	UNKNOWN
};

enum MouseState
{
	RIGHT,
	LEFT,
	NONE
};

enum BirdState
{
	NORMAL,
	DRAGGED,
	IMPULSE_HIGH_ANGLE,
	IMPULSE_LOW_ANGLE,
};

void CameraControls()
{
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	Vect pos;
	Vect lookAt;
	Vect up;
	Vect right;
	pCam->getPos(pos);
	pCam->getLookAt(lookAt);
	pCam->getUp(up);
	pCam->getRight(right);

	float movespeed = 2.0f;

	// crazy spin...
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_BACKSPACE))
	{
		Matrix rot = Matrix(ROT_Z, .01f);
		up = up * rot;
		pCam->setOrientAndPosition(up, lookAt, pos);
	}
	else
	{
		up = Vect(0, 1, 0);
		pCam->setOrientAndPosition(up, lookAt, pos);
	}

	// Left-right controls
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_RIGHT))
	{
		pos += right * movespeed;
		lookAt += right * movespeed;
		pCam->setOrientAndPosition(up, lookAt, pos);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_LEFT))
	{
		pos -= right * movespeed;
		lookAt -= right * movespeed;
		pCam->setOrientAndPosition(up, lookAt, pos);
	}


	float MinX = pCam->getMinX();
	float MaxX = pCam->getMaxX();
	float MinY = pCam->getMinY();
	float MaxY = pCam->getMaxY();

	float zoomUp = 1.01f;
	float zoomDown = .99f;

	// Zoom in/out controls
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_DOWN))
	{
		pCam->setOrthographic(zoomUp*MinX, zoomUp*MaxX, zoomUp*MinY, zoomUp*MaxY, 1, 1000);
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_ARROW_UP))
	{
		pCam->setOrthographic(zoomDown*MinX, zoomDown*MaxX, zoomDown*MinY, zoomDown*MaxY, 1, 1000);
	}


}

static BirdState bodyState = NORMAL;

void KeyboardResetBird(GameObject2D *pGobj)
{
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE))
	{
		bodyState = NORMAL;
		b2Vec2 pos(PixelToMeter(50), PixelToMeter(50));

		b2Body* pbod = pGobj->GetBody();

		pbod->SetTransform(pos, 0.7f);
		pbod->SetActive(false);
		pbod->SetAngularVelocity(0.0f);
		pbod->SetLinearVelocity(b2Vec2(0, 0));
	}

}

void MouseApplyImpulse(GameObject2D *pGobj)
{
	MouseState mstate = NONE;
	PositionState pstate = UNKNOWN;

	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(xPos, yPos);

	//------------ Pixel Correction based on Camera ------------------------
	Vect campos;
	pCam->getPos(campos);

	//xPos = xPos + campos[x];  // Corrects for left-rigth cam position (not enough for zoom though)

	/*
	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactor = currwidth / pCam->getScreenWidth();

	// Corrects for left-rigth cam position (also adjusting for zoom)
	xPos = ScaleFactor * (xPos)									// converts window pixels to view pixels
				- 0.5f * (currwidth - pCam->getScreenWidth()) 	// Offsets the location of origin based on view dimension
				+ campos[x]										// Corrects for camera position
				;
	//*/

	/*
	// Corrects for up=down cam position (also adjusting for zoom)
	float currheight = pCam->getMaxY() - pCam->getMinY();
	yPos = ScaleFactor * yPos								// converts window pixels to view pixels
		- .5f * (currheight - pCam->getScreenHeight())		// Offsets the location of origin based on view dimension
		+ campos[y];										// Corrects for camera position
	//*/
	
	//DebugMsg::out("Bird: x = %f, y = %f \tMouse: x = %f, y = %f\n", pGobj->posX, pGobj->posY, xPos, yPos);

	//--------------------------------------------------------

	b2Vec2 WorldMousePos = b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));

	// inside bird?
	b2Body *pBody = pGobj->GetBody();

	b2Fixture *pFix = pBody->GetFixtureList();
	assert(pFix->GetNext() == 0);

	if (pFix->TestPoint(b2Vec2(WorldMousePos)))
	{
		pstate = INSIDE;
	}
	else
	{
		pstate = OUTSIDE;
	}

	mstate = NONE;
	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT))
	{
		mstate = RIGHT;
	}

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		mstate = LEFT;
	}


	if (mstate == LEFT && pstate == INSIDE)
	{
		bodyState = IMPULSE_LOW_ANGLE;
	}

	if (bodyState == IMPULSE_LOW_ANGLE && !pBody->IsActive())
	{
		bodyState = NORMAL;
		b2Vec2 unitVect(1, 1);
		unitVect.Normalize(); // defining direction as a unit vector
		float mag = 12.0f;
		b2Vec2 imp = mag * pBody->GetMass() * unitVect;

		// Impulses are given in N*s so we can give it once only and Box2D takes over
		pBody->ApplyLinearImpulse(imp, pBody->GetWorldCenter(), true);

		// The impulse must be applied to a specific point on the body
		// Off-center impulse create additional torque
		//pBody->ApplyLinearImpulse(imp, WorldMousePos, true);

		// Apply a force once only won't do any good (see below)
		//pBody->ApplyForceToCenter(b2Vec2(0, 12 * pBody->GetMass()), true);

		pBody->SetActive(true);
	}

	// Forces should be applied over time
	//pBody->ApplyForceToCenter(b2Vec2(0, 12 * pBody->GetMass()), true);

	if (mstate == RIGHT && pstate == INSIDE)
	{
		bodyState = IMPULSE_HIGH_ANGLE;
	}

	if (bodyState == IMPULSE_HIGH_ANGLE && !pBody->IsActive())
	{
		bodyState = NORMAL;
		b2Vec2 unitVect(0.3f, 1);
		unitVect.Normalize();  // defining direction as a unit vector
		float mag = 160.0f;
		b2Vec2 imp = mag * unitVect;

		pBody->ApplyLinearImpulse(imp, pBody->GetWorldCenter(), true);

		pBody->SetActive(true);
	}


}

void KeyboardTest()
{
	// Quick and dirty test, if these work the rest do.
	// ---> try a,s,d,<SPACE> keys
	std::string a;
	std::string b;
	std::string c;
	std::string d;

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_A))
	{
		a = " A";
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_S))
	{
		b = " S";
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_D))
	{
		c = " D";
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE))
	{
		d = " <SPACE>";
	}

	std::string total = a + b + c + d;
	DebugMsg::out("Key:%s \n", total.c_str());

}

void MouseTest(GameObject2D *pGobj)
{
	MouseState mstate = NONE;
	PositionState pstate = UNKNOWN;
	bodyState = NORMAL;

	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);

	// Important: inverts the y values to get 0,0 at bottom left.
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(xPos,yPos);    
	DebugMsg::out("mouse: (%d,%d) \n", (int)xPos, (int)yPos);

	// inside bird?
	b2Body *pBody = pGobj->GetBody();

	b2Fixture *pFix = pBody->GetFixtureList();
	assert(pFix->GetNext() == 0); // for simplicity, we're only testing a single fixture here. 

	if (pFix->TestPoint(b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos))))
	{
		pstate = INSIDE;
	}
	else 
	{
		pstate = OUTSIDE;
	}

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT))
	{
		mstate = RIGHT;
	}

	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		mstate = LEFT;
	}


	if (mstate == LEFT && pstate == INSIDE)
	{
		bodyState = DRAGGED;
		pBody->SetActive(false);
	}

	if (mstate == LEFT)
	{
		if (bodyState == DRAGGED)
		{
			b2Vec2 newPos((PixelToMeter(xPos)),(PixelToMeter(yPos)));
			pBody->SetTransform(newPos, pBody->GetAngle() );
		}
		else
		{
			bodyState = NORMAL;
			pBody->SetActive(true);
		}
	}



}


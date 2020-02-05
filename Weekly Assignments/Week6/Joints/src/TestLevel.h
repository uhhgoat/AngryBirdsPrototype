#pragma once
#include "Includes.h"
class TestLevel
{
	b2World *pWorld;
	bool BUILT;
	SlingShot *sH;
	WoodBlockMed *WBM1;
	WoodBlockMed *WBM2;
	WoodBlockMed *WBM3;
	WoodBlockShort *WBS1;
	WoodBlockShort *WBS2;
	WoodBlockShort *WBS3;
	WoodBlockShort *WBS4;
	WoodBlockShort *WBS5;
	WoodBlockShort *WBS6;
	GlassBlockLong *GBL1;
	GlassBlockLong *GBL2;
	GlassBlockLong *GBL3;
	RedBird *rB;
public:
	TestLevel(b2World *world)
	{
		BUILT = false;
		pWorld = world;
		sH = new SlingShot(200, 500, 0.0f, *pWorld);
	}

	~TestLevel()
	{
		GameObject2D *pObj;
		GameObject2D *pObjNext;
		GameSortBucket* pSortBkt = (GameSortBucket*)GameObjectMan::Find(GameObjectName::Structure);

		pObj = (GameObject2D*)pSortBkt->getChild();
		while (pObj != nullptr)
		{
			pObjNext = (GameObject2D*)pObj->getSibling();

			// here we outright delete all the remaining sticks
			GameObjectMan::Delete(pObj);
			// removes pObj from Manager structure and calls delete on it

			pObj = pObjNext;
		}
	}

	void Update()
	{
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_HOME))
		{
			SetLevel(); // Set the tower
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_END))
		{
			ClearLevel(); // Clean up the current tower
		}
		else if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_RIGHT))
		{
			//MAKE THE SENSOR EXPLOSION HERE
			float xPos;
			float yPos;
			Mouse::GetCursor(xPos, yPos);
			Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
			pCam->CorrectForOrigin(xPos, yPos);
			Blast *b = new Blast(xPos, yPos, 0.0f, *pWorld, true);
			GameObjectMan::Add(b, GameObjectName::MainGroup);

		}

		sH->Update();
	}


	void SetLevel()
	{
		if (!BUILT)
		{
			GBL1 = new GlassBlockLong(450, 100, 0.0f, *pWorld);
			GameObjectMan::Add(GBL1, GameObjectName::MainGroup);
			GBL2 = new GlassBlockLong(950, 100, 0.0f, *pWorld);
			GameObjectMan::Add(GBL2, GameObjectName::MainGroup);
			GBL3 = new GlassBlockLong(1450, 100, 0.0f, *pWorld);
			GameObjectMan::Add(GBL3, GameObjectName::MainGroup);

			


			WBM1 = new WoodBlockMed(900, 360, 0, *pWorld);
			GameObjectMan::Add(WBM1, GameObjectName::Structure);
			WBM2 = new WoodBlockMed(900, 630, 0, *pWorld);
			GameObjectMan::Add(WBM2, GameObjectName::Structure);
			WBM3 = new WoodBlockMed(900, 900, 0, *pWorld);
			GameObjectMan::Add(WBM3, GameObjectName::Structure);


			WBS1 = new WoodBlockShort(800, 230, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS1, GameObjectName::Structure);
			WBS2 = new WoodBlockShort(1000, 230, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS2, GameObjectName::Structure);
			WBS3 = new WoodBlockShort(800, 500, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS3, GameObjectName::Structure);
			WBS4 = new WoodBlockShort(1000, 500, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS4, GameObjectName::Structure);
			WBS5 = new WoodBlockShort(800, 770, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS5, GameObjectName::Structure);
			WBS6 = new WoodBlockShort(1000, 770, MATH_PI2, *pWorld);
			GameObjectMan::Add(WBS6, GameObjectName::Structure);


			rB = new RedBird(450, 900, 0.0f, *pWorld, true);
			GameObjectMan::Add(rB, GameObjectName::Structure);

			BUILT = true;
		}
	}

	void ClearLevel()
	{
		if (BUILT)
		{
			GameObject *pObj;
			GameObject *pObjNext;

			GameSortBucket* pSortBkt = (GameSortBucket*)GameObjectMan::Find(GameObjectName::Structure);

			pObj = (GameObject *)pSortBkt->getChild();
			while (pObj != 0)
			{
				pObjNext = (GameObject *)pObj->getSibling();
				((GameObject2D*)pObj)->MarkForDelete();

				pObj = pObjNext;
			}

			BUILT = false;
		}
	}
};
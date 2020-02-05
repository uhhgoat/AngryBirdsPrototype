#include "Level_1_1.h"
#include "Includes.h"
Level_1_1::Level_1_1(SlingShot* slingshot)
	:Level(slingshot)
{
	BUILT = false;
	//sH = new SlingShot(200, 450, 0.0f);
	sH = slingshot;
}

Level_1_1::~Level_1_1()
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

void Level_1_1::Update()
{


	if (SleepMonitor::isEveryoneAsleep())
	{
		DebugMsg::out("***** ALL CLEAR ***** Do something important...\n");
	}

	//sH->Update();
}

void Level_1_1::SetLevel()
{
	if (!BUILT)
	{
		numPigs = 0;

		AudioManager::MusicOn();

		pF1 = new Platform(1600, 280, 0);
		pF2 = new Platform(1800, 280, 0);
		pF3 = new Platform(1430, 240, MATH_PI8);
		pF4 = new Platform(1970, 240, -MATH_PI8);

		WBT1 = new WoodBlockTiny(1520, 350, MATH_PI2);
		WBT2 = new WoodBlockTiny(1880, 350, MATH_PI2);
		WBT3 = new WoodBlockTiny(1700, 625, 0);
		WBT4 = new WoodBlockTiny(1700, 870, MATH_PI2);

		rP = new RegularPig(1700, 650, 0);
		rP->SetLevel(this);

		WBS1 = new WoodBlockShort(1700, 350, 0);
		WBS2 = new WoodBlockShort(1700, 550, 0);
		WBS3 = new WoodBlockShort(1700, 825, 0);

		WBL1 = new WoodBlockLong(1615, 450, MATH_PI2);
		WBL2 = new WoodBlockLong(1785, 450, MATH_PI2);
		WBL3 = new WoodBlockLong(1700, 575, 0);
		WBL4 = new WoodBlockLong(1650, 700, MATH_PI2);
		WBL5 = new WoodBlockLong(1750, 700, MATH_PI2);

		GBS1 = new GlassBlockShort(1670, 425, MATH_PI2);
		GBS2 = new GlassBlockShort(1730, 425, MATH_PI2);


		GameObjectMan::Add(pF1, GameObjectName::Structure);
		GameObjectMan::Add(pF2, GameObjectName::Structure);
		GameObjectMan::Add(pF3, GameObjectName::Structure);
		GameObjectMan::Add(pF4, GameObjectName::Structure);

		GameObjectMan::Add(WBT1, GameObjectName::Structure);
		GameObjectMan::Add(WBT2, GameObjectName::Structure);
		GameObjectMan::Add(WBT3, GameObjectName::Structure);
		GameObjectMan::Add(WBT4, GameObjectName::Structure);

		GameObjectMan::Add(rP, GameObjectName::Structure);

		GameObjectMan::Add(WBS1, GameObjectName::Structure);
		GameObjectMan::Add(WBS2, GameObjectName::Structure);
		GameObjectMan::Add(WBS3, GameObjectName::Structure);

		GameObjectMan::Add(WBL1, GameObjectName::Structure);
		GameObjectMan::Add(WBL2, GameObjectName::Structure);
		GameObjectMan::Add(WBL3, GameObjectName::Structure);
		GameObjectMan::Add(WBL4, GameObjectName::Structure);
		GameObjectMan::Add(WBL5, GameObjectName::Structure);

		GameObjectMan::Add(GBS1, GameObjectName::Structure);
		GameObjectMan::Add(GBS2, GameObjectName::Structure);



		rB1 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB1, GameObjectName::Structure);
		rB2 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB2, GameObjectName::Structure);
		rB3 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB3, GameObjectName::Structure);



		//FIRST IN SLING
		sH->AddBirdToQueue(rB1);

		//STACK FROM HERE (last in first out)
		sH->AddBirdToQueue(rB2);
		sH->AddBirdToQueue(rB3);


		sH->projTraj->Load();

		BUILT = true;
	}
}

void Level_1_1::ClearLevel()
{
	if (BUILT)
	{
		AudioManager::MusicOff();
		sH->ClearBirdsQueue();
		sH->projTraj->Clear();
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
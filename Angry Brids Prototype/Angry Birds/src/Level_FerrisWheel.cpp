#include "Level_FerrisWheel.h"
#include "Includes.h"
#include "FerrisWheel.h"
Level_FerrisWheel::Level_FerrisWheel(SlingShot* slingshot)
	:Level(slingshot)
{
	BUILT = false;
	//sH = new SlingShot(200, 450, 0.0f);
	sH = slingshot;
}

Level_FerrisWheel::~Level_FerrisWheel()
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

void Level_FerrisWheel::Update()
{


	if (SleepMonitor::isEveryoneAsleep())
	{
		DebugMsg::out("***** ALL CLEAR ***** Do something important...\n");
	}

	//sH->Update();
}

void Level_FerrisWheel::SetLevel()
{
	if (!BUILT)
	{
		numPigs = 0;
		AudioManager::MusicOn();

		ferrisWheel = new FerrisWheel(1700, 300);
		ferrisWheel->SetLevel(this);

		pedestal1 = new WoodBlockLong(1300, 360, MATH_PI2);
		pedestal2 = new WoodBlockLong(2100, 360, MATH_PI2);
		pedestal3 = new WoodBlockLong(1300, 560, MATH_PI2);
		pedestal4 = new WoodBlockLong(2100, 560, MATH_PI2);

		rock1 = new StoneCircle(1295, 720, 0);
		rock2 = new StoneCircle(2095, 720, 0);

		hPig1 = new HelmetPig(1400, 310, 0);
		hPig1->SetLevel(this);
		hPig2 = new HelmetPig(2000, 310, 0);
		hPig2->SetLevel(this);


		GameObjectMan::Add(hPig1, GameObjectName::Structure);
		GameObjectMan::Add(hPig2, GameObjectName::Structure);

		GameObjectMan::Add(pedestal1, GameObjectName::Structure);
		GameObjectMan::Add(pedestal2, GameObjectName::Structure);
		GameObjectMan::Add(pedestal3, GameObjectName::Structure);
		GameObjectMan::Add(pedestal4, GameObjectName::Structure);
		GameObjectMan::Add(rock1, GameObjectName::Structure);
		GameObjectMan::Add(rock2, GameObjectName::Structure);
		

		bB = new BlackBird(450, 900, 0.0f);
		GameObjectMan::Add(bB, GameObjectName::Structure);
		gB = new GreenBird(450, 900, 0.0f);
		GameObjectMan::Add(gB, GameObjectName::Structure);
		yB = new YellowBird(450, 900, 0.0f);
		GameObjectMan::Add(yB, GameObjectName::Structure);



		//FIRST IN SLING
		sH->AddBirdToQueue(bB);

		//STACK FROM HERE (last in first out)
		sH->AddBirdToQueue(yB);
		sH->AddBirdToQueue(gB);
		

		sH->projTraj->Load();

		BUILT = true;
	}
}

void Level_FerrisWheel::ClearLevel()
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
#include "TestLevel.h"
#include "Includes.h"
TestLevel::TestLevel(SlingShot* slingshot)
	:Level(slingshot)
{
	BUILT = false;
	//sH = new SlingShot(200, 450, 0.0f);
	sH = slingshot;
}

TestLevel::~TestLevel()
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

void TestLevel::Update()
{
	

	if (SleepMonitor::isEveryoneAsleep())
	{
		DebugMsg::out("***** ALL CLEAR ***** Do something important...\n");
	}

	//sH->Update();
}

void TestLevel::SetLevel()
{
	if (!BUILT)
	{
		


		AudioManager::MusicOn();

		WBS = new WoodBlockShort(1300, 270, MATH_PI2);
		GameObjectMan::Add(WBS, GameObjectName::Structure);
		WBM = new WoodBlockMed(1400, 430, MATH_PI2);
		GameObjectMan::Add(WBM, GameObjectName::Structure);
		WBL = new WoodBlockLong(1500, 430, MATH_PI2);
		GameObjectMan::Add(WBL, GameObjectName::Structure);
		
		GBS = new GlassBlockShort(1600, 430, MATH_PI2);
		GameObjectMan::Add(GBS, GameObjectName::Structure);
		GBM = new GlassBlockMed(1700, 430, MATH_PI2);
		GameObjectMan::Add(GBM, GameObjectName::Structure);
		GBL = new GlassBlockLong(1800, 430, MATH_PI2);
		GameObjectMan::Add(GBL, GameObjectName::Structure);

		SBS = new StoneBlockShort(1900, 430, MATH_PI2);
		GameObjectMan::Add(SBS, GameObjectName::Structure);
		SBM = new StoneBlockMed(2000, 430, MATH_PI2);
		GameObjectMan::Add(SBM, GameObjectName::Structure);
		SBL = new StoneBlockLong(2100, 430, MATH_PI2);
		GameObjectMan::Add(SBL, GameObjectName::Structure);
		



		rB = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB, GameObjectName::Structure);

		yB = new YellowBird(50, 450, 0.0f);
		GameObjectMan::Add(yB, GameObjectName::Structure);

		wB = new WhiteBird(-50, 450, 0.0f);
		GameObjectMan::Add(wB, GameObjectName::Structure);

		blB = new BlackBird(-50, 500, 0.0f);
		GameObjectMan::Add(blB, GameObjectName::Structure);

		bB = new BlueBird(-50, 400, 0.0f);
		GameObjectMan::Add(bB, GameObjectName::Structure);

		brB = new BigRedBird(-50, 400, 0.0f);
		GameObjectMan::Add(brB, GameObjectName::Structure);

		gB = new GreenBird(-50, 400, 0.0f);
		GameObjectMan::Add(gB, GameObjectName::Structure);

		

		//FIRST IN SLING
		sH->AddBirdToQueue(rB);

		//STACK FROM HERE (last in first out)
		sH->AddBirdToQueue(bB);
		sH->AddBirdToQueue(blB);
		sH->AddBirdToQueue(yB);
		sH->AddBirdToQueue(brB);
		sH->AddBirdToQueue(gB);
		sH->AddBirdToQueue(wB);

		sH->projTraj->Load();

		BUILT = true;
	}
}

void TestLevel::ClearLevel()
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
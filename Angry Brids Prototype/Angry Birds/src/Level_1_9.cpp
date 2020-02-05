#include "Level_1_9.h"
#include "Includes.h"
Level_1_9::Level_1_9(SlingShot* slingshot)
	:Level(slingshot)
{
	BUILT = false;
	//sH = new SlingShot(200, 450, 0.0f);
	sH = slingshot;
}

Level_1_9::~Level_1_9()
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

void Level_1_9::Update()
{


	if (SleepMonitor::isEveryoneAsleep())
	{
		DebugMsg::out("***** ALL CLEAR ***** Do something important...\n");
	}

	//sH->Update();
}

void Level_1_9::SetLevel()
{
	if (!BUILT)
	{
		numPigs = 0;

		AudioManager::MusicOn();

		SBMT1 = new StoneBlockMedThick(1475, 285, 0);
		SBMT2 = new StoneBlockMedThick(1575, 285, 0);
		SBMT3 = new StoneBlockMedThick(1825, 285, 0);
		SBMT4 = new StoneBlockMedThick(1925, 285, 0);

		WBL1 = new WoodBlockLong(1700, 325, 0);

		WBSQ1 = new WoodBlockSquare(1575, 335, 0);
		WBMT1 = new WoodBlockMedThick(1500, 335, 0);
		WBSQ2 = new WoodBlockSquare(1475, 385, 0);
		WBMT2 = new WoodBlockMedThick(1550, 385, 0);

		WBSQ3 = new WoodBlockSquare(1925, 335, 0);
		WBMT3 = new WoodBlockMedThick(1850, 335, 0);
		WBSQ4 = new WoodBlockSquare(1825, 385, 0);
		WBMT4 = new WoodBlockMedThick(1900, 385, 0);

		SBMT5 = new StoneBlockMedThick(1525, 460, MATH_PI2);
		SBMT6 = new StoneBlockMedThick(1875, 460, MATH_PI2);

		WBS1 = new WoodBlockShort(1462.5f, 460, MATH_PI2);
		WBS2 = new WoodBlockShort(1587.5f, 460, MATH_PI2);
		WBS3 = new WoodBlockShort(1812.5f, 460, MATH_PI2);
		WBS4 = new WoodBlockShort(1937.5f, 460, MATH_PI2);

		WBL2 = new WoodBlockLong(1525, 497.5f, 0);
		WBL3 = new WoodBlockLong(1875, 497.5f, 0);

		GBTS1 = new GlassBlockTinySquare(1487.5, 522.5f, 0);
		GBTS2 = new GlassBlockTinySquare(1562.5, 522.5f, 0);
		GBTS3 = new GlassBlockTinySquare(1837.5, 522.5f, 0);
		GBTS4 = new GlassBlockTinySquare(1912.5, 522.5f, 0);

		WBMT5 = new WoodBlockMedThick(1450, 585, MATH_PI2);
		WBMT6 = new WoodBlockMedThick(1600, 585, MATH_PI2);
		WBS5 = new WoodBlockShort(1800, 585, MATH_PI2);
		WBS6 = new WoodBlockShort(1950, 585, MATH_PI2);
		WBS7 = new WoodBlockShort(1962.5f, 585, MATH_PI2);

		WBL4 = new WoodBlockLong(1525, 622.5f, 0);
		WBL5 = new WoodBlockLong(1875, 622.5f, 0);

		GBMT1 = new GlassBlockMedThick(1525, 685, 0);
		GBMT2 = new GlassBlockMedThick(1875, 685, 0);

		GBS1 = new GlassBlockShort(1525, 760, MATH_PI2);
		GBS2 = new GlassBlockShort(1875, 760, MATH_PI2);

		rP1 = new RegularPig(1700, 360, 0);
		rP2 = new RegularPig(1525, 560, 0);
		rP3 = new RegularPig(1875, 560, 0);

		rP1->SetLevel(this);
		rP2->SetLevel(this);
		rP3->SetLevel(this);

		
		GameObjectMan::Add(SBMT1, GameObjectName::Structure);
		GameObjectMan::Add(SBMT2, GameObjectName::Structure);
		GameObjectMan::Add(SBMT3, GameObjectName::Structure);
		GameObjectMan::Add(SBMT4, GameObjectName::Structure);

		GameObjectMan::Add(WBL1, GameObjectName::Structure);

		GameObjectMan::Add(WBSQ1, GameObjectName::Structure);
		GameObjectMan::Add(WBMT1, GameObjectName::Structure);
		GameObjectMan::Add(WBSQ2, GameObjectName::Structure);
		GameObjectMan::Add(WBMT2, GameObjectName::Structure);

		GameObjectMan::Add(WBSQ3, GameObjectName::Structure);
		GameObjectMan::Add(WBMT3, GameObjectName::Structure);
		GameObjectMan::Add(WBSQ4, GameObjectName::Structure);
		GameObjectMan::Add(WBMT4, GameObjectName::Structure);

		GameObjectMan::Add(SBMT5, GameObjectName::Structure);
		GameObjectMan::Add(SBMT6, GameObjectName::Structure);

		GameObjectMan::Add(WBS1, GameObjectName::Structure);
		GameObjectMan::Add(WBS2, GameObjectName::Structure);
		GameObjectMan::Add(WBS3, GameObjectName::Structure);
		GameObjectMan::Add(WBS4, GameObjectName::Structure);

		GameObjectMan::Add(WBL2, GameObjectName::Structure);
		GameObjectMan::Add(WBL3, GameObjectName::Structure);

		GameObjectMan::Add(GBTS1, GameObjectName::Structure);
		GameObjectMan::Add(GBTS2, GameObjectName::Structure);
		GameObjectMan::Add(GBTS3, GameObjectName::Structure);
		GameObjectMan::Add(GBTS4, GameObjectName::Structure);

		GameObjectMan::Add(WBMT5, GameObjectName::Structure);
		GameObjectMan::Add(WBMT6, GameObjectName::Structure);
		GameObjectMan::Add(WBS5, GameObjectName::Structure);
		GameObjectMan::Add(WBS6, GameObjectName::Structure);
		GameObjectMan::Add(WBS7, GameObjectName::Structure);

		GameObjectMan::Add(WBL4, GameObjectName::Structure);
		GameObjectMan::Add(WBL5, GameObjectName::Structure);

		GameObjectMan::Add(GBMT1, GameObjectName::Structure);
		GameObjectMan::Add(GBMT2, GameObjectName::Structure);

		GameObjectMan::Add(GBS1, GameObjectName::Structure);
		GameObjectMan::Add(GBS2, GameObjectName::Structure);
		
		GameObjectMan::Add(rP1, GameObjectName::Structure);
		GameObjectMan::Add(rP2, GameObjectName::Structure);
		GameObjectMan::Add(rP3, GameObjectName::Structure);


		rB1 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB1, GameObjectName::Structure);
		rB2 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB2, GameObjectName::Structure);
		rB3 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB3, GameObjectName::Structure);
		rB4 = new RedBird(450, 900, 0.0f);
		GameObjectMan::Add(rB4, GameObjectName::Structure);




		//FIRST IN SLING
		sH->AddBirdToQueue(rB1);

		//STACK FROM HERE (last in first out)
		sH->AddBirdToQueue(rB2);
		sH->AddBirdToQueue(rB3);
		sH->AddBirdToQueue(rB4);

		sH->projTraj->Load();

		BUILT = true;
	}
}

void Level_1_9::ClearLevel()
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
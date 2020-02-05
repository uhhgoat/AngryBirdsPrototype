#include "TrailPuffFactory.h"
#include "TrailPuff.h"
#include "Game.h"
#include "GameObjectMan.h"

TrailPuffFactory::TrailPuffFactory()
{
	SortName = GameObjectName::EffectsGroup;
	pSort = (GameSortBucket*)GameObjectMan::Find(SortName);
}

GameObject2D* TrailPuffFactory::CreateNew()
{
	return new TrailPuff(this);
}

void TrailPuffFactory::Create(float pixx, float pixy, float ang)
{
	TrailPuff* p = (TrailPuff*) this->GetNew();

	p->SetPosAng(pixx, pixy, ang);

	GameObjectMan::Add(p, SortName);
}

TrailPuffFactory::~TrailPuffFactory()
{
	DebugMsg::out("TrailPuffFactory: Deleting Trail\n");

	GameObject2D *pObj;
	GameObject2D *pObjNext;

	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		GameObjectMan::Delete(pObj);  // removes pObj from Manager structure and calls delete on it

		pObj = pObjNext;
	}
}

void TrailPuffFactory::RecallTrail()
{
	DebugMsg::out("TrailPuffFactory: Recalling Trail\n");

	GameObject2D *pObj;
	GameObject2D *pObjNext;

	pObj = (GameObject2D*)pSort->getChild();

	while (pObj != nullptr)
	{
		pObjNext = (GameObject2D*)pObj->getSibling();

		pObj->MarkForDelete();  

		pObj = pObjNext;
	}
}
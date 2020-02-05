#include "TrailFactory.h"
#include "Trail.h"
#include "Game.h"
#include "GameObjectMan.h"

TrailFactory::TrailFactory()
{
	SortName = GameObjectName::EffectsGroup;
	pSort = (GameSortBucket*)GameObjectMan::Find(SortName);
}

GameObject2D* TrailFactory::CreateNew()
{
	return new Trail(this);
}

Trail* TrailFactory::Create(float pixx, float pixy, float ang, float scale)
{
	Trail* p = (Trail*)this->GetNew();

	p->SetPosAng(pixx, pixy, ang);
	p->scaleX = scale;
	p->scaleY = scale;

	GameObjectMan::Add(p, SortName);

	return p;
}

TrailFactory::~TrailFactory()
{
	DebugMsg::out("TrailFactory: Deleting Trail\n");

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

void TrailFactory::RecallTrail()
{
	DebugMsg::out("TrailFactory: Recalling Trail\n");

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
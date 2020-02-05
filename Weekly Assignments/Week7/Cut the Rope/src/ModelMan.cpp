#include <stdlib.h>
#include <assert.h>



#include "ModelMan.h"

ModelMan::ModelMan()
{
	this->pSpriteModel = new SpriteModel("SpriteModel.azul");
	this->pCircleModel = new CircleModel("CircleModel.azul");
	this->pBoxModel = new BoxModel("BoxModel.azul");
	this->pTriModel = new TriModel("TriModel.azul");
}

Model *ModelMan::GetModel(ModelName::Name name)
{
	ModelMan *pMan = ModelMan::privGetInstance();
	Model *p = 0;
	switch (name)
	{
	case ModelName::Sprite:
		p = pMan->pSpriteModel;
		break;	
	
	case ModelName::Box:
		p = pMan->pBoxModel;
		break;

	case ModelName::Circle:
		p = pMan->pCircleModel;
		break;

	case ModelName::Tri:
		p = pMan->pTriModel;
		break;

	default:
		assert(0);
		break;
	}

	return p;
}

ModelMan * ModelMan::privGetInstance()
{
	// This is where its actually stored (BSS section)
	static ModelMan modelMan;
	return &modelMan;
}

void ModelMan::Terminate()
{
	ModelMan* pMan = privGetInstance();

	delete pMan->pSpriteModel;
	delete pMan->pCircleModel;
	delete pMan->pBoxModel;
	delete pMan->pTriModel;
}

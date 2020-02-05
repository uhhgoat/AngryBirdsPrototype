#include <assert.h>

#include "MathEngine.h"
#include "GameObject.h"

#include "GameObject2D.h"
#include "GraphicsObject_Sprite.h"
#include "AzulHelper.h"
#include "GraphicsObject.h"
#include "PCSNode.h"
#include "Model.h"
#include "PixelToMeter.h"
#include "GameObjectMan.h"

GameObject2D::GameObject2D(GameObjectName::Name _name)
{
	this->pGameSprite = nullptr;
	this->pDebugSprite = nullptr;
	this->DebugShape = Box;

	this->drawSprite = false;
	this->drawDebug = false;

	this->name = _name;
	this->currAngle = 0.0f;
	this->origAngle = 0;
	this->posX = 0.0f;
	this->posY = 0.0f;
	this->scaleX = 1.0f;
	this->scaleY = 1.0f;

	this->origHeight = 0;
	this->origWidth = 0;

	this->pBody = nullptr;
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite  *pGraphicsObject, GraphicsObject_Box *graphicsObject_Box)
{
	assert(pGraphicsObject != nullptr);
	assert(graphicsObject_Box != nullptr);

	this->privBuilder(_name, pGraphicsObject, graphicsObject_Box, DEBUG_SHAPE::Box);
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Circle *graphicsObject_Circle)
{
	assert(graphicsObject != nullptr);
	assert(graphicsObject_Circle != nullptr);

	this->privBuilder(_name, graphicsObject, graphicsObject_Circle, DEBUG_SHAPE::Circle);
}

GameObject2D::GameObject2D(GameObjectName::Name _name, GraphicsObject_Sprite *graphicsObject)
{
	assert(graphicsObject != nullptr);
	this->privBuilder(_name, graphicsObject, nullptr, DEBUG_SHAPE::Box);
}

GameObject2D::GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *pgo, DEBUG_SHAPE _shape)
{
	assert(pgo != nullptr);
	Rect r;

	switch (_shape)
	{
	case GameObject2D::Box:
		r = Rect(pgo->origPosX, pgo->origPosY, pgo->origWidth, pgo->origHeight);
		this->privBuilder(name, pgo, new GraphicsObject_Box(r), DEBUG_SHAPE::Box);
		break;
	case GameObject2D::Circle:
		r = Rect(pgo->origPosX, pgo->origPosY, pgo->origWidth, pgo->origHeight);
		this->privBuilder(name, pgo, new GraphicsObject_Circle(r), DEBUG_SHAPE::Circle);
		break;
	default:
		break;
	}
}

void GameObject2D::privBuilder(GameObjectName::Name _name, GraphicsObject_Sprite* _pgo, GraphicsObject* _pgodebug, DEBUG_SHAPE sh)
{
	this->name = _name;

	this->pGameSprite = _pgo;
	this->pDebugSprite = _pgodebug;
	this->drawSprite = true;
	this->drawDebug = false;
	this->DebugShape = sh;

	this->currAngle = 0.0f;
	this->origAngle = 0;
	this->posX = pGameSprite->origPosX;
	this->posY = pGameSprite->origPosY;

	this->scaleX = 1.0f;
	this->scaleY = 1.0f;

	this->origHeight = pGameSprite->origHeight;
	this->origWidth = pGameSprite->origWidth;

	this->pBody = nullptr;
}

void GameObject2D::SetDebugColor(Color::Type col)
{
	switch (DebugShape)
	{
	case GameObject2D::Box:
		((GraphicsObject_Box*)(this->pDebugSprite))->color = col;
		break;
	case GameObject2D::Circle:
		((GraphicsObject_Circle*)(this->pDebugSprite))->color = col;
		break;
	default:
		break;
	}
}

GameObject2D::~GameObject2D()
{
	delete this->pGameSprite;
	delete this->pDebugSprite;

	//*
	if (pBody != nullptr)
	{
		b2World* pB2World = pBody->GetWorld();
		pB2World->DestroyBody(this->pBody);
	}
	//*/
}

void GameObject2D::WorldUpdate(float currentTime)
{
	AZUL_UNUSED_FLOAT(currentTime);

	// Goal: update the world matrix
	Matrix Scale(MatrixScaleType::SCALE, this->scaleX, this->scaleY, 1.0f);
	Matrix Rot(RotType::ROT_Z, this->currAngle + this->origAngle);
	Matrix Trans(MatrixTransType::TRANS, this->posX, this->posY, 0.0f);

	*this->pWorld = Scale * Rot * Trans;
}

void GameObject2D::Update(float currentTime)
{
	AZUL_UNUSED_FLOAT(currentTime);

	// Goal: update the world matrix
	this->WorldUpdate(currentTime);

	// push to graphics object
	if (this->getGraphicsObject() != 0)
	{
		this->getGraphicsObject()->SetWorld(*this->pWorld);
	}

	// Push to the collision object
	GraphicsObject *pGraphicsObj = this->getGraphicsObject_Collision();
	if (pGraphicsObj != 0)
	{
		pGraphicsObj->SetWorld(*this->pWorld);
	}
}

void GameObject2D::Draw()
{
	if (this->drawSprite && this->getGraphicsObject() != nullptr)
	{
		this->pGameSprite->Render();
	}

	if (this->drawDebug && this->pDebugSprite != nullptr)
	{
		this->pDebugSprite->Render();
	}
}

GraphicsObject *GameObject2D::getGraphicsObject()
{
	return this->pGameSprite;
};

GraphicsObject *GameObject2D::getGraphicsObject_Collision()
{
	return this->pDebugSprite;
};

EnumBase::Name GameObject2D::getName()
{
	return (EnumBase::Name)this->name;
}

void GameObject2D::MarkForDelete()
{
	if (this->deleteMe == false)  // don't add to delete more than once!
	{
		this->deleteMe = true;
		GameObjectMan::AddToDeleteList(this);
	}
}

void GameObject2D::PhysicsUpdate(b2Vec2 posInMeters, float angleInRadians)
{
	// updates position and angle from physics update
	this->posX = MeterToPixel(posInMeters.x);
	this->posY = MeterToPixel(posInMeters.y);
	this->currAngle = angleInRadians;
}
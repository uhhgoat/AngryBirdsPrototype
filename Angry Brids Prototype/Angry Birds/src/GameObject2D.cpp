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
#include "Includes.h"

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

	this->pWakeListener = &AwakeListenerEmpty::NullAwakeListener;
	myAwake = false;
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
	this->origAngle = 0.0f;
	this->posX = pGameSprite->origPosX;
	this->posY = pGameSprite->origPosY;

	this->scaleX = 1.0f;
	this->scaleY = 1.0f;

	this->origHeight = pGameSprite->origHeight;
	this->origWidth = pGameSprite->origWidth;

	this->pBody = nullptr;

	this->pWakeListener = &AwakeListenerEmpty::NullAwakeListener;
	myAwake = false;
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
	if (pBody != nullptr)
	{
		b2World* pB2World = pBody->GetWorld();
		pB2World->DestroyBody(this->pBody);
	}

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
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_LEFT_SHIFT))
	{
		this->SetDrawDebug(true);
	}
	else
	{
		this->SetDrawDebug(false);
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

	this->CheckAwakeState();
}

void GameObject2D::TakeImpact(float damage)
{
	AZUL_UNUSED_FLOAT(damage);
}

void GameObject2D::CollideVisit(Blast&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("Blast hit WoodBlockLong\n");
};
void GameObject2D::CollideVisit(Trail&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("Trail hit WoodBlockLong\n");
};
void GameObject2D::CollideVisit(Background&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("Background hit WoodBlockLong\n");
};
void GameObject2D::CollideVisit(WoodBlockLong&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit WoodBlockLong\n");
};
void GameObject2D::CollideVisit(WoodBlockMed&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit WoodBlockMed\n");
};
void GameObject2D::CollideVisit(WoodBlockShort&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit WoodBlockShort\n");
};
void GameObject2D::CollideVisit(WoodBlockTiny&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(WoodBlockMedThick&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(WoodBlockSquare&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(GlassBlockLong&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit GlassBlockLong\n");
};
void GameObject2D::CollideVisit(GlassBlockMed&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit GlassBlockMed\n");
};
void GameObject2D::CollideVisit(GlassBlockShort&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit GlassBlockShort\n");
};
void GameObject2D::CollideVisit(GlassBlockMedThick&, b2Contact*, const b2ContactImpulse*)
{};

void GameObject2D::CollideVisit(GlassBlockTinySquare&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(RegularPig&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(HelmetPig&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(StoneBlockLong&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit StoneBlockLong\n");
};
void GameObject2D::CollideVisit(StoneBlockMed&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit StoneBlockMed\n");
};
void GameObject2D::CollideVisit(StoneBlockShort&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit StoneBlockShort\n");
};
void GameObject2D::CollideVisit(StoneBlockMedThick&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(StoneCircle&, b2Contact*, const b2ContactImpulse*)
{};
void GameObject2D::CollideVisit(Platform&, b2Contact*, const b2ContactImpulse*)
{};

void GameObject2D::CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Redbird\n");
};
void GameObject2D::CollideVisit(BigRedBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit BigRedbird\n");
};
void GameObject2D::CollideVisit(BlackBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit BlackBird\n");
};
void GameObject2D::CollideVisit(BlueBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit BlueBird\n");
};
void GameObject2D::CollideVisit(GreenBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit GreenBird\n");
};
void GameObject2D::CollideVisit(WhiteBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit WhiteBird\n");
};
void GameObject2D::CollideVisit(YellowBird&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit YellowBird\n");
};
void GameObject2D::CollideVisit(Egg&, b2Contact*, const b2ContactImpulse*)
{
	//DebugMsg::out("GameObject2D hit Egg\n");
};
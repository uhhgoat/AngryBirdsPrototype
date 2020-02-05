#ifndef GAME_OBJECT_2D_H
#define GAME_OBJECT_2D_H

#include "MathEngine.h"
#include "GameObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"

#include "Box2D.h"
#include "PixelToMeter.h"
#include "AwakeListenerBase.h"
#include "TrailFactory.h"
#include "Trajectory.h"

class Background;
class Blast;
class WoodBlockLong;
class WoodBlockMed;
class WoodBlockShort;
class WoodBlockTiny;
class WoodBlockMedThick;
class WoodBlockSquare;
class GlassBlockLong;
class GlassBlockMed;
class GlassBlockShort;
class GlassBlockMedThick;
class GlassBlockTinySquare;
class StoneBlockLong;
class StoneBlockMed;
class StoneBlockShort;
class StoneBlockMedThick;
class StoneCircle;
class Platform;
class BlackBird;
class BlueBird;
class BigRedBird;
class GreenBird;
class RedBird;
class WhiteBird;
class YellowBird;
class Egg;
class Trail;
class RegularPig;
class HelmetPig;

class GameObject2D : public GameObject
{
public:
	enum DEBUG_SHAPE { Box, Circle };

	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Box *graphicsObject_Box);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, GraphicsObject_Circle *graphicsObject_Circle);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject, DEBUG_SHAPE _shape);
	GameObject2D(GameObjectName::Name name, GraphicsObject_Sprite *graphicsObject);
	GameObject2D(GameObjectName::Name name);

	virtual ~GameObject2D() override;

	virtual void Update(float t) override;
	virtual void Draw() override;

	void PhysicsUpdate(b2Vec2 posInMeters, float angleInRadians);

	virtual void WorldUpdate(float currentTime) override;
	virtual EnumBase::Name getName() override;
	virtual GraphicsObject *getGraphicsObject() override;
	virtual GraphicsObject *getGraphicsObject_Collision() override;

	virtual void KillTrail() {};

	virtual void SetFlying() {};

	void MarkForDelete();

	//VISITOR PATTERN
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse) { other; contact; impulse; };
	
	virtual void CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(Egg& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(Trail& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockTiny& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockSquare& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockTinySquare& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(StoneBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(StoneBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(StoneBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(StoneBlockMedThick& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(StoneCircle& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(Platform& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(RegularPig& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(HelmetPig& other, b2Contact* contact, const b2ContactImpulse* impulse);


private:
	GraphicsObject_Sprite *pGameSprite;
	GraphicsObject *pDebugSprite;
	DEBUG_SHAPE DebugShape;
	GameObjectName::Name name;

	bool drawSprite;
	bool drawDebug;

	void privBuilder(GameObjectName::Name name, GraphicsObject_Sprite *pgo, GraphicsObject *pgodebug, DEBUG_SHAPE sh);

	AwakeListenerEmpty* pWakeListener;

protected:
	// Box2D Body
	b2Body *pBody;

	bool myAwake;
	bool blinking = false;
	int frame = 0;
	bool idle = true;

	void SetDebugShape(DEBUG_SHAPE sh) { DebugShape = sh; }
	
public: // Should be protected and with accessors
	float scaleX;
	float scaleY;
	float posX;
	float posY;
	float currAngle;

	// Original Sizes
	float origWidth;
	float origHeight;
	float origAngle;

	void SetAwakeListener(AwakeListenerBase* _pListr) { pWakeListener = _pListr; };
	void CheckAwakeState() { pWakeListener->TriggerCallback(this->pBody); }
	
	GraphicsObject* GetGameSprite() { return pGameSprite; }
	void SetGameSprite(GraphicsObject_Sprite* s) { pGameSprite = s; }

	GraphicsObject* GetDebugSprite() { return pDebugSprite; }
	void SetDebugSprite(GraphicsObject* s) { pDebugSprite = s; }

	void SetDebugColor(Color::Type col);

	GameObjectName::Name GetName() { return name; }
	
	void SetDrawSprite(bool b) { drawSprite = b; }
	void SetDrawDebug(bool b) { drawDebug = b; }

	void SetBody(b2Body* b) { pBody = b; }
	b2Body* GetBody() { return pBody; }
	b2Vec2 GetPosPixel() { return b2Vec2(posX, posY); }
	b2Vec2 GetPosWorld() { return b2Vec2(PixelToMeter(posX), PixelToMeter(posY)); }

	virtual GameObject2D* SpecialAction() { return nullptr; };

	virtual void TakeImpact(float damage);
};


#endif
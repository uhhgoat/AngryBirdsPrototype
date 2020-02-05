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

class Background;
class Blast;
class WoodBlockLong;
class WoodBlockMed;
class WoodBlockShort;
class GlassBlockLong;
class GlassBlockMed;
class GlassBlockShort;
class BlackBird;
class BlueBird;
class BigRedBird;
class GreenBird;
class RedBird;
class WhiteBird;
class YellowBird;

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

	void MarkForDelete();

	//VISITOR PATTERN
	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* impulse) { other; contact; impulse; };
	
	virtual void CollideVisit(Background& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(Blast& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(WoodBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WoodBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockLong& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockMed& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GlassBlockShort& other, b2Contact* contact, const b2ContactImpulse* impulse);

	virtual void CollideVisit(RedBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BigRedBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BlackBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(BlueBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(GreenBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(WhiteBird& other, b2Contact* contact, const b2ContactImpulse* impulse);
	virtual void CollideVisit(YellowBird& other, b2Contact* contact, const b2ContactImpulse* impulse);


private:
	GraphicsObject_Sprite *pGameSprite;
	GraphicsObject *pDebugSprite;
	DEBUG_SHAPE DebugShape;
	GameObjectName::Name name;

	bool drawSprite;
	bool drawDebug;

	void privBuilder(GameObjectName::Name name, GraphicsObject_Sprite *pgo, GraphicsObject *pgodebug, DEBUG_SHAPE sh);


protected:
	// Box2D Body
	b2Body *pBody;

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

	virtual void TakeImpact(float damage);
};


#endif
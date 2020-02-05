#ifndef GAME_OBJECT_2D_H
#define GAME_OBJECT_2D_H

#include "MathEngine.h"
#include "GameObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"

#include "Box2D.h"
#include "DebugOut.h"
#include "PixelToMeter.h"

class BlockWoodLong;
class RedBird;
class GenericBlock;
class Pig;
class StickWood;
class Gear;
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

	virtual void CollideAccept(GameObject2D& , b2Contact* , const b2ContactImpulse* ){};
	virtual void CollideVisit(BlockWoodLong&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(RedBird&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(GenericBlock&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(Pig&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(StickWood&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(Gear&, b2Contact*, const b2ContactImpulse*) {  };
	virtual void CollideVisit(YellowBird&, b2Contact*, const b2ContactImpulse*) {  };

	virtual void GetSliced();

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
	
public: // Should be protected and with accessors
	float scaleX;
	float scaleY;
	float posX;
	float posY;
	float currAngle;

	// Original data
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
};


#endif
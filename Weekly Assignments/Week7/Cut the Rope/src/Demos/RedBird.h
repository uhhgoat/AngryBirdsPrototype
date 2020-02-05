// RedBird
// Andre Berthiaume March 2016

#ifndef _RedBird
#define _RedBird

#include "GameObject2D.h"

class JumpTimerCmd;
class SpriteChangeTimerCmd;

class RedBird : public GameObject2D
{
public:
	RedBird() = delete;
	~RedBird();
	RedBird(const RedBird&) = delete;
	RedBird& operator=(const RedBird&) = delete;

	RedBird(float posx, float posy, float ang);

	virtual void Update(float t) override;

	void AddDamage(float d) { DamageTotal += d; }
	void NextSprite();

	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) override { other.CollideVisit(*this, contact, pimpulse); };
	//virtual void CollideVisit(BlockWoodLong&, b2Contact*, const b2ContactImpulse*) override { DebugMsg::out("RedBird hit BlockWoodLong\n"); };
	virtual void CollideVisit(BlockWoodLong&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;
	virtual void CollideVisit(Pig&, b2Contact* pContact, const b2ContactImpulse* pImpulse) override;

private:
	float DamageTotal;



	// Jumping action
	JumpTimerCmd* pJump;

	// Sprite changing
	GraphicsObject_Sprite** pSpriteArray;
	const int SPRITECOUNT = 2;
	int CurrentSpriteIndex;
	SpriteChangeTimerCmd* pSpriteChangeCmd;
};

#endif _RedBird

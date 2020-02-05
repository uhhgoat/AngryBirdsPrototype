#ifndef _SlashLine
#define _SlashLine

#include "GameObject2D.h"

class SlashLine : public GameObject2D
{
public:
	SlashLine() = delete;
	virtual ~SlashLine() = default;
	SlashLine(const SlashLine&) = delete;
	SlashLine& operator=(const SlashLine&) = delete;

	SlashLine(float posx, float posy, float ang, float width, float height, GameObjectName::Name objname, ImageName::Name imgname);


	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other; contact; pimpulse; };
	virtual void Update(float t) override;

	int lifetime = 30;
};

#endif _SlashLine
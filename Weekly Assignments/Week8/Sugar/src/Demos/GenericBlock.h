// GenericBlock
// Andre Berthiaume, April 2017

#ifndef _GenericBlock
#define _GenericBlock

#include "GameObject2D.h"

class GenericBlock : public GameObject2D
{
public:
	GenericBlock() = delete;
	virtual ~GenericBlock() = default;
	GenericBlock(const GenericBlock&) = delete;
	GenericBlock& operator=(const GenericBlock&) = delete;

	GenericBlock(float posx, float posy, float ang, float width, float height, GameObjectName::Name objname, ImageName::Name imgname );


	virtual void CollideAccept(GameObject2D& other, b2Contact* contact, const b2ContactImpulse* pimpulse) { other.CollideVisit(*this, contact, pimpulse); };
};

#endif _GenericBlock
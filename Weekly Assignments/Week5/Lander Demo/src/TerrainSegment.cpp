#include "TerrainSegment.h"
#include "Includes.h"

TerrainSegment::TerrainSegment(b2Body* body, b2Vec2 left, b2Vec2 right)
	:GameObject2D(GameObjectName::GlassBlockLong)
{
	//calculate pos, width, angle
	b2Vec2 center = left + (0.5f* (right - left));
	float width = (right - left).Length();
	float rotation = atan2(right.y - left.y, right.x - left.x);


	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockLong, Rect(center.x, center.y, width, 5));
	SetGameSprite(pGraphics_Sprite);
	
	origAngle = rotation;
	posX = center.x;
	posY = center.y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(center.x, center.y, width, 5)));
	SetDrawDebug(true);
	SetDrawSprite(true);

	xOff = center.x;
	yOff = center.y;

	//BOX2D STUFF

	// GameObject points to Body
	SetBody(body);

	// Shape
	b2PolygonShape segBox;
	segBox.SetAsBox(
		PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
		b2Vec2(PixelToMeter(xOff), PixelToMeter(yOff)),
		this->origAngle
	);

	// Fixture
	b2FixtureDef SegmentFixtureDef;
	SegmentFixtureDef.shape = &segBox;
	SegmentFixtureDef.density = 0;
	SegmentFixtureDef.friction = 0;
	SegmentFixtureDef.restitution = 0;
	SegmentFixtureDef.userData = this;

	SegmentFixtureDef.filter.categoryBits = FilterCategory::GLASSBLOCK;
	SegmentFixtureDef.filter.maskBits = FilterCategory::BIRD;

	body->CreateFixture(&SegmentFixtureDef);

}
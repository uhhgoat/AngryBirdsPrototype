#include "TerrainSegment.h"
#include "Includes.h"

TerrainSegment::TerrainSegment(b2Body* body, b2Vec2 left, b2Vec2 right, b2Vec2 v0, b2Vec2 v3)
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
	//b2PolygonShape segBox;
	//segBox.SetAsBox(
	//	PixelToMeter(this->origWidth * 0.5f), PixelToMeter(this->origHeight * 0.5f),
	//	b2Vec2(PixelToMeter(xOff), PixelToMeter(yOff)),
	//	this->origAngle
	//);

	//EDGE SHAPE
	b2EdgeShape StickShape;
	b2Vec2 WorldLeft(PixelToMeter(left.x), PixelToMeter(left.y));
	b2Vec2 Worldright(PixelToMeter(right.x), PixelToMeter(right.y));
	b2Vec2 WorldV0(PixelToMeter(v0.x), PixelToMeter(v0.y));
	b2Vec2 WorldV3(PixelToMeter(v3.x), PixelToMeter(v3.y));

	StickShape.Set(WorldLeft, Worldright);
	//ghost vertices
	StickShape.m_vertex0.Set(WorldV0.x, WorldV0.y);
	StickShape.m_vertex3.Set(WorldV3.x, WorldV3.y);
	StickShape.m_hasVertex0 = true;
	StickShape.m_hasVertex3 = true;

	// Fixture
	b2FixtureDef SegmentFixtureDef;
	SegmentFixtureDef.shape = &StickShape;
	SegmentFixtureDef.density = 0;
	SegmentFixtureDef.friction = 0.9f;
	SegmentFixtureDef.restitution = 0;
	SegmentFixtureDef.userData = this;
	

	SegmentFixtureDef.filter.categoryBits = FilterCategory::GLASSBLOCK;
	SegmentFixtureDef.filter.maskBits = FilterCategory::BIRD;

	body->CreateFixture(&SegmentFixtureDef);

}
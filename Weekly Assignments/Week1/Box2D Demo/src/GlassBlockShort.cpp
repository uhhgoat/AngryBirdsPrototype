#include "GlassBlockShort.h"


GlassBlockShort::GlassBlockShort(float x, float y, float rot, b2World &world)
	:GameObject2D(GameObjectName::GlassBlockShort)
{
	//AZUL STUFF
	GraphicsObject_Sprite *pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockShort, Rect(x, y, 200, 40));
	SetGameSprite(pGraphics_Sprite);
	currAngle = rot;
	origAngle = 0;
	posX = x;
	posY = y;
	origHeight = pGraphics_Sprite->origHeight;
	origWidth = pGraphics_Sprite->origWidth;
	SetDebugShape(DEBUG_SHAPE::Box);
	SetDebugSprite(new GraphicsObject_Box(Rect(x, y, 200, 40)));
	SetDrawDebug(false);
	SetDrawSprite(true);

	//BOX2D STUFF
	// BodyDef
	b2BodyDef GroundBoxDef;
	GroundBoxDef.type = b2_staticBody;  // Default value, but I show it here explicitly
	GroundBoxDef.position.Set(PixelToMeter(posX), PixelToMeter(posY));
	GroundBoxDef.angle = currAngle;

	// Body
	b2Body *pGroundBoxBody = world.CreateBody(&GroundBoxDef);  // Bodies manage their own fixtures

															   // Shape
	b2PolygonShape GroundBox;
	GroundBox.SetAsBox(PixelToMeter(origWidth * 0.5f), PixelToMeter(origHeight * 0.5f));

	// Fixture
	pGroundBoxBody->CreateFixture(&GroundBox, 0.0f);

	// GameObject points to Body
	SetBody(pGroundBoxBody);

	// Link the fixture back to the GameOBject2D
	b2Fixture* pGroundFix = pGroundBoxBody->GetFixtureList();  // pointer to the first fixture
	pGroundFix->SetUserData(this);
	pGroundFix->SetFriction(.3f);
}

//void GlassBlockShort::AddScale(float s)
//{
//}
//float GlassBlockShort::GetScale()
//{
//}
//void GlassBlockShort::Rotate(float a)
//{
//
//}
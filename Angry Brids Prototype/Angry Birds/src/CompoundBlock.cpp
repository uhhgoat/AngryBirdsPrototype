#include "CompoundBlock.h"
#include "Game.h"
CompoundBlock::CompoundBlock(float x, float y, float rot, bool showDebugShape)
{
	// Glass Block 1
	GraphicsObject_Sprite* pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockMed, Rect(x, y, 400, 40));
	GameObject2D* pGlassBlock = new GameObject2D(GameObjectName::Structure, pGraphics_Sprite, GameObject2D::Box);
	pGlassBlock->SetDrawDebug(showDebugShape);
	pGlassBlock->origAngle = 0;
	objects.push_front(pGlassBlock);

	// Glass Block 2
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockMed, Rect(x, y, 400, 40));
	GameObject2D* pGlassBlock2 = new GameObject2D(GameObjectName::Structure, pGraphics_Sprite, GameObject2D::Box);
	pGlassBlock2->origAngle = MATH_PI8;
	pGlassBlock2->SetDrawDebug(showDebugShape);
	objects.push_front(pGlassBlock2);

	//*
	// Glass Block 3
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockMed, Rect(x+200, y, 400, 40));
	GameObject2D* pGlassBlock3 = new GameObject2D(GameObjectName::Structure, pGraphics_Sprite, GameObject2D::Box);
	pGlassBlock3->origAngle = -MATH_PI8;
	pGlassBlock3->SetDrawDebug(showDebugShape);
	objects.push_front(pGlassBlock3);

	// Glass Block 4
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::GlassBlockMed, Rect(x, y, 400, 40));
	GameObject2D* pGlassBlock4 = new GameObject2D(GameObjectName::Structure, pGraphics_Sprite, GameObject2D::Box);
	pGlassBlock4->origAngle = 0;
	pGlassBlock4->SetDrawDebug(showDebugShape);
	objects.push_front(pGlassBlock4);

	//*/
	




	// Create one and only one body
	b2BodyDef GlassBlockDef;
	GlassBlockDef.type = b2_dynamicBody;
	GlassBlockDef.position.Set(PixelToMeter(pGlassBlock->posX), PixelToMeter(pGlassBlock->posY));
	GlassBlockDef.angle = rot;

	b2Body *pGlassBlockBody = Game::GetB2World()->CreateBody(&GlassBlockDef);

	// *** Both GameObject2D use the same body ***
	pGlassBlock->SetBody(pGlassBlockBody);
	pGlassBlock2->SetBody(pGlassBlockBody);
	pGlassBlock3->SetBody(pGlassBlockBody);
	pGlassBlock4->SetBody(pGlassBlockBody);

	// create a fixture
	b2PolygonShape GlassBlockBox;
	GlassBlockBox.SetAsBox(
		PixelToMeter(pGlassBlock->origWidth * 0.5f), PixelToMeter(pGlassBlock->origHeight * 0.5f),
		b2Vec2(0, 0),
		pGlassBlock->origAngle
	);

	b2FixtureDef GlassBlockFixtureDef;
	GlassBlockFixtureDef.shape = &GlassBlockBox;
	GlassBlockFixtureDef.density = 5.0f;
	GlassBlockFixtureDef.friction = 0.3f;
	GlassBlockFixtureDef.restitution = 0.50f;
	GlassBlockFixtureDef.userData = pGlassBlock;

	GlassBlockFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GlassBlockFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGlassBlockBody->CreateFixture(&GlassBlockFixtureDef);


	// Create fixture 2
	b2PolygonShape GlassBlock2Box;
	GlassBlock2Box.SetAsBox(
		PixelToMeter(pGlassBlock2->origWidth * 0.5f), PixelToMeter(pGlassBlock2->origHeight * 0.5f),
		b2Vec2( PixelToMeter(25), PixelToMeter(-75)),
		pGlassBlock2->origAngle
	);

	b2FixtureDef GlassBlock2FixtureDef;
	GlassBlock2FixtureDef.shape = &GlassBlock2Box;
	GlassBlock2FixtureDef.density = 5.0f;
	GlassBlock2FixtureDef.friction = 0.3f;
	GlassBlock2FixtureDef.restitution = 0.50f;
	GlassBlock2FixtureDef.userData = pGlassBlock2;

	GlassBlockFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GlassBlockFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGlassBlockBody->CreateFixture(&GlassBlock2FixtureDef);

	// Create fixture 3
	b2PolygonShape GlassBlock3Box;
	GlassBlock3Box.SetAsBox(
		PixelToMeter(pGlassBlock3->origWidth * 0.5f), PixelToMeter(pGlassBlock3->origHeight * 0.5f),
		b2Vec2(PixelToMeter(25), PixelToMeter(-225)),
		pGlassBlock3->origAngle
	);

	b2FixtureDef GlassBlock3FixtureDef;
	GlassBlock3FixtureDef.shape = &GlassBlock3Box;
	GlassBlock3FixtureDef.density = 5.0f;
	GlassBlock3FixtureDef.friction = 0.3f;
	GlassBlock3FixtureDef.restitution = 0.50f;
	GlassBlock3FixtureDef.userData = pGlassBlock3;

	GlassBlockFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GlassBlockFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGlassBlockBody->CreateFixture(&GlassBlock3FixtureDef);

	// Create fixture 4
	b2PolygonShape GlassBlock4Box;
	GlassBlock4Box.SetAsBox(
		PixelToMeter(pGlassBlock4->origWidth * 0.5f), PixelToMeter(pGlassBlock4->origHeight * 0.5f),
		b2Vec2(PixelToMeter(25), PixelToMeter(-300)),
		pGlassBlock4->origAngle
	);

	b2FixtureDef GlassBlock4FixtureDef;
	GlassBlock4FixtureDef.shape = &GlassBlock4Box;
	GlassBlock4FixtureDef.density = 5.0f;
	GlassBlock4FixtureDef.friction = 0.3f;
	GlassBlock4FixtureDef.restitution = 0.50f;
	GlassBlock4FixtureDef.userData = pGlassBlock4;

	GlassBlockFixtureDef.filter.categoryBits = FilterCategory::BLOCK;
	GlassBlockFixtureDef.filter.maskBits = FilterCategory::BIRD | FilterCategory::PIG | FilterCategory::BLOCK;

	pGlassBlockBody->CreateFixture(&GlassBlock4FixtureDef);
}
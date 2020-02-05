#include "SlingShot.h"
SlingShot::SlingShot(float x, float y, float rot, b2World &world, bool showDebugShape)
{
	// Right Side
	GraphicsObject_Sprite* pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::SlingShotRight, Rect(x, y, 38, 200));
	GameObject2D* slingShotRight = new GameObject2D(GameObjectName::BackSling, pGraphics_Sprite, GameObject2D::Box);
	slingShotRight->SetDrawDebug(showDebugShape);
	slingShotRight->origAngle = 0;
	objects.push_front(slingShotRight);

	// Left Side
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::SlingShotLeft, Rect(x, y, 45, 125));
	GameObject2D* slingShotLeft = new GameObject2D(GameObjectName::FrontSling, pGraphics_Sprite, GameObject2D::Box);
	slingShotLeft->origAngle = 0;
	slingShotLeft->SetDrawDebug(showDebugShape);
	objects.push_front(slingShotLeft);

	// Rubber Right
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Sling, Rect(x, y, 150, 18));
	slingRight = new GameObject2D(GameObjectName::BackSling, pGraphics_Sprite, GameObject2D::Box);
	slingRight->origAngle = 0;
	slingRight->SetDrawDebug(showDebugShape);
	objects.push_front(slingRight);

	// Rubber Left
	pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Sling, Rect(x, y, 150, 18));
	slingLeft = new GameObject2D(GameObjectName::FrontSling, pGraphics_Sprite, GameObject2D::Box);
	slingLeft->origAngle = 0;
	slingLeft->SetDrawDebug(showDebugShape);
	objects.push_front(slingLeft);






	// Create one and only one body
	b2BodyDef slingShotDef;
	slingShotDef.type = b2_staticBody;
	slingShotDef.position.Set(PixelToMeter(slingShotRight->posX), PixelToMeter(slingShotRight->posY));
	slingShotDef.angle = rot;

	b2Body *slingShotBody = world.CreateBody(&slingShotDef);

	// *** Both GameObject2D use the same body ***
	slingShotRight->SetBody(slingShotBody);
	slingShotLeft->SetBody(slingShotBody);
	slingRight->SetBody(slingShotBody);
	slingLeft->SetBody(slingShotBody);

	// create a fixture
	b2PolygonShape slingShotRightBox;
	slingShotRightBox.SetAsBox(
		PixelToMeter(slingShotRight->origWidth * 0.5f), PixelToMeter(slingShotRight->origHeight * 0.5f),
		b2Vec2(0, 0),
		slingShotRight->origAngle
	);

	b2FixtureDef slingShotRightFixDef;
	slingShotRightFixDef.shape = &slingShotRightBox;
	slingShotRightFixDef.userData = slingShotRight;

	slingShotRightFixDef.filter.categoryBits = 0;
	slingShotRightFixDef.filter.maskBits = 0;

	slingShotBody->CreateFixture(&slingShotRightFixDef);


	// Create fixture 2
	b2PolygonShape slingShotLeftBox;
	slingShotLeftBox.SetAsBox(
		PixelToMeter(slingShotLeft->origWidth * 0.5f), PixelToMeter(slingShotLeft->origHeight * 0.5f),
		b2Vec2(PixelToMeter(-25), PixelToMeter(40)),
		slingShotLeft->origAngle
	);

	b2FixtureDef slingShotLeftFixDef;
	slingShotLeftFixDef.shape = &slingShotLeftBox;
	slingShotLeftFixDef.userData = slingShotLeft;

	slingShotRightFixDef.filter.categoryBits = 0;
	slingShotRightFixDef.filter.maskBits = 0;

	slingShotBody->CreateFixture(&slingShotLeftFixDef);

	// Create fixture 3
	b2PolygonShape slingRightBox;
	slingRightBox.SetAsBox(
		PixelToMeter(slingRight->origWidth * 0.5f), PixelToMeter(slingRight->origHeight * 0.5f),
		b2Vec2(PixelToMeter(15), PixelToMeter(70)),
		slingRight->origAngle
	);

	b2FixtureDef slingRightFixDef;
	slingRightFixDef.shape = &slingRightBox;
	slingRightFixDef.userData = slingRight;

	slingShotRightFixDef.filter.categoryBits = 0;
	slingShotRightFixDef.filter.maskBits = 0;

	slingShotBody->CreateFixture(&slingRightFixDef);

	// Create fixture 4
	b2PolygonShape slingLeftBox;
	slingLeftBox.SetAsBox(
		PixelToMeter(slingLeft->origWidth * 0.5f), PixelToMeter(slingLeft->origHeight * 0.5f),
		b2Vec2(PixelToMeter(-30), PixelToMeter(70)),
		slingLeft->origAngle
	);

	b2FixtureDef slingLeftFixDef;
	slingLeftFixDef.shape = &slingLeftBox;
	slingLeftFixDef.userData = slingLeft;

	slingShotRightFixDef.filter.categoryBits = 0;
	slingShotRightFixDef.filter.maskBits = 0;

	slingShotBody->CreateFixture(&slingLeftFixDef);


	//add gameobjects to manager in different layers
	GameObjectMan::Add(slingShotRight, GameObjectName::BackSling);
	GameObjectMan::Add(slingShotLeft, GameObjectName::FrontSling);
	GameObjectMan::Add(slingRight, GameObjectName::BackSling);
	GameObjectMan::Add(slingLeft, GameObjectName::FrontSling);

}

void SlingShot::Update()
{
	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT))
	{
		UpdateRubber(slingRight);
		UpdateRubber(slingLeft);
	}
	else
	{
		slingRight->scaleX = 0;
		slingLeft->scaleX = 0;
	}
}

void SlingShot::UpdateRubber(GameObject2D* go)
{
	b2Vec2 Anchor(go->posX, go->posY); // Fixed point of the sling
	float MaxDrawLength = go->origWidth; // max strength of the sling

												// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(xPos, yPos);

	b2Vec2 DrawPoint(xPos, yPos);
	b2Vec2 DrawVector = (Anchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
	float len = DrawVector.Normalize();

	// Cap the sling's extension
	if (len > MaxDrawLength)
	{
		len = MaxDrawLength;
	}

	// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
	// also: http://en.cppreference.com/w/c/numeric/math/atan2
	go->currAngle = atan2f(DrawVector.y, DrawVector.x);

	// rescaling the sprite based on the sling's extension
	go->scaleX = len / MaxDrawLength;

	// Adjust sprite position
	b2Vec2 newCenterPos = Anchor - 0.5f * len * DrawVector;
	go->posX = newCenterPos.x;
	go->posY = newCenterPos.y;
}
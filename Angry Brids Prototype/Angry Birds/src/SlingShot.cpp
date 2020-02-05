#include "SlingShot.h"
#include "Game.h"
SlingShot::SlingShot(float x, float y, float rot, bool showDebugShape)
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

	b2Body *slingShotBody = Game::GetB2World()->CreateBody(&slingShotDef);

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

	state = ShotState::Idle;
	centerAnchor = 0.5f * (slingLeft->GetPosPixel() + slingRight->GetPosPixel());
	centerAnchor.y += 60;
	birdInSlingShot = nullptr;
	birdInFlight = nullptr;
	previousBird = nullptr;

	camFollow = slingShotLeft;

	autoCam = new AutoCam(centerAnchor);

	projTraj = new Trajectory();

	currentLevel = new Level(this);
}

enum PositionState
{
	INSIDE,
	OUTSIDE,
	UNKNOWN
};

//----------SLINGSHOT UPDATE-------------

void SlingShot::Update()
{
	PositionState pstate = UNKNOWN;

	b2Vec2 WorldMousePos = GetMouseWorld();

	mLast = mPressed;
	
	// inside bird?
	if (birdInSlingShot != nullptr)
	{
		b2Body *pBody = birdInSlingShot->GetBody();

		b2Fixture *pFix = pBody->GetFixtureList();
		assert(pFix->GetNext() == 0);

		if (pFix->TestPoint(b2Vec2(WorldMousePos)) || state == ShotState::Drawn)
		{
			pstate = INSIDE;
		}
		else
		{
			pstate = OUTSIDE;
		}
	}


	if (Mouse::GetKeyState(AZUL_MOUSE::BUTTON_LEFT) && pstate == INSIDE)
	{
		UpdateRubber(slingRight);
		UpdateRubber(slingLeft);
		//update bird to match slingshot pull
		UpdateBird();
		state = ShotState::Drawn;
	}
	else
	{
		slingRight->scaleX = 0;
		slingLeft->scaleX = 0;
		if (state == ShotState::Drawn && birdInSlingShot != nullptr)
		{
			ShootBird();
		}
		state = ShotState::Idle;
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE))
	{
		if (birdInFlight != nullptr)
		{
			camFollow = birdInFlight->SpecialAction();
			//previousBird = birdInFlight;
			//camFollow = previousBird;
			birdInFlight = nullptr;
		}
	}
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_HOME))
	{
		currentLevel->SetLevel(); // Set the tower
		autoCam->Return();
	}
	else if (Keyboard::GetKeyState(AZUL_KEY::KEY_END))
	{
		currentLevel->ClearLevel(); // Clean up the current tower
		camFollow = slingLeft;
	}

	mPressed = false;
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_M))
	{
		mPressed = true;
		if(mPressed ^ mLast)
			AudioManager::ToggleMusic();
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_R))
	{
		RedBird* newBird = new RedBird(0, 0, 0);
		GameObjectMan::Add(newBird, GameObjectName::Structure);

		AddBirdToQueue(newBird);

	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_0))
	{
		currentLevel->ClearLevel();
		testLevel = new TestLevel(this);
		currentLevel = testLevel;
		
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_1))
	{
		currentLevel->ClearLevel();
		level1 = new Level_1_1(this);
		currentLevel = level1;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_2))
	{
		currentLevel->ClearLevel();
		level2 = new Level_1_9(this);
		currentLevel = level2;
	}

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_3))
	{
		currentLevel->ClearLevel();
		level3 = new Level_FerrisWheel(this);
		currentLevel = level3;
	}

	if (SleepMonitor::isEveryoneAsleep())
	{
		autoCam->Return();
		camFollow = slingLeft;
	}

	if (camFollow->posY < 0 ||
		camFollow->posY > 1080)
	{
		camFollow = slingLeft;
		autoCam->Return();
	}

	currentLevel->Update();


	autoCam->Update(camFollow->GetPosPixel(), b2Vec2(camFollow->GetPosPixel().x, centerAnchor.y));
}

void SlingShot::UpdateBird()
{
	if (birdInSlingShot != nullptr)
	{

		birdInSlingShot->GetBody()->SetActive(false);
		birdInSlingShot->GetBody()->SetLinearVelocity(b2Vec2(0, 0));
		birdInSlingShot->GetBody()->SetAngularVelocity(0);

		float MaxDrawLength = slingLeft->origWidth;

		float xPos;
		float yPos;
		//Mouse::GetCursor(xPos, yPos);
		//Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
		//pCam->CorrectForOrigin(xPos, yPos);
		b2Vec2 WorldMousePos = GetMouseWorld();
		xPos = MeterToPixel(WorldMousePos.x);
		yPos = MeterToPixel(WorldMousePos.y);


		b2Vec2 DrawPoint(xPos, yPos);
		b2Vec2 DrawVector = (centerAnchor - DrawPoint);  // The 'sling direction' goes from the drawpoint towards the anchor
		float len = DrawVector.Normalize();

		// Cap the extension
		if (len > MaxDrawLength)
		{
			len = MaxDrawLength;
		}

		// Get the sprite angle through Atan2 (you remember? http://facweb.cs.depaul.edu/andre/GAM325/week4.htm )
		// also: http://en.cppreference.com/w/c/numeric/math/atan2
		birdInSlingShot->currAngle = atan2f(DrawVector.y, DrawVector.x);

		// rescaling the sprite based on the sling's extension
		//go->scaleX = len / MaxDrawLength;

		// Adjust sprite position
		b2Vec2 newCenterPos = centerAnchor - len * DrawVector;
		birdInSlingShot->posX = newCenterPos.x;
		birdInSlingShot->posY = newCenterPos.y;
		birdInSlingShot->GetBody()->SetTransform(b2Vec2(PixelToMeter(newCenterPos.x), PixelToMeter(newCenterPos.y)), birdInSlingShot->currAngle);
	}
}

void SlingShot::UpdateRubber(GameObject2D* go)
{
	b2Vec2 Anchor(go->posX, go->posY); // Fixed point of the sling
	float MaxDrawLength = go->origWidth; // max strength of the sling

												// get mouse position
	float xPos;
	float yPos;
	//Mouse::GetCursor(xPos, yPos);
	//Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	//pCam->CorrectForOrigin(xPos, yPos);
	b2Vec2 WorldMousePos = GetMouseWorld();
	xPos = MeterToPixel(WorldMousePos.x);
	yPos = MeterToPixel(WorldMousePos.y);

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

	b2Vec2 trajectory = centerAnchor - birdInSlingShot->GetPosPixel();
	float magnitude = trajectory.Length() / 5.0f;
	trajectory.Normalize();

	projTraj->Trace(go->GetPosWorld(), magnitude*trajectory);
}

void SlingShot::ShootBird()
{
	projTraj->Clear();
	float magnitude;
	float mass = birdInSlingShot->GetBody()->GetMass();
	b2Vec2 trajectory = centerAnchor - birdInSlingShot->GetPosPixel();
	magnitude = trajectory.Length() * mass / 5.0f;
	trajectory.Normalize();
	birdInSlingShot->GetBody()->SetActive(true);
	birdInSlingShot->GetBody()->ApplyLinearImpulseToCenter(magnitude * trajectory, true);
	birdInSlingShot->SetFlying();

	if (previousBird != nullptr)
	{
		previousBird->KillTrail();
	}

	birdInFlight = birdInSlingShot;
	previousBird = birdInFlight;

	birdInSlingShot = nullptr;
	if (!birdsInQueue.empty())
	{
		birdInSlingShot = birdsInQueue.back();
		birdInSlingShot->posX = centerAnchor.x;
		birdInSlingShot->posY = centerAnchor.y;
		birdInSlingShot->GetBody()->SetTransform(b2Vec2(PixelToMeter(centerAnchor.x), PixelToMeter(centerAnchor.y)), birdInSlingShot->currAngle);

		birdsInQueue.pop_back();
	}

	camFollow = birdInFlight;
	autoCam->SetAuto();
	int j = 0;
	for (int i = (int)birdsInQueue.size()-1 ; i >= 0 ; i--)
	{
		GameObject2D *bird = birdsInQueue.at(i);
		bird->posX = centerAnchor.x - (100 * j) - 100;
		bird->posY = centerAnchor.y - 125;
		bird->GetBody()->SetTransform(b2Vec2(PixelToMeter(bird->posX), PixelToMeter(bird->posY)), bird->currAngle);
		j++;
	}

}

void SlingShot::AddBirdToQueue(GameObject2D* bird)
{
	if (birdInSlingShot == nullptr)
	{
		birdInSlingShot = bird;
		birdInSlingShot->GetBody()->SetActive(false);
		birdInSlingShot->posX = centerAnchor.x;
		birdInSlingShot->posY = centerAnchor.y;
		
		birdInSlingShot->GetBody()->SetTransform(b2Vec2(PixelToMeter(centerAnchor.x), PixelToMeter(centerAnchor.y)), birdInSlingShot->currAngle);

	}
	else
	{
		birdsInQueue.push_back(bird);
		int j = 0;
		for (int i = (int)birdsInQueue.size() - 1; i >= 0; i--)
		{
			GameObject2D *b = birdsInQueue.at(i);
			b->posX = centerAnchor.x - (100 * j) - 100;
			b->posY = centerAnchor.y - 125;
			b->GetBody()->SetTransform(b2Vec2(PixelToMeter(b->posX), PixelToMeter(b->posY)), b->currAngle);
			j++;
		}
		bird->GetBody()->SetActive(false);
	}
}

void SlingShot::ClearBirdsQueue()
{
	birdInSlingShot = nullptr;
	birdInFlight = nullptr;
	previousBird = nullptr;
	while (!birdsInQueue.empty())
	{
		birdsInQueue.pop_back();
	}
}

b2Vec2 SlingShot::GetMouseWorld()
{
	// get mouse position
	float xPos;
	float yPos;
	Mouse::GetCursor(xPos, yPos);
	Camera *pCam = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam->CorrectForOrigin(xPos, yPos);

	Vect campos;
	pCam->getPos(campos);

	float currwidth = pCam->getMaxX() - pCam->getMinX();
	float ScaleFactorX = currwidth / pCam->getScreenWidth();
	xPos = ScaleFactorX * xPos - .5f * (currwidth - pCam->getScreenWidth()) + campos[x];

	float currheight = pCam->getMaxY() - pCam->getMinY();
	float ScaleFactorY = currheight / pCam->getScreenHeight();
	yPos = ScaleFactorY * yPos - .5f * (currheight - pCam->getScreenHeight()) + campos[y];

	//DebugMsg::out("Bird: x = %f, y = %f \tMouse: x = %f, y = %f\n", pGobj->posX, pGobj->posY, xPos, yPos );

	return b2Vec2(PixelToMeter(xPos), PixelToMeter(yPos));
}
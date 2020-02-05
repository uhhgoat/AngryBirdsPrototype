#include "Game.h"
#include "Terrain.h"
#include "AutoCam.h"

Game* Game::ptrInstance = nullptr;

 

WoodBlockLong *WBL;
GlassBlockLong *GBL;
WoodBlockMed *WBM;
GlassBlockMed *GBM;
WoodBlockShort *WBS;
GlassBlockShort *GBS;


RedBird* rB;
BlueBird* blB;
YellowBird* yB;
GreenBird* gB;
BlackBird* bkB;
WhiteBird* wB;
BigRedBird* brB;

CompoundBlock* cB;

Terrain* terr;

FlyingBird* fB;

AutoCam* autoCam;

GameSortBucket* pSortBkt;

AngryContactListener* contactListener;

//-----------------------------------------------------------------------------
//  Game::Game()
//		Game Engine Constructor
//-----------------------------------------------------------------------------
Game::Game(const char* windowName, const int Width, const int Height)
	:Engine(windowName, Width, Height)
{
		ptrInstance = this;
		screenWidth = static_cast<float>(Width);
		screenHeight = static_cast<float>(Height);
}

//-----------------------------------------------------------------------------
// Game::Initialize()
//		Allows the engine to perform any initialization it needs to before 
//      starting to run.  This is where it can query for any required services 
//      and load any non-graphic related content. 
//-----------------------------------------------------------------------------
void Game::Initialize()
{
	// Initialize timer
	AzulStopWatch::initStopWatch();

	// Start timer
	stopWatch.tic();
	totalWatch.tic();
	srand(GetTickCount());
	//---------------------------------------------------------------------------------------------------------
	// Box2D setup
	//---------------------------------------------------------------------------------------------------------

	// Gravity in Y direction
	b2Vec2 gravity(0.0, -10.0f);
	pWorld = new b2World(gravity);

	// scale: pixels per meter
	UnitScale::Create(50);

	contactListener = new AngryContactListener();
	pWorld->SetContactListener(contactListener);
}

//-----------------------------------------------------------------------------
// Game::LoadContent()
//		Allows you to load all content needed for your engine,
//	    such as objects, graphics, etc.
//-----------------------------------------------------------------------------
void Game::LoadContent()
{
	//---------------------------------------------------------------------------------------------------------
	// Setup the current 2D orthographic Camera
	//---------------------------------------------------------------------------------------------------------
	Camera *pCam2D = new Camera(Camera::Type::ORTHOGRAPHIC_2D);

	pCam2D->setViewport(0, 0, (int)this->screenWidth, (int)this->screenHeight);
	pCam2D->setOrthographic(-pCam2D->getScreenWidth() / 2.0f, pCam2D->getScreenWidth() / 2.0f,
		-pCam2D->getScreenHeight() / 2.0f, pCam2D->getScreenHeight() / 2.0f,
		1.0f, 1000.0f);
	pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 0.0f));

	// Holder for the current 2D  cameras
	CameraMan::SetCurrentCamera(pCam2D, Camera::Type::ORTHOGRAPHIC_2D);

	//GENERAL LOAD ALL ASSETS
	LoadResources();

	//---------------------------------------------------------------------------------------------------------
	// Sort buckets (AKA sprite layers)
	//---------------------------------------------------------------------------------------------------------
	pSortBkt = new GameSortBucket(GameObjectName::EffectsGroup);
	GameObjectMan::Add(pSortBkt);
	pSortBkt = new GameSortBucket(GameObjectName::MainGroup);
	GameObjectMan::Add(pSortBkt);

	//---------------------------------------------------------------------------------------------------------
	// Create Sprites
	//---------------------------------------------------------------------------------------------------------


	// Sprite

	//cB = new CompoundBlock(900, 800, MATH_PI2, *pWorld, true);
	//cB = new CompoundBlock(500, 800, MATH_PI2, *pWorld, true);
	//cB = new CompoundBlock(1000, 800, MATH_PI, *pWorld, true);
	//GameObjectMan::Add(cB, GameObjectName::MainGroup);

	//WBL = new WoodBlockLong(650, 100, 0.0f, *pWorld);
	//GameObjectMan::Add(WBL, GameObjectName::MainGroup);
	//
	//GBL = new GlassBlockLong(1150, 100, 0.0f, *pWorld);
	//GameObjectMan::Add(GBL, GameObjectName::MainGroup);
	//
	//WBM = new WoodBlockMed(200, 200, -0.2f, *pWorld);
	//GameObjectMan::Add(WBM, GameObjectName::MainGroup);
	//
	//GBM = new GlassBlockMed(1600, 200, 0.2f, *pWorld);
	//GameObjectMan::Add(GBM, GameObjectName::MainGroup);
	//
	//WBS = new WoodBlockShort(650, 500, 0.4f, *pWorld);
	//GameObjectMan::Add(WBS, GameObjectName::MainGroup);
	//
	//GBS = new GlassBlockShort(1900, 500, -0.4f, *pWorld);
	//GameObjectMan::Add(GBS, GameObjectName::MainGroup);
	
	terr = new Terrain(128, -4000, 4000, *pWorld);

	fB = new FlyingBird(200, 2000, 0.0f, *pWorld, true);
	GameObjectMan::Add(fB, GameObjectName::MainGroup);
	

	autoCam = new AutoCam(fB, terr->GetPlatform());

	
	/*
	rB = new RedBird(350, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(rB, GameObjectName::MainGroup);

	blB = new BlueBird(1300, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(blB, GameObjectName::MainGroup);

	gB = new GreenBird(1100, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(gB, GameObjectName::MainGroup);

	yB = new YellowBird(900, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(yB, GameObjectName::MainGroup);

	wB = new WhiteBird(700, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(wB, GameObjectName::MainGroup);

	bkB = new BlackBird(500, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(bkB, GameObjectName::MainGroup);

	brB = new BigRedBird(600, 900, 0.0f, *pWorld, true);
	GameObjectMan::Add(brB, GameObjectName::MainGroup);

	//*/

	//----------------------------------------------------------------------------------------
	// Ground box - Box2D setup
	//----------------------------------------------------------------------------------------

	//CONSOLIDATED INTO CLASS

	//----------------------------------------------------------------------------------------
	// Red Bird - Box2D setup
	//----------------------------------------------------------------------------------------

	//CONSOLIDATED INTO CLASS
	
}

//-----------------------------------------------------------------------------
// Game::Update()
//      Called once per frame, update data, tranformations, etc
//      Use this function to control process order
//      Input, AI, Physics, Animation, and Graphics
//-----------------------------------------------------------------------------
void Game::Update(float currentTime)
{
	// Time update.
	//      Get the time that has passed.
	//      Feels backwards, but its not, need to see how much time has passed
	stopWatch.toc();
	stopWatch.tic();
	totalWatch.toc();

	// Update cameras - make sure everything is consistent
	Camera *pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam2D->updateCamera();

	TimerMan::Update();

	// -------------  Add your update below this line: ----------------------------
	
	// Phase 1: Physics Update - Step world----------------------------
		int velocityIterations = 8;
		int positionIterations = 3;
		float timestep = 1.0f / 60; // 60 fps. Box2D does not recommend tying this to framerate

		// adding some debug controls for the simulation speed
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_P))
		{
			DebugMsg::out("Mode: Pause\n");
			timestep = 0;
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_O))
		{
			DebugMsg::out("Mode: Slow\n");
			timestep = 1.0f / 600;
		}

		pWorld->Step(timestep, velocityIterations, positionIterations);

	// Phase 2: Update the associated GameObjectsd --------------------
		b2Body *pBody = pWorld->GetBodyList();
		while (pBody != 0) // Loop through all the bodies in the Box2D
		{
			b2Fixture *pFix = pBody->GetFixtureList();
			while (pFix != 0) // For each body, loop through all its fixtures
			{
				// For a given fixture, get the associated GameObject2D
				GameObject2D *pGObj = static_cast<GameObject2D*>(pFix->GetUserData());

				b2Vec2 fixCenter;
				if (pBody->IsActive())
				{
					fixCenter = pFix->GetAABB(0).GetCenter();
				}
				else
				{   // Must extract the center this way when body is inactive
					b2AABB tmpAABB;
					pFix->GetShape()->ComputeAABB(&tmpAABB, pBody->GetTransform(), 0);
					fixCenter = tmpAABB.GetCenter();
				}

				float ang = pBody->GetAngle();

				pGObj->PhysicsUpdate(fixCenter, ang);

				pFix = pFix->GetNext();
			}

			pBody = pBody->GetNext();
		}

		autoCam->Update();

	// Phase 3: Let the engine update all the game objects normally
	GameObjectMan::Update(currentTime);

}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	// draw all objects
	GameObjectMan::Draw();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	delete rB;
	delete blB;
	delete gB;
	delete yB;
	delete wB;
	delete bkB;
	delete brB;

	delete WBS;
	delete WBM;
	delete WBL;
	delete GBS;
	delete GBM;
	delete GBL;

	delete terr;

	delete fB;

	delete autoCam;

	delete cB;

	delete pSortBkt;

	delete contactListener;

	// Engine clean-up
	CameraMan::Terminate();
	ModelMan::Terminate();
	ShaderMan::Terminate();
	TextureMan::Terminate();
	ImageMan::Terminate();

	GameObjectMan::Terminate();
	TimerMan::Terminate();
}

//------------------------------------------------------------------
// Game::ClearBufferFunc()
// Allows user to change the way the clear buffer function works
//------------------------------------------------------------------
void Game::ClearBufferFunc()
{
	const GLfloat blue[] = { 0.6f, 0.6f, 0.6f, 1.0f };
	const GLfloat one = 1.0f;

	glViewport(0, 0, info.windowWidth, info.windowHeight);
	glClearBufferfv(GL_COLOR, 0, blue);
	glClearBufferfv(GL_DEPTH, 0, &one);
}

float Game::GetFrameTime()
{
	return Instance().stopWatch.timeInSeconds();
}

float Game::GetTotalTime()
{
	return Instance().totalWatch.timeInSeconds();
}

Game::~Game()
{
	delete pWorld;
}

void Game::Run(const char* windowName, const int Width, const int Height)
{
	ptrInstance = new Game(windowName, Width, Height);
	ptrInstance->run();
	delete ptrInstance;
}

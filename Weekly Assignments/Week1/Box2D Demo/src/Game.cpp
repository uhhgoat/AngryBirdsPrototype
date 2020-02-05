#include <sb6.h>
#include <sb6ktx.h>
#include <math.h>
#include <assert.h>

#include "DebugOut.h"
#include "GameObject.h"
#include "MathEngine.h"
#include "Game.h"
#include "GraphicsObject.h"
#include "GraphicsObject_Sprite.h"
#include "GraphicsObject_Circle.h"
#include "GraphicsObject_Box.h"
#include "GraphicsObject_Tri.h"
#include "TextureMan.h"
#include "Camera.h"
#include "GameObjectMan.h"
#include "CameraMan.h"
#include "Image.h"
#include "GameObject2D.h"
#include "Color.h"
#include "Vect2D.h"
#include "ShaderMan.h"
#include "ImageMan.h"
#include "DebugOut.h"
#include "ModelMan.h"
#include "AzulStopWatch.h"
#include "TimerMan.h"
#include "Keyboard.h"
#include "Mouse.h"

#include "RedBird.h"
#include "BlueBird.h"
#include "YellowBird.h"
#include "GreenBird.h"
#include "BlackBird.h"
#include "WhiteBird.h"
#include "BigRedBird.h"

#include "KingPig.h"
#include "QueenPig.h"

#include "WoodBlockShort.h"
#include "WoodBlockMed.h"
#include "WoodBlockLong.h"
#include "GlassBlockShort.h"
#include "GlassBlockMed.h"
#include "GlassBlockLong.h"

Game* Game::ptrInstance = nullptr;

#include "Box2D.h"
#include "PixelToMeter.h"
 

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


GameSortBucket* pSortBkt;

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

	//---------------------------------------------------------------------------------------------------------
	// Box2D setup
	//---------------------------------------------------------------------------------------------------------

	// Gravity in Y direction
	b2Vec2 gravity(0.0, -10.0f);
	pWorld = new b2World(gravity);

	// scale: pixels per meter
	UnitScale::Create(50);
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

	//---------------------------------------------------------------------------------------------------------
	// Load up the managers
	//---------------------------------------------------------------------------------------------------------
		// Create/Load Shader 
		ShaderMan::addShader(ShaderName::SPRITE, "spriteRender");
		ShaderMan::addShader(ShaderName::SPRITE_LINE, "spriteLineRender");

		// Textures
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/unsorted.tga", TextName::Characters);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);

		// Images
		ImageMan::addImage(ImageName::KingPig, TextName::Characters, Rect(40, 1, 127, 153));
		ImageMan::addImage(ImageName::QueenPig, TextName::Characters, Rect(40, 466, 127, 153));

		ImageMan::addImage(ImageName::RedBird, TextName::Characters, Rect(903, 798, 46, 45));
		ImageMan::addImage(ImageName::BlueBird, TextName::Characters, Rect(0, 378, 32, 31));
		ImageMan::addImage(ImageName::YellowBird, TextName::Characters, Rect(667, 879, 59, 55));
		ImageMan::addImage(ImageName::GreenBird, TextName::Characters, Rect(932, 529, 99, 72));
		ImageMan::addImage(ImageName::WhiteBird, TextName::Characters, Rect(409, 352, 81, 94));
		ImageMan::addImage(ImageName::BlackBird, TextName::Characters, Rect(409, 725, 62, 80));
		ImageMan::addImage(ImageName::BigRedBird, TextName::Characters, Rect(298, 752, 97, 95));

		ImageMan::addImage(ImageName::WoodBlockShort, TextName::WoodBlocks, Rect(288, 344, 83, 21));
		ImageMan::addImage(ImageName::WoodBlockMed, TextName::WoodBlocks, Rect(288, 257, 168, 21));
		ImageMan::addImage(ImageName::WoodBlockLong, TextName::WoodBlocks, Rect(288, 169, 205, 21));

		ImageMan::addImage(ImageName::GlassBlockShort, TextName::GlassBlocks, Rect(288, 346, 83, 21));
		ImageMan::addImage(ImageName::GlassBlockMed, TextName::GlassBlocks, Rect(288, 259, 168, 21));
		ImageMan::addImage(ImageName::GlassBlockLong, TextName::GlassBlocks, Rect(288, 215, 205, 21));

	//---------------------------------------------------------------------------------------------------------
	// Sort buckets (AKA sprite layers)
	//---------------------------------------------------------------------------------------------------------

	pSortBkt = new GameSortBucket(GameObjectName::MainGroup);
	GameObjectMan::Add(pSortBkt);

	//---------------------------------------------------------------------------------------------------------
	// Create Sprites
	//---------------------------------------------------------------------------------------------------------


	// Sprite

	WBL = new WoodBlockLong(650, 100, 0.0f, *pWorld);
	GameObjectMan::Add(WBL, GameObjectName::MainGroup);

	GBL = new GlassBlockLong(1150, 100, 0.0f, *pWorld);
	GameObjectMan::Add(GBL, GameObjectName::MainGroup);

	WBM = new WoodBlockMed(200, 200, -0.2f, *pWorld);
	GameObjectMan::Add(WBM, GameObjectName::MainGroup);

	GBM = new GlassBlockMed(1600, 200, 0.2f, *pWorld);
	GameObjectMan::Add(GBM, GameObjectName::MainGroup);

	WBS = new WoodBlockShort(650, 500, 0.4f, *pWorld);
	GameObjectMan::Add(WBS, GameObjectName::MainGroup);

	GBS = new GlassBlockShort(1150, 500, -0.4f, *pWorld);
	GameObjectMan::Add(GBS, GameObjectName::MainGroup);

	rB = new RedBird(350, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(rB, GameObjectName::MainGroup);

	blB = new BlueBird(1300, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(blB, GameObjectName::MainGroup);

	gB = new GreenBird(1100, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(gB, GameObjectName::MainGroup);

	yB = new YellowBird(900, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(yB, GameObjectName::MainGroup);

	wB = new WhiteBird(700, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(wB, GameObjectName::MainGroup);

	bkB = new BlackBird(500, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(bkB, GameObjectName::MainGroup);

	brB = new BigRedBird(600, 900, 0.0f, true, *pWorld);
	GameObjectMan::Add(brB, GameObjectName::MainGroup);

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

	delete pSortBkt;

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

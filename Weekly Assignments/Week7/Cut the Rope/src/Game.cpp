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
#include "Demos\InputTest.h"

Game* Game::ptrInstance = nullptr;

#include "Box2D.h"
#include "PixelToMeter.h"
 

#include "Demos\Visualizer.h"
#include "Demos\AngryContactListener.h"
#include "Demos\RedBird.h"
#include "Demos\Pig.h"
#include "Demos\BlockWoodLong.h"
#include "Demos\DistanceJointDemo.h"
#include "Demos\RevoluteJointDemo.h"
#include "Demos\RopeJointDemo.h"
#include "Demos\GearJointDemo.h"
#include "Demos\PistonExercise.h"
#include "Demos\PrismaticJointDemo.h"
#include "Demos\RampExercise.h"
#include "Demos\WheelJointDemo.h"
#include "Demos\GenericBlock.h"
#include "Demos\YellowBird.h"
#include "Demos\SimpleRayCastCallBack.h"

GameSortBucket* pSortBkt;
GameSortBucket* pSortBkt2;
GameSortBucket* pSortBkt3;

#include "Demos\AngryContactListener.h"
AngryContactListener* pMyContactListener;

GenericBlock* pGround;
YellowBird* pYBird;
BlockWoodLong** pBlock;
int count;
SimpleRayCastCallBack* pSimpleRCCB;

RopeJointDemo* pRopeDemo;
Pig* pig;

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
	UnitScale::Create(50.0f);

	// create and initialize contact listener
	pMyContactListener = new AngryContactListener();
	pWorld->SetContactListener(pMyContactListener);
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
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/unsorted.tga", TextName::AngryBirds);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/WoodBlocks.tga", TextName::Wood_Blocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/GlassBlocks.tga", TextName::Glass_Blocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/stoneBlocks.tga", TextName::Stone_Blocks);
		TextureMan::addTexture("../../../../../reference/Asset/Gears/gears.tga", TextName::Gears);

		// Images
		ImageMan::addImage(ImageName::Long_Wood_Block, TextName::Wood_Blocks, Rect(288, 257, 168, 20));
		ImageMan::addImage(ImageName::Long_Wood_Block3, TextName::Wood_Blocks, Rect(288, 323, 168, 20));
		ImageMan::addImage(ImageName::Glass_Block, TextName::Glass_Blocks, Rect(288, 347, 83, 20));
		ImageMan::addImage(ImageName::RedBird, TextName::AngryBirds, Rect(903, 798, 45, 45));
		ImageMan::addImage(ImageName::Bang, TextName::AngryBirds, Rect(674, 354, 87, 89));
		ImageMan::addImage(ImageName::Short_Stone_Block, TextName::Stone_Blocks, Rect(417, 257, 83, 20));
		ImageMan::addImage(ImageName::Pig, TextName::AngryBirds, Rect(732, 856, 48, 46));
		ImageMan::addImage(ImageName::GearLarge, TextName::Gears, Rect(240, 120, 214, 214));
		ImageMan::addImage(ImageName::GearSmall, TextName::Gears, Rect(390, 3, 106, 106));
		ImageMan::addImage(ImageName::RedBird2, TextName::AngryBirds, Rect(951, 798, 45, 45));
		ImageMan::addImage(ImageName::YellowBird, TextName::AngryBirds, Rect(732, 800, 59, 55));

		//---------------------------------------------------------------------------------------------------------
		// Sort buckets (AKA sprite layers)
		//---------------------------------------------------------------------------------------------------------

		pSortBkt = new GameSortBucket(GameObjectName::EffectsGroup);
		GameObjectMan::Add(pSortBkt);
		pSortBkt2 = new GameSortBucket(GameObjectName::MainGroup);
		GameObjectMan::Add(pSortBkt2);
		pSortBkt3 = new GameSortBucket(GameObjectName::BirdGroup);
		GameObjectMan::Add(pSortBkt3);

		//---------------------------------------------------------------------------------------------------------
		// Create Sprites
		//---------------------------------------------------------------------------------------------------------

		pRopeDemo = new RopeJointDemo();
		pig = new Pig(100, 100, 0);
		GameObjectMan::Add(pig, GameObjectName::MainGroup);
		//pig->GetBody()->SetActive(false);



		/*
		pGround = new GenericBlock(400, 10, 0, 800, 20, GameObjectName::Block, ImageName::Short_Stone_Block);
		pGround->GetBody()->SetType(b2_staticBody);
		GameObjectMan::Add(pGround, GameObjectName::MainGroup);

		pYBird = new YellowBird(50, 50, 0);
		GameObjectMan::Add(pYBird, GameObjectName::BirdGroup);

		count = 5;
		pBlock = new BlockWoodLong*[5];
		b2Vec2 Separation(30, 0);
		b2Vec2 Dimension(20, 400);
		b2Vec2 StartPos(pGround->posX, pGround->posY);
		StartPos = StartPos + 0.5f*Dimension;

		for (int i = 0; i < count; i++)
		{
			pBlock[i] = new BlockWoodLong(StartPos.x, StartPos.y, MATH_PI2);
			pBlock[i]->GetBody()->SetType(b2_dynamicBody);
			GameObjectMan::Add(pBlock[i], GameObjectName::MainGroup);

			StartPos += Separation;
		}
		//*/

		pSimpleRCCB = new SimpleRayCastCallBack();
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
	
	// IMPORTANT: These tests are unacceptable in a real application
	// I'm ony using this to allow me an easy way to switch between
	// the various joint demos during the lecture...
	
	//KeyboardResetBird(pYBird);
	//MouseApplyImpulse(pYBird);

	//MouseControlTest();
	RayCastQuery(pSimpleRCCB);

	// Phase 1: Physics Update - Step world----------------------------
		int velocityIterations = 8;
		int positionIterations = 3;
		float timestep = 1.0f / 60; // 60 fps. Box2D does not recommend tying this to framerate
		
		// adding some debug controls for the simulation speed
		if (Keyboard::GetKeyState(AZUL_KEY::KEY_P))
		{
			//DebugMsg::out("Mode: Pause\n");
			timestep = 0;
		}
		else if (Keyboard::GetKeyState(AZUL_KEY::KEY_O))
		{
			//DebugMsg::out("Mode: Slow\n");
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

	// Phase 3: Let the engine update all the game objects normally
	GameObjectMan::Update(currentTime);

	// Process the delete requests
	GameObjectMan::DeletePending();
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

	if (Keyboard::GetKeyState(AZUL_KEY::KEY_LEFT_SHIFT))
	{
		Visualizer::Render();
		Visualizer::ShowJointLinks();
	}
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	GameObjectMan::Delete(pYBird);
	GameObjectMan::Delete(pGround);
	GameObjectMan::Delete(pig);

	delete pSimpleRCCB;
	delete pRopeDemo;

	/*
	// This block clean won't work since blocks can be destroyed at runtime
	// We need a proper factory to keep track of which ones are left.
	for (int i = 0; i < count; i++)
	{
		GameObjectMan::Delete(pBlock[i]);
	}
	delete[] pBlock;
	//*/
	
	GameObjectMan::Delete(pSortBkt);
	GameObjectMan::Delete(pSortBkt2);
	GameObjectMan::Delete(pSortBkt3);

	//delete pSortBkt;
	//delete pSortBkt2;
	//delete pSortBkt3;

	delete pMyContactListener;

	Visualizer::Terminate();

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

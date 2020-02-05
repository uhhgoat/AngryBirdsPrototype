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

// Global vars: Very  sloppy!
GameObject2D *pA1;				
GameObject2D *pB1;

KingPig* kP;
QueenPig* qP;

RedBird* rB;
BlueBird* blB;
YellowBird* yB;
GreenBird* gB;
BlackBird* bkB;
WhiteBird* wB;
BigRedBird* brB;

WoodBlockShort* WBS;
WoodBlockMed* WBM;
WoodBlockLong* WBL;
GlassBlockShort* GBS;
GlassBlockMed* GBM;
GlassBlockLong* GBL;

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
	float halfwidth = this->screenWidth / 2.0f;
	float halfheight = this->screenHeight / 2.0f;
	pCam2D->setOrthographic(-halfwidth, halfwidth, -halfheight, halfheight, 1.0f, 1000.0f);
	pCam2D->setOrientAndPosition(Vect(0.0f, 1.0f, 0.0f), Vect(0.0f, 0.0f, -1.0f), Vect(0.0f, 0.0f, 0.0f));

	// Holder for the current 2D  cameras
	CameraMan::SetCurrentCamera(pCam2D, Camera::Type::ORTHOGRAPHIC_2D);

	//---------------------------------------------------------------------------------------------------------
	// Load up the managers
	//---------------------------------------------------------------------------------------------------------
		// Create/Load Shaders (don't change)
		ShaderMan::addShader(ShaderName::SPRITE, "spriteRender");
		ShaderMan::addShader(ShaderName::SPRITE_LINE, "spriteLineRender");

		// Textures
		TextureMan::addTexture("../../../../../reference/Asset/Azul/Aliens.tga", TextName::Invaders);
		TextureMan::addTexture("../../../../../reference/Asset/Azul/Stitch.tga", TextName::Stitch);

		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/unsorted.tga", TextName::Characters);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/woodBlocks.tga", TextName::WoodBlocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/glassBlocks.tga", TextName::GlassBlocks);
		TextureMan::addTexture("../../../../../reference/Asset/AngryBirds/stoneBlocks.tga", TextName::StoneBlocks);

		// Images
		ImageMan::addImage(ImageName::Stitch, TextName::Stitch, Rect(0, 0, 300, 410));
		ImageMan::addImage(ImageName::Alien_Green, TextName::Invaders, Rect(136, 64, 85, 63));
		ImageMan::addImage(ImageName::Alien_Blue, TextName::Invaders, Rect(370, 64, 62, 63));
		ImageMan::addImage(ImageName::Alien_Red, TextName::Invaders, Rect(559, 64, 93, 63));


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

	GameSortBucket* pSortBkt = new GameSortBucket(GameObjectName::MainGroup);
	GameObjectMan::Add(pSortBkt);

	//---------------------------------------------------------------------------------------------------------
	// Create GameObject2D
	//---------------------------------------------------------------------------------------------------------

		// GraphicsObject for a specific instance
		GraphicsObject_Sprite *pGraphics_Sprite;

		// Alien
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Alien_Green, Rect(600, 150, 150, 150));
		pB1 = new GameObject2D(GameObjectName::Alien, pGraphics_Sprite);
		//GameObjectMan::Add(pB1, GameObjectName::MainGroup);

		//BIRDS
		rB = new RedBird(1500, 900, 0.0f, true);
		GameObjectMan::Add(rB, GameObjectName::MainGroup);

		blB = new BlueBird(1300, 900, 0.0f, true);
		GameObjectMan::Add(blB, GameObjectName::MainGroup);

		gB = new GreenBird(1100, 900, 0.0f, true);
		GameObjectMan::Add(gB, GameObjectName::MainGroup);

		yB = new YellowBird(900, 900, 0.0f, true);
		GameObjectMan::Add(yB, GameObjectName::MainGroup);

		wB = new WhiteBird(700, 900, 0.0f, true);
		GameObjectMan::Add(wB, GameObjectName::MainGroup);

		bkB = new BlackBird(500, 900, 0.0f, true);
		GameObjectMan::Add(bkB, GameObjectName::MainGroup);

		brB = new BigRedBird(300, 900, 0.0f, true);
		GameObjectMan::Add(brB, GameObjectName::MainGroup);

		//PIGS
		kP = new KingPig(800, 600, 0.1f, false);
		GameObjectMan::Add(kP, GameObjectName::MainGroup);

		qP = new QueenPig(1200, 600, -0.1f, false);
		GameObjectMan::Add(qP, GameObjectName::MainGroup);

		//BLOCKS
		WBS = new WoodBlockShort(200, 100, 2.0f);
		GameObjectMan::Add(WBS, GameObjectName::MainGroup);

		WBM = new WoodBlockMed(500, 400, 1.0f);
		GameObjectMan::Add(WBM, GameObjectName::MainGroup);

		WBL = new WoodBlockLong(800, 100, 0);
		GameObjectMan::Add(WBL, GameObjectName::MainGroup);

		GBS = new GlassBlockShort(1100, 100, 2.0f);
		GameObjectMan::Add(GBS, GameObjectName::MainGroup);

		GBM = new GlassBlockMed(1400, 400, 1.0f);
		GameObjectMan::Add(GBM, GameObjectName::MainGroup);

		GBL = new GlassBlockLong(1600, 100, 0);
		GameObjectMan::Add(GBL, GameObjectName::MainGroup);





		// Stitch
		Rect rect = Rect(200, 355, 150, 150);
		pGraphics_Sprite = new GraphicsObject_Sprite(ImageName::Stitch, rect);

		// Stitch Simple
		//*
		pA1 = new GameObject2D(GameObjectName::Stitch, pGraphics_Sprite);
		//*/

		// Stitch Alt 1: Debug shape (auto)
		/*
		pA1 = new GameObject2D(GameObjectName::Stitch, pGraphics_Sprite, GameObject2D::Circle);
		pA1->SetDrawDebug(true);
		//*/
		
		// Stitch Alt 2: Debug shape (manual)
		/*
		rect = Rect(200, 355, 190, 190); // bigger width & height. Origin ignored
		pA1 = new GameObject2D(GameObjectName::Stitch, pGraphics_Sprite, new GraphicsObject_Circle(rect));
		pA1->SetDrawDebug(true);
		//pA1->SetDebugColor(Color::Type::Green);
		//*/
		// 
		// 
		//GameObjectMan::Add(pA1, GameObjectName::MainGroup);

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
	TimerMan::Update();  // Alarms

	// Update cameras - make sure everything is consistent
	Camera *pCam2D = CameraMan::GetCurrent(Camera::Type::ORTHOGRAPHIC_2D);
	pCam2D->updateCamera();


	// -------------  Add your update below this line: ----------------------------
	
	//-----------------------------------------------------------
	// Keyboard reading
	//-----------------------------------------------------------
	if (Keyboard::GetKeyState(AZUL_KEY::KEY_SPACE) )
	{
		DebugMsg::out("Spacebar pressed\n");
	} 

	//-----------------------------------------------------------
	// Spinning Bird
	//-----------------------------------------------------------
	bkB->currAngle += 0.03f;

	//-----------------------------------------------------------
	// scaling up and down
	//-----------------------------------------------------------
	//*
	static float blB_dir_x = 1.0f;
	blB->scaleX += blB_dir_x * 0.005f;
	if (blB->scaleX > 2.0f || blB->scaleX < 0.0f)
	{
		blB_dir_x *= -1.0f;
	}
	blB->scaleY = blB->scaleX;
	//*/
	
	//-----------------------------------------------------------
	// Moving, bouncing off of screen edges
	//-----------------------------------------------------------
	//*
	static float rB_dir_x = 1.0f;
	rB->posX += rB_dir_x * -3.0f;
	if (rB->posX > this->screenWidth || rB->posX < 0.0f)
	{
		rB_dir_x *= -1.0f;
	}
	static float rB_dir_y = 1.0f;
	rB->posY += rB_dir_y * 2.0f;
	if (rB->posY > this->screenHeight || rB->posY < 0.0f)
	{
		rB_dir_y *= -1.0f;
	}

	static float gB_dir_x = -1.0f;
	gB->posX += gB_dir_x * -3.0f;
	if (gB->posX > this->screenWidth || gB->posX < 0.0f)
	{
		gB_dir_x *= -1.0f;
	}
	static float gB_dir_y = 1.0f;
	gB->posY += gB_dir_y * 3.0f;
	if (gB->posY > this->screenHeight || gB->posY < 0.0f)
	{
		gB_dir_y *= -1.0f;
	}


	static float wB_dir_x = 1.0f;
	wB->posX += wB_dir_x * -3.0f;
	if (wB->posX > this->screenWidth || wB->posX < 0.0f)
	{
		wB_dir_x *= -1.0f;
	}

	static float brB_dir_y = 1.0f;
	brB->posY += brB_dir_y * 2.0f;
	if (brB->posY > this->screenHeight || brB->posY < 0.0f)
	{
		brB_dir_y *= -1.0f;
	}

	yB->currAngle -= 0.05f;



	//*/

	// Let the engine update all the game objects
	GameObjectMan::Update(currentTime);
}

//-----------------------------------------------------------------------------
// Game::Draw()
//		This function is called once per frame. 
//	    Use this for draw graphics to the screen.
//      Only do rendering here
//-----------------------------------------------------------------------------
void Game::Draw()
{
	// let the engine draw all the objects
	GameObjectMan::Draw();
}

//-----------------------------------------------------------------------------
// Game::UnLoadContent()
//       unload content (resources loaded above)
//       unload all content that was loaded before the Engine Loop started
//-----------------------------------------------------------------------------
void Game::UnLoadContent()
{
	delete pA1;
	delete pB1;

	delete rB;
	delete blB;
	delete gB;
	delete yB;
	delete wB;
	delete bkB;
	delete brB;

	delete kP;
	delete qP;

	delete WBS;
	delete WBM;
	delete WBL;
	delete GBS;
	delete GBM;
	delete GBL;

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
	// add your own clean-up
}

void Game::Run(const char* windowName, const int Width, const int Height)
{
	ptrInstance = new Game(windowName, Width, Height);
	ptrInstance->run();
	delete ptrInstance;
}

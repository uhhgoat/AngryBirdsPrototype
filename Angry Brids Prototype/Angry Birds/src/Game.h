#ifndef GAME_H
#define GAME_H

#include "Engine.h"
#include <sb6.h>
#include "Includes.h"

#include <math.h>
#include <vmath.h>
#include "MathEngine.h"
#include "AzulStopWatch.h"

class b2World;

class Game : public Engine
{
private:
	static Game* ptrInstance;

	Game() = delete;
	~Game();
	Game(const Game&) = delete;
	Game& operator=(const Game&) = delete;
	Game(const char* windowName, const int Width, const int Height);

	static Game& Instance()
	{
		assert(ptrInstance != nullptr);
		return *ptrInstance;
	}

	virtual void Initialize();
	virtual void LoadContent();
	virtual void Update(float currentTime);
	virtual void Draw();
	virtual void UnLoadContent();

	virtual void ClearBufferFunc();
	
	void LoadResources();

	float			screenWidth;
	float			screenHeight;
	float           aspect;

	AzulStopWatch	stopWatch;
	AzulStopWatch	totalWatch;

	b2World *pWorld;

	Background *bG;

	void CleanSortBuckets(GameObjectName::Name name);

public:
	static void Run(const char* windowName, const int Width, const int Height);

	static float GetFrameTime();
	static float GetTotalTime();

	static b2World* GetB2World() { return Instance().pWorld; }

	static b2Body* GetBackgroundBody() { return Instance().bG->GetBody(); };
};

#endif
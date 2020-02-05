#include <assert.h>

#include "sb6.h"
#include "Game.h"


int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{
	Game::Run("Box2D Demo", 1920, 1080);
	return 0;
}


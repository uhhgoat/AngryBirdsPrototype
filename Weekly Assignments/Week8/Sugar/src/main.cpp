#include <assert.h>

#include "sb6.h"
#include "Game.h"


int CALLBACK WinMain(HINSTANCE , HINSTANCE ,  LPSTR , int)                  
{
	Game::Run("Box2D Demo", 800, 600);
	return 0;
}


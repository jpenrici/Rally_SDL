#include "Game.h"
#include "Utils.h"

#include <iostream>
using std::cout;

Game* game = 0;

int main()
{
	Uint32 frameTime = 0;
	Uint32 frameStart = 0;
	
	cout << "game init attempt...\n";
	if(RallyGame::Instance()->init())
	{
		cout << "game init success!\n";
		while(RallyGame::Instance()->running())
		{
			frameStart = SDL_GetTicks();
			
			RallyGame::Instance()->handleEvents();
			RallyGame::Instance()->update();
			RallyGame::Instance()->render();

			frameTime = SDL_GetTicks() - frameStart;
			if(frameTime < DELAY_TIME)
			{
				SDL_Delay((int)(DELAY_TIME - frameTime));
			}
		}
	}
	else
	{
		cout << "game init failure!\n";
		return -1;
	}
	
	cout << "game closing..." << endl;
	RallyGame::Instance()->clean();

	return 0;
}

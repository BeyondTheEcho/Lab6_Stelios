#include "CApp.h"

void CApp::OnCleanup()
{
	SDL_DestroyWindow(window);
	window = NULL;

	//deletes renderer and resets pointer
	SDL_DestroyRenderer(renderer);
	renderer = NULL;

	//quits the program
	SDL_Quit();
}
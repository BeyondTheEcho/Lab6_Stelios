#include "CApp.h"
#include "ObjectManager.h"

void CApp::OnRender()
{

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg.texture, NULL, NULL);
	
	player.Render(renderer);

	obj.RenderAllCars(renderer);

	//obj.car1.Render(renderer);

	SDL_RenderPresent(renderer);

}


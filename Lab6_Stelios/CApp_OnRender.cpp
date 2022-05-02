#include "CApp.h"
#include "ObjectManager.h"

void CApp::OnRender()
{

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg.texture, NULL, NULL);

	obj.RenderAllObjects(renderer);
	
	player.Render(renderer);

	SDL_RenderPresent(renderer);

}


#include "CApp.h"

void CApp::OnRender()
{

	SDL_RenderClear(renderer);

	SDL_RenderCopy(renderer, bg.texture, NULL, NULL);
	
	player.Render(renderer);

	SDL_RenderPresent(renderer);

}


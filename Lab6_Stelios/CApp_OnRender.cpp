#include "CApp.h"

void CApp::OnRender()
{

	SDL_RenderClear(renderer);

	
	SDL_RenderCopy(renderer, bg.texture, NULL, NULL);

	
	
	SDL_RenderCopy(renderer, player.texture, NULL, &player.playerPosition);
	
	

	SDL_RenderPresent(renderer);

}


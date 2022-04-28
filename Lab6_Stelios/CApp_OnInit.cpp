#include "CApp.h"

bool CApp::OnInit()
{
	window = SDL_CreateWindow("Crossing The Road And River",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	//if window does not work, escapes
	if (!window)
	{
		return -1;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	//if renderer does not work, escapes
	if (!renderer)
	{
		return -1;
	}


	if (bg.LoadSprite("BG.bmp", renderer, bg.texture) < 0)
	{
		return -1;
	}


	if (player.LoadSprite("monke.bmp", renderer, player.texture) < 0)
	{
		return -1;
	}

	return true;
}
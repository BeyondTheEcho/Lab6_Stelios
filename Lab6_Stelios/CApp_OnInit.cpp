#include "CApp.h"

bool CApp::OnInit()
{
	window = SDL_CreateWindow("Frogger - Lab 6 - Stelios",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT,
		SDL_WINDOW_SHOWN);

	//if window does not work, escapes
	if (!window)
	{
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, 0);

	//if renderer does not work, escapes
	if (!renderer)
	{
		return false;
	}

	if (bg.LoadSprite(AssetManager::FormatFilePath(AssetManager::background).c_str(), renderer, bg.texture) < 0)
	{
		return false;
	}

	if (!player.LoadFrogSprites(renderer))
	{
		return false;
	}

	obj.StorePlayerPointer(&player);

	return true;
}
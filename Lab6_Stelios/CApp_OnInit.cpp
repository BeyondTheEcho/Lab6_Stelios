#include "CApp.h"

bool CApp::OnInit()
{
	window = SDL_CreateWindow("Frogger - The Challenges of Frog Life",
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

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return false;
	}

	if (SDL_Init(SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		return false;
	}

	if (TTF_Init() < 0)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
		return false;
	}

	//Initializations
	score.LoadFonts();
	music.loadMedia();

	//Passes and stored pointers
	obj.StorePointers(&player, &music);
	score.StorePlayerPointer(&player);

	return true;
}
#pragma once
#include <iostream>

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "Player.h"
#include "Sprite.h"

using namespace std;

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720
#define NUM_SPRITES		1



class CApp
{
public:
	int OnExecute();

	bool OnInit();

	void OnEvent(SDL_Event* event);
	void OnLoop();
	void OnRender();
	void OnCleanup();

private:
	bool done = false;

	Player player;

	SDL_Window* window;
	SDL_Renderer* renderer;

	Sprite bg;
};

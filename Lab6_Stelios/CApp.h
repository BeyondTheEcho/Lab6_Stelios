#pragma once
#include <iostream>

#include "SDL.h"
#include "SDL_mixer.h"
#include "SDL_ttf.h"

#include "Player.h"
#include "Background.h"

using namespace std;

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720

#define NUM_SPRITES		1

class CApp
{
public:

	bool OnInit();
	void OnEvent(SDL_Event* event);
	void OnLoop();
	
	void OnRender();

	//challenge
	

	void OnCleanup();

	int OnExecute();


private:
	bool done = false;

	//SDL_Rect backgroundBlack = { 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT };
	
	Player player;
	

	SDL_Window* window;
	SDL_Renderer* renderer;
	
	Background bg;

};

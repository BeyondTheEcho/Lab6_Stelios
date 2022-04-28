#pragma once

#include <iostream>

#include "SDL.h"
class Background
{
public:
	int LoadSprite(const char* file, SDL_Renderer* renderer, SDL_Texture*& someTexture);
	int sprite_w, sprite_h;
	SDL_Texture* texture;

private:
	
};


#include "Background.h"

int Background::LoadSprite(const char* file, SDL_Renderer* renderer, SDL_Texture*& someTexture)
{
	SDL_Surface* temp;

	temp = SDL_LoadBMP(file);
	if (temp == NULL)
	{
		fprintf(stderr, "Couldn't load %s: %s", file, SDL_GetError());
		return 1;
	}
	sprite_w = temp->w;
	sprite_h = temp->h;

	if (temp->format->palette)
	{
		SDL_SetColorKey(temp, SDL_TRUE, *(Uint8*)temp->pixels);
	}
	else
	{
		switch (temp->format->BitsPerPixel)
		{
		case 15:
			SDL_SetColorKey(temp, SDL_TRUE, (*(Uint16*)temp->pixels) & 0x00007FFF);
			break;
		case 16:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint16*)temp->pixels);
			break;
		case 24:
			SDL_SetColorKey(temp, SDL_TRUE, (*(Uint32*)temp->pixels) & 0x00FFFFFF);
			break;
		case 32:
			SDL_SetColorKey(temp, SDL_TRUE, *(Uint32*)temp->pixels);
			break;
		}
	}

	someTexture = SDL_CreateTextureFromSurface(renderer, temp);
	if (!someTexture)
	{
		fprintf(stderr, "Couldn't create texture: %s\n", SDL_GetError());
		SDL_FreeSurface(temp);
		return 1;
	}

	SDL_FreeSurface(temp);

	return 0;
}

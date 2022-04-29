#pragma once
#include "Sprite.h"

class Car : public Sprite
{
	int xPos = 100;
	int yPos = 650;

	SDL_Texture* car_Blue;
	SDL_Texture* car_Yellow;
	SDL_Texture* car_Green;

	SDL_Rect CarPosition = { 0, 0, xPos, yPos };

	bool LoadCarSprites(SDL_Renderer* renderer);

	enum Colors { BLUE, YELLOW, GREEN };

	Colors colors;

	static Colors ColorRotation;

	Car();

	void Render(SDL_Renderer* renderer) override;
};


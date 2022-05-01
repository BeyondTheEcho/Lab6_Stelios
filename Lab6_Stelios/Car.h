#pragma once
#include "Sprite.h"
#include "AssetManager.h"
#include "Objects.h"

class Car : public Objects
{
public:
	SDL_Texture* car_Blue;
	SDL_Texture* car_Yellow;
	SDL_Texture* car_Green;

	int* numCarsSpawned = nullptr;

	//Car Color Vars
	enum Colors { BLUE, YELLOW, GREEN };
	Colors colors;
	static Colors ColorRotation;

	//Prototypes
	Car(int* totalCars);
	void Render(SDL_Renderer* renderer) override;
	void RandomizeCarColor();
	bool LoadCarSprites(SDL_Renderer* renderer);
};

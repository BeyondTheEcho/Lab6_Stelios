#pragma once
#include "Sprite.h"
#include "AssetManager.h"

class Car : public Sprite
{
public:

	int* numCarsSpawned;

	//Size of Sprite - Maintain Aspect Ratio
	int xSize = 105;
	int ySize = 49;

	//Position To Be Spawned
	int xPos = 50;
	int yPos = 555;

	//Car Spawn Variance
	int xOffset = 400;
	int yOffset = 55;

	//Car Movement Increment
	int xMovement = 0;

	bool hasLoadedSprites = false;

	//Textures for different Colors
	SDL_Texture* car_Blue;
	SDL_Texture* car_Yellow;
	SDL_Texture* car_Green;

	//Car Rect contains Pos / Size vars
	SDL_Rect CarPosition = { xPos, yPos, xSize, ySize };

	bool LoadCarSprites(SDL_Renderer* renderer);

	//Car Color Vars
	enum Colors { BLUE, YELLOW, GREEN };
	Colors colors;
	static Colors ColorRotation;

	//Prototypes
	Car(int* totalCars);
	void Render(SDL_Renderer* renderer) override;
	void RandomizeCarColor();
	void PlaceCars();
	void Move();
};

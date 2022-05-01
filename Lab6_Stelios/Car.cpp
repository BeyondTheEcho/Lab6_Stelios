#include "Car.h"

Car::Car(int* totalCars)
{
	//Size of Sprite - Maintain Aspect Ratio
	xSize = 105;
	ySize = 49;

	//Position To Be Spawned
	xPos = 50;
	yPos = 555;

	//Car Spawn Variance
	xOffset = 400;
	yOffset = 55;

	numCarsSpawned = totalCars;

	//Randomizes car color on instantiation
	RandomizeCarColor();

	//Places cars appropriately as they are spawned
	PlaceObjects(numCarsSpawned);
}

bool Car::LoadCarSprites(SDL_Renderer* renderer)
{
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::car_Blue).c_str(), renderer, car_Blue) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::car_Green).c_str(), renderer, car_Yellow) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::car_Yellow).c_str(), renderer, car_Green) < 0) return false;

	return true;
}

void Car::RandomizeCarColor()
{
	colors = ColorRotation;
	int temp = ColorRotation;
	temp++;
	if (temp > GREEN) temp = BLUE;
	ColorRotation = (Colors)temp;
}

void Car::Render(SDL_Renderer* renderer)
{
	SDL_Texture* thisTexture;

	if (!hasLoadedSprites)
	{
		LoadCarSprites(renderer);

		hasLoadedSprites = true;
	}

	switch (colors)
	{
	case BLUE:
		thisTexture = car_Blue;
		break;
	case YELLOW:
		thisTexture = car_Yellow;
		break;
	case GREEN:
		thisTexture = car_Green;
		break;
	default: 
		thisTexture = car_Blue;
		cout << "ERROR: Color Unknown: " << colors << endl;
		break;
	}

	SDL_RenderCopy(renderer, thisTexture, nullptr, &Position);
	cout << thisTexture << endl;
}

Car::Colors Car::ColorRotation = BLUE;


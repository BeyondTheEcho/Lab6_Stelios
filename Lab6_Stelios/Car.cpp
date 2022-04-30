#include "Car.h"

Car::Car(int* totalCars)
{
	numCarsSpawned = totalCars;

	//Randomizes car color on instantiation
	RandomizeCarColor();

	//Places cars appropriately as they are spawned
	PlaceCars();
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

void Car::PlaceCars()
{
	
	if (*numCarsSpawned < 3)
	{
		//Places the first 3 cars at the standard y pos with x offset
		for (int i = 0; i < *numCarsSpawned; i++)
		{
			CarPosition.x += xOffset;
		}

		xMovement = 2;
	}
	else if (*numCarsSpawned < 6)
	{
		//Places the next 3 cars at the modified ypos with the x offset
		CarPosition.y -= yOffset;

		for (int i = 3; i < *numCarsSpawned; i++)
		{
			CarPosition.x += xOffset;
		}

		xMovement = 4;

	}
	else if (*numCarsSpawned < 9)
	{
		//Places the final 3 cars at the modified ypos with the x offset
		CarPosition.y -= yOffset * 2;

		for (int i = 6; i < *numCarsSpawned; i++)
		{
			CarPosition.x += xOffset;
		}

		xMovement = 3;
	}

	//Increases the count of currently spawned cars
	*numCarsSpawned = *numCarsSpawned + 1;
}

void Car::Move()
{
	CarPosition.x += xMovement;
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

	SDL_RenderCopy(renderer, thisTexture, nullptr, &CarPosition);
}

Car::Colors Car::ColorRotation = BLUE;


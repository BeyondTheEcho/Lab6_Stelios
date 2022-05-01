#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	ObjectManager::SpawnAllCars();
}

void ObjectManager::SpawnAllCars()
{
	for(int i = 0; i < numCars; i++)
	{
		cars.push_back(new Car(&totalCars));
	}
}

void ObjectManager::RenderAllCars(SDL_Renderer* renderer)
{
	for (int i = 0; i < numCars; i++)
	{
		cars[i]->Render(renderer);
	}
}

void ObjectManager::MoveAllCars()
{
	int totalCars = cars.size();

	for (int i = 0; i < totalCars; i++)
	{
		cars[i]->Move();
	}

	SDL_Delay(sleepDelay);
}

void ObjectManager::RecycleCars()
{
	int totalCars = cars.size();

	for (int i = 0; i < totalCars; i++)
	{
		if (cars[i]->Position.x > WINDOW_WIDTH)
		{
			cars[i]->Position.x = (WINDOW_WIDTH / WINDOW_WIDTH) - WINDOW_OFFSET;
		}
	}

}

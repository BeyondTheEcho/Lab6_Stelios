#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	ObjectManager::SpawnAllObjects();
}

void ObjectManager::SpawnAllObjects()
{
	for(int i = 0; i < numCars; i++)
	{
		cars.push_back(new Car(&totalCars));
	}

	for (int i = 0; i < numLogs; i++)
	{
		logs.push_back(new Log(&totalLogs));
	}
}

void ObjectManager::RenderAllObjects(SDL_Renderer* renderer)
{
	for (int i = 0; i < numCars; i++)
	{
		cars[i]->Render(renderer);
	}

	for (int i = 0; i < numLogs; i++)
	{
		logs[i]->Render(renderer);
	}
}

void ObjectManager::MoveAllObjects()
{
	int totalCars = cars.size();
	int totalLogs = logs.size();

	for (int i = 0; i < totalCars; i++)
	{
		cars[i]->Move();
	}

	for (int i = 0; i < totalLogs; i++)
	{
		logs[i]->Move();
	}

	SDL_Delay(sleepDelay);
}

void ObjectManager::RecycleObjects()
{
	int totalCars = cars.size();
	int totalLogs = logs.size();

	for (int i = 0; i < totalCars; i++)
	{
		if (cars[i]->CarPosition.x > WINDOW_WIDTH)
		{
			cars[i]->CarPosition.x = (WINDOW_WIDTH / WINDOW_WIDTH) - WINDOW_OFFSET;
		}
	}

	for (int i = 0; i < totalLogs; i++)
	{
		if (logs[i]->LogPosition.x > WINDOW_WIDTH)
		{
			logs[i]->LogPosition.x = (WINDOW_WIDTH / WINDOW_WIDTH) - WINDOW_OFFSET * 2;
		}
	}

}

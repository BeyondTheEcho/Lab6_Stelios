#include "ObjectManager.h"

ObjectManager::ObjectManager()
{
	ObjectManager::SpawnAllObjects();
}

void ObjectManager::StorePointers(Player* playerMain, MusicPlayer* musicptr)
{
	player = playerMain;
	music = musicptr;
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

void ObjectManager::CheckAllCollisions()
{
	for (auto car : cars)
	{
		if (CheckCollision(player->playerPosition, car->CarPosition))
		{
			player->ResetPlayerPos();
			music->PlaySplat();
		}
	}
}

bool ObjectManager::CheckCollision(SDL_Rect a, SDL_Rect b)
{
	//The sides of the rectangles
	int leftA, leftB;
	int rightA, rightB;
	int topA, topB;
	int bottomA, bottomB;

	//Calculate the sides of rect A
	leftA = a.x;
	rightA = a.x + a.w;
	topA = a.y;
	bottomA = a.y + a.h;

	//Calculate the sides of rect B
	leftB = b.x;
	rightB = b.x + b.w;
	topB = b.y;
	bottomB = b.y + b.h;

	//If any of the sides from A are outside of B
	if (bottomA <= topB)
	{
		return false;
	}

	if (topA >= bottomB)
	{
		return false;
	}

	if (rightA <= leftB)
	{
		return false;
	}

	if (leftA >= rightB)
	{
		return false;
	}

	//If none of the sides from A are outside B
	return true;
}


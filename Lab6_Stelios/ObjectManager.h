#pragma once
#include "Car.h"
#include <vector>

using namespace std;

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720
#define WINDOW_OFFSET   105

class ObjectManager
{
public:
	//Number of cars to spawn
	int numCars = 9;
	//Total cars spawned
	int totalCars = 0;
	//Sleep Delay
	int sleepDelay = 10;

	//Array of all NPC Objects
	vector<Car*> cars;

	ObjectManager();
	void SpawnAllCars();
	void RenderAllCars(SDL_Renderer* renderer);
	void MoveAllCars();
	void RecycleCars();
};


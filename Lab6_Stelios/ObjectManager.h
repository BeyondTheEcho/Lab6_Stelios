#pragma once
#include "Car.h"
#include "Log.h"
#include <vector>
#include "Player.h"
#include "MusicPlayer.h"

using namespace std;

#define WINDOW_WIDTH	1280
#define WINDOW_HEIGHT	720
#define WINDOW_OFFSET   105

class ObjectManager
{
public:
	Player* player = nullptr;
	MusicPlayer* music = nullptr;
	

	//Number of cars to spawn
	int numCars = 9;
	//Total cars spawned
	int totalCars = 0;

	//Number of logs to be spawned
	int numLogs = 12;
	//total logs to be spawned
	int totalLogs = 0;

	//Sleep Delay
	int sleepDelay = 10;

	//Array of all Car Objects
	vector<Car*> cars;
	//Array of all Log Objects
	vector<Log*> logs;

	ObjectManager();
	void StorePointers(Player* playerMain, MusicPlayer* musicptr);
	void SpawnAllObjects();
	void RenderAllObjects(SDL_Renderer* renderer);
	void MoveAllObjects();
	void RecycleObjects();
	void CheckAllCollisions();
	bool CheckCollision(SDL_Rect a, SDL_Rect b);
};


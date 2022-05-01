#pragma once
#include "Car.h"

class Log : public Sprite
{
public:
	int* numLogsSpawned;

	//Size of Sprite - Maintain Aspect Ratio
	int xSize = 205;
	int ySize = 80;

	//Position To Be Spawned
	int xPos = 50;
	int yPos = 260;

	//Log Spawn Variance
	int xOffset = 400;
	int yOffset = 70;

	//Log Movement Increment
	int xMovement = 0;

	bool hasLoadedSprites = false;

	//Textures for different Colors
	SDL_Texture* log_Small;
	SDL_Texture* log_Medium;
	SDL_Texture* Log_Large;

	enum Logs { SMALL, MEDIUM, LARGE };
	Logs logs;
	static Logs LogRotation;

	//Car Rect contains Pos / Size vars
	SDL_Rect LogPosition = { xPos, yPos, xSize, ySize };

	//Prototypes
	Log(int* totallogs);
	bool LoadLogSprites(SDL_Renderer* renderer);
	void PlaceLogs();
	void Move();
	void Render(SDL_Renderer* renderer) override;
	void RandomizeLogs();

};

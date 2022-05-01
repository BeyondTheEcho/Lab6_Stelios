#pragma once
#include <SDL_render.h>
#include "AssetManager.h"
#include "Sprite.h"

class Objects : public Sprite
{
public:
	//Size of Sprite - Maintain Aspect Ratio
	int xSize = 0;
	int ySize = 0;

	//Position To Be Spawned
	int xPos = 0;
	int yPos = 0;

	//Obj Spawn Variance
	int xOffset = 0;
	int yOffset = 0;

	//Movement Increment
	int xMovement = 0;

	bool hasLoadedSprites = false;

	////Textures for different Objects
	//SDL_Texture* texture_1;
	//SDL_Texture* texture_2;
	//SDL_Texture* texture_3;

	//Car Rect contains Pos / Size vars
	SDL_Rect Position = { xPos, yPos, xSize, ySize };

	//Prototypes
	//virtual void Render(SDL_Renderer* renderer, string txt1, string txt2, string txt3);
	//virtual bool LoadSprites(SDL_Renderer* renderer, string txt1, string txt2, string txt3);
	void PlaceObjects(int* numObjsSpawned);
	void Move();

};

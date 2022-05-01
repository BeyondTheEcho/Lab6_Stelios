#pragma once
#include <iostream>
#include <vector>

#include "SDL.h"
#include "Sprite.h"

class Player: public Sprite
{
protected:
	//Sprite Size Vars
	int xSize = 60;
	int ySize = 50;

	//Frog Position Vars
	int xPos = 670;
	int yPos = 610;
	
	void CheckBounds();
public:
	//Frog Start Position
	const int xStartPos = 670;
	const int yStartPos = 610;

	SDL_Texture* frog_Up;
	SDL_Texture* frog_Down;
	SDL_Texture* frog_Right;
	SDL_Texture* frog_Left;

	std::vector<SDL_Texture*> sprites = { frog_Up, frog_Down, frog_Left, frog_Right };

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void ResetPlayerPos();

	void RotateSprite(std::string);
	bool LoadFrogSprites(SDL_Renderer* renderer);

	void Render(SDL_Renderer* renderer) override;

	SDL_Rect playerPosition = { xPos, yPos, xSize, ySize };

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	Direction dir;
};



	


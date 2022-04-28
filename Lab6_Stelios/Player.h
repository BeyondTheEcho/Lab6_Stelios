#pragma once
#include <iostream>
#include <vector>

#include "SDL.h"
#include "Sprite.h"

class Player: public Sprite
{
protected:
	
	int xPos = 64;
	int yPos = 72;
	
	void CheckBounds();
public:
	SDL_Texture* frog_Up;
	SDL_Texture* frog_Down;
	SDL_Texture* frog_Right;
	SDL_Texture* frog_Left;

	std::vector<SDL_Texture*> sprites = { frog_Up, frog_Down, frog_Left, frog_Right };

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	void RotateSprite(std::string);
	bool LoadFrogSprites(SDL_Renderer* renderer);

	void Render(SDL_Renderer* renderer) override;

	SDL_Rect playerPosition = { 0, 0, xPos, yPos };

	enum Direction
	{
		UP,
		DOWN,
		LEFT,
		RIGHT
	};

	Direction dir;
};



	


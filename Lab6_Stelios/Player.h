#pragma once
#include <iostream>

#include "SDL.h"
#include "Background.h"

class Player: public Background
{
protected:
	
	int xUnits = 64;
	int yUnits = 72;
	
	void CheckBounds();
public:
	

	void MoveLeft();
	void MoveRight();
	void MoveUp();
	void MoveDown();

	
	
	SDL_Rect playerPosition = { 0, 0, xUnits, yUnits };



};



	


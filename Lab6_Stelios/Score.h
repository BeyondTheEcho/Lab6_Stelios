#pragma once
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>
#include "Player.h"

using namespace std;

#define START_Y	610

class Score
{
public:
	//Player Pointer
	Player* player;

	//Text Position Ints
	int xPos = 0;
	int yPos = 0;

	//Text Size Ints
	int width = 20;
	int height = 20;

	//Score Vars
	int playerScore = 0;
	int lowestPlayerY = START_Y;
	int scoreMultiplier = 2;
	int scoreBonus = 1000;

	//Fonts
	TTF_Font* font = nullptr;

	//Colors
	SDL_Color color;

	//Text To Render
	string outputText;

	//Pointer for surface
	SDL_Surface* messageSurface = nullptr;
	//Pointer to Texture after surface is converted
	SDL_Texture* messageTexture = nullptr;

	//Font Path
	string fontPath = "./Assets/Fonts/upheavtt.ttf";

	//Rect For Location Of Text
	SDL_Rect messageRect = {xPos,yPos,width,height};

	//Prototypes
	void LoadFonts();
	void DisplayScore(SDL_Renderer* renderer);
	void StorePlayerPointer(Player* playerptr);
	void CalculateScore();
};




#include "Score.h"

void Score::LoadFonts()
{
	font = TTF_OpenFont(fontPath.c_str(), 20);
	color = { 0,0,0 };
}

void Score::DisplayScore(SDL_Renderer* renderer)
{
    //To cleanup memory
    SDL_DestroyTexture(messageTexture);
    SDL_FreeSurface(messageSurface);
    outputText = "";

    outputText.append("Score: ");
    outputText.append(to_string(playerScore));

    //make text an image (an SDL_Surface)
    messageSurface = TTF_RenderText_Solid(font, outputText.c_str(), color);
    //convert SDL_Surface to SDL_Texture
    messageTexture = SDL_CreateTextureFromSurface(renderer, messageSurface);			

    //get width & height of texture
    SDL_QueryTexture(messageTexture, NULL, NULL, &width, &height);
    //create a SDL_Rect for the message
    messageRect = { xPos, yPos, width, height };												

    //Render To Screen
    SDL_RenderCopy(renderer, messageTexture, NULL, &messageRect);					
}

void Score::StorePlayerPointer(Player* playerptr)
{
    player = playerptr;
}

void Score::CalculateScore()
{
    int scoreToAdd = 0;
    int currentPlayerY = player->playerPosition.y;

    if (currentPlayerY < lowestPlayerY)
    {
        scoreToAdd = (lowestPlayerY - currentPlayerY) * scoreMultiplier;
        lowestPlayerY = currentPlayerY;

        playerScore += scoreToAdd;

        cout << "Player Score: " << playerScore << endl;
    }

    if (currentPlayerY == 0)
    {
        playerScore += scoreBonus;

        player->ResetPlayerPos();

        lowestPlayerY = START_Y;
    }
}
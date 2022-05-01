#include "CApp.h"
#include "Player.h"

#include "AssetManager.h"

void Player::CheckBounds() 
{
	if (playerPosition.x < 0)
	{
		playerPosition.x = 0;
	}
	if (playerPosition.x > WINDOW_WIDTH - 1)
	{
		playerPosition.x = WINDOW_WIDTH - xSize;
	}
	if (playerPosition.y < 0)
	{
		playerPosition.y = 0;
	}
	if (playerPosition.y > WINDOW_HEIGHT - 1)
	{
		playerPosition.y = WINDOW_HEIGHT - ySize;
	}
}

void Player::MoveLeft()
{
	playerPosition.x -= xSize;
	dir = LEFT;
	CheckBounds();
}

void Player::MoveRight()
{
	playerPosition.x += xSize;
	dir = RIGHT;
	CheckBounds();
}

void Player::MoveUp()
{
	playerPosition.y -= ySize;
	dir = UP;
	CheckBounds();
}

void Player::MoveDown()
{
	playerPosition.y += ySize;
	dir = DOWN;
	CheckBounds();
}

void Player::ResetPlayerPos()
{
	playerPosition.x = xStartPos;
	playerPosition.y = yStartPos;
}

bool Player::LoadFrogSprites(SDL_Renderer* renderer)
{
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::frog_Up).c_str(), renderer, frog_Up) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::frog_Down).c_str(), renderer, frog_Down) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::frog_Right).c_str(), renderer, frog_Right) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::frog_Left).c_str(), renderer, frog_Left) < 0) return false;
	
	return true;
}

void Player::Render(SDL_Renderer* renderer)
{
	SDL_Texture* thisTexture;

	switch (dir)
	{
	case UP: 
		thisTexture = frog_Up;
		break;
	case DOWN: 
		thisTexture = frog_Down;
		break;
	case RIGHT: 
		thisTexture = frog_Right;
		break;
	case LEFT: 
		thisTexture = frog_Left;
		break;
	default: 
		thisTexture = frog_Up;
		cout << "ERROR: Unknown Direction: " << dir << endl;
		break;
	}

	SDL_RenderCopy(renderer, thisTexture, nullptr, &playerPosition);
}



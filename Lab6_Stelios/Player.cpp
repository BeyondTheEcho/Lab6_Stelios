#include "CApp.h"
#include "Player.h"

void Player::CheckBounds() 
{
	if (playerPosition.x < 0)
	{
		playerPosition.x = 0;
	}
	if (playerPosition.x > WINDOW_WIDTH - 1)
	{
		playerPosition.x = WINDOW_WIDTH - xUnits;
	}
	if (playerPosition.y < 0)
	{
		playerPosition.y = 0;
	}
	if (playerPosition.y > WINDOW_HEIGHT - 1)
	{
		playerPosition.y = WINDOW_HEIGHT - yUnits;
	}
}

void Player::MoveLeft()
{
	playerPosition.x -= xUnits;
	CheckBounds();
}

void Player::MoveRight()
{
	playerPosition.x += xUnits;
	CheckBounds();
}

void Player::MoveUp()
{
	playerPosition.y -= yUnits;
	CheckBounds();
}

void Player::MoveDown()
{
	playerPosition.y += yUnits;
	CheckBounds();
}



#include "Log.h"

Log::Log(int* totallogs)
{
	numLogsSpawned = totallogs;

	RandomizeLogs();

	//Places cars appropriately as they are spawned
	PlaceLogs();
}

bool Log::LoadLogSprites(SDL_Renderer* renderer)
{
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::log_Small).c_str(), renderer, log_Small) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::log_Medium).c_str(), renderer, log_Medium) < 0) return false;
	if (LoadSprite(AssetManager::FormatFilePath(AssetManager::log_Large).c_str(), renderer, Log_Large) < 0) return false;

	return true;
}

void Log::RandomizeLogs()
{
	logs = LogRotation;
	int temp = LogRotation;
	temp++;
	if (temp > LARGE) temp = SMALL;
	LogRotation = (Logs)temp;
}


void Log::PlaceLogs()
{

	if (*numLogsSpawned < 3)
	{
		for (int i = 0; i < *numLogsSpawned; i++)
		{
			LogPosition.x += xOffset;
		}

		xMovement = 2;
	}
	else if (*numLogsSpawned < 6)
	{
		LogPosition.y -= yOffset;

		for (int i = 3; i < *numLogsSpawned; i++)
		{
			LogPosition.x += xOffset;
		}

		xMovement = 4;

	}
	else if (*numLogsSpawned < 9)
	{
		LogPosition.y -= yOffset * 2;

		for (int i = 6; i < *numLogsSpawned; i++)
		{
			LogPosition.x += xOffset;
		}

		xMovement = 3;
	}
	else if (*numLogsSpawned < 12)
	{
		LogPosition.y -= yOffset * 3;

		for (int i = 9; i < *numLogsSpawned; i++)
		{
			LogPosition.x += xOffset;
		}

		xMovement = 2;
	}

	//Increases the count of currently spawned logs
	*numLogsSpawned = *numLogsSpawned + 1;
}

void Log::Move()
{
	LogPosition.x += xMovement;
}

void Log::Render(SDL_Renderer* renderer)
{
	SDL_Texture* thisTexture;

	if (!hasLoadedSprites)
	{
		LoadLogSprites(renderer);

		hasLoadedSprites = true;
	}

	switch (logs)
	{
	case SMALL:
		thisTexture = log_Small;
		break;
	case MEDIUM:
		thisTexture = log_Medium;
		break;
	case LARGE:
		thisTexture = Log_Large;
		break;
	default:
		thisTexture = log_Small;
		cout << "ERROR: Color Unknown: " << logs << endl;
		break;
	}

	SDL_RenderCopy(renderer, thisTexture, nullptr, &LogPosition);
}

Log::Logs Log::LogRotation = SMALL;
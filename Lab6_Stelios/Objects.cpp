#include "Objects.h"

//bool Objects::LoadSprites(SDL_Renderer* renderer, string txt1, string txt2, string txt3)
//{
//	if (LoadSprite(AssetManager::FormatFilePath(txt1).c_str(), renderer, texture_1) < 0) return false;
//	if (LoadSprite(AssetManager::FormatFilePath(txt2).c_str(), renderer, texture_2) < 0) return false;
//	if (LoadSprite(AssetManager::FormatFilePath(txt3).c_str(), renderer, texture_3) < 0) return false;
//	cout << AssetManager::FormatFilePath(txt1).c_str() << " - " << texture_1 << endl;
//	cout << "Object Sprites Loaded" << endl;
//
//	return true;
//}


void Objects::PlaceObjects(int* numObjsSpawned)
{
	cout << "Place Objects Called #" << *numObjsSpawned << endl;

	if (*numObjsSpawned < 3)
	{
		//Places the first 3 cars at the standard y pos with x offset
		for (int i = 0; i < *numObjsSpawned; i++)
		{
			Position.x += xOffset;
			cout << "Object Placed At X: " << Position.x << " Y: " << Position.y << endl;
		}

		xMovement = 2;
	}
	else if (*numObjsSpawned < 6)
	{
		//Places the next 3 Objects at the modified ypos with the x offset
		Position.y -= yOffset;

		for (int i = 3; i < *numObjsSpawned; i++)
		{
			Position.x += xOffset;
			cout << "Object Placed At X: " << Position.x << " Y: " << Position.y << endl;
		}

		xMovement = 4;

	}
	else if (*numObjsSpawned < 9)
	{
		//Places the final 3 cars at the modified ypos with the x offset
		Position.y -= yOffset * 2;

		for (int i = 6; i < *numObjsSpawned; i++)
		{
			Position.x += xOffset;
			cout << "Object Placed At X: " << Position.x << " Y: " << Position.y << endl;
		}

		xMovement = 3;
	}

	//Increases the count of currently spawned cars
	*numObjsSpawned = *numObjsSpawned + 1;
}

void Objects::Move()
{
	Position.x += xMovement;
}

//void Objects::Render(SDL_Renderer* renderer, string txt1, string txt2, string txt3)
//{
//	SDL_Texture* thisTexture = nullptr;
//
//	if (!hasLoadedSprites)
//	{
//		LoadSprites(renderer, txt1, txt2, txt3);
//
//		hasLoadedSprites = true;
//	}
//
//	SDL_RenderCopy(renderer, thisTexture, nullptr, &Position);
//}

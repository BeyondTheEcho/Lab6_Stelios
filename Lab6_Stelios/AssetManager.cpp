#include "AssetManager.h"

string AssetManager::assetsFilePath = "./Assets/";
string AssetManager::frog_Up = "Frog_Up";
string AssetManager::frog_Down = "Frog_Down";
string AssetManager::frog_Right = "Frog_Right";
string AssetManager::frog_Left = "Frog_Left";
string AssetManager::background = "background";

string AssetManager::FormatFilePath(string asset)
{
	string filePath = assetsFilePath;
	filePath.append(asset);
	filePath.append(".bmp");

	return filePath;
}
#include "AssetManager.h"

string AssetManager::assetsFilePath = "./Assets/BMPs/";

string AssetManager::frog_Up = "Frog_Up";
string AssetManager::frog_Down = "Frog_Down";
string AssetManager::frog_Right = "Frog_Right";
string AssetManager::frog_Left = "Frog_Left";

string AssetManager::background = "background";

string AssetManager::car_Blue = "Car_Blue";
string AssetManager::car_Green = "Car_Green";
string AssetManager::car_Yellow = "Car_Yellow";

string AssetManager::log_Small = "Log_Small";
string AssetManager::log_Medium = "Log_Medium";
string AssetManager::log_Large = "Log_Large";

string AssetManager::FormatFilePath(string asset)
{
	string filePath = assetsFilePath;
	filePath.append(asset);
	filePath.append(".bmp");

	return filePath;
}
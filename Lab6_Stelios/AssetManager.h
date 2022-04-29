#pragma once
#include <string>

using namespace std;

class AssetManager
{
public:
	static string assetsFilePath;

	static string frog_Up;
	static string frog_Down;
	static string frog_Right;
	static string frog_Left;

	static string car_Blue;
	static string car_Green;
	static string car_Yellow;

	static string background;

	static string FormatFilePath(string asset);
};


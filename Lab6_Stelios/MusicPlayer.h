#pragma once
#include  <SDL_mixer.h>
#include "AssetManager.h"

using namespace std;

class MusicPlayer
{
public:
	//Music
	Mix_Music* gameMusic1 = nullptr;
	Mix_Music* gameMusic2 = nullptr;
	Mix_Music* gameMusic3 = nullptr;
	Mix_Music* gameMusic4 = nullptr;
	
	//Sound Effects
	Mix_Chunk* splatSound = nullptr;
	Mix_Chunk* waterSound = nullptr;
	Mix_Chunk* splashSound = nullptr;

	//Music Paths
	string track1Path = "./Assets/Sounds/dockknocking.wav";
	string track2Path = "./Assets/Sounds/forest.wav";
	string track3Path = "./Assets/Sounds/moon.wav";
	string track4Path = "./Assets/Sounds/underground.wav";

	//Sound Paths
	string waterAmbiencePath = "./Assets/Sounds/beach_atmosphere.wav";
	string waterSplashPath = "./Assets/Sounds/splash1.wav";
	string splatPath = "./Assets/Sounds/impactsplat01.wav";
	

	//Track Counter
	int currentTrack = 1;
	
	//Prototypes
	bool loadMedia();
	void PlayMusic();
	void PlaySplat();
	void PlaySplash();
	void PlayAmbience();

};


#pragma once
#include  <SDL_mixer.h>
#include "AssetManager.h"

using namespace std;

class MusicPlayer
{
public:
	//Music
	Mix_Music* gameMusic = nullptr;
	
	//Sound Effects
	Mix_Chunk* splatSound = nullptr;
	Mix_Chunk* waterSound = nullptr;
	Mix_Chunk* splashSound = nullptr;

	//Music + Sound Paths
	string waterAmbiencePath = "./Assets/Sounds/beach_atmosphere.wav";
	string waterSplashPath = "./Assets/Sounds/splash1.wav";
	string splatPath = "./Assets/Sounds/impactsplat01.wav";
	string musicPath = "./Assets/Sounds/dockknocking.wav";
	
	//Prototypes
	bool loadMedia();
	void PlayMusic();
	void PlaySplat();
	void PlaySplash();
	void PlayAmbience();

};


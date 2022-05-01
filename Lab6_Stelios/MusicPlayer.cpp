#include "MusicPlayer.h"

bool MusicPlayer::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load music
    gameMusic = Mix_LoadMUS(musicPath.c_str());
    if (gameMusic == NULL)
    {
        printf("Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
    splatSound = Mix_LoadWAV(splatPath.c_str());
    if (splatSound == NULL)
    {
        printf("Failed to load scratch sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
    waterSound = Mix_LoadWAV(waterAmbiencePath.c_str());
    if (waterSound == NULL)
    {
        printf("Failed to load water sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    //Load sound effects
    splashSound = Mix_LoadWAV(waterSplashPath.c_str());
    if (splashSound == NULL)
    {
        printf("Failed to load water sound effect! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    return success;
}

void MusicPlayer::PlayMusic()
{
    Mix_PlayMusic(gameMusic, -1);
}

void MusicPlayer::PlaySplat()
{
    Mix_PlayChannel(-1, splatSound, 0);
}

void MusicPlayer::PlaySplash()
{
    Mix_PlayChannel(-1, splashSound, 0);
}

void MusicPlayer::PlayAmbience()
{
    Mix_PlayChannel(-1, waterSound, 0);
}

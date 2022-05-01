#include "MusicPlayer.h"

bool MusicPlayer::loadMedia()
{
    //Loading success flag
    bool success = true;

    //Load music
    gameMusic1 = Mix_LoadMUS(track1Path.c_str());
    if (gameMusic1 == NULL)
    {
        printf("Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    gameMusic2 = Mix_LoadMUS(track2Path.c_str());
    if (gameMusic2 == NULL)
    {
        printf("Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    gameMusic3 = Mix_LoadMUS(track3Path.c_str());
    if (gameMusic3 == NULL)
    {
        printf("Failed to load game music! SDL_mixer Error: %s\n", Mix_GetError());
        success = false;
    }

    gameMusic4 = Mix_LoadMUS(track4Path.c_str());
    if (gameMusic4 == NULL)
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
    if (Mix_PlayingMusic() == 0)
    {
        if (currentTrack == 1)
        {
            Mix_PlayMusic(gameMusic1, 1);
            currentTrack++;
        }
        else if (currentTrack == 2)
        {
            Mix_PlayMusic(gameMusic2, 1);
            currentTrack++;
        }
        else if (currentTrack == 3)
        {
            Mix_PlayMusic(gameMusic3, 1);
            currentTrack++;
        }
        else if (currentTrack == 4)
        {
            Mix_PlayMusic(gameMusic4, 1);
            currentTrack = 1;
        }
    }
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

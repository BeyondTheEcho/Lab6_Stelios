#include "CApp.h"

void CApp::OnLoop()
{
	//Player music tracks
	music.PlayMusic();

	//Moves and Recycles Objects
	obj.MoveAllObjects();
	obj.RecycleObjects();

	//Checks all collision conditions
	obj.CheckAllCollisions();

	//Calculates and displays players score
	score.CalculateScore();
	score.DisplayScore(renderer);
}
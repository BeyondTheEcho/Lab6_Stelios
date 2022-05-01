#include "CApp.h"

void CApp::OnLoop()
{
	music.PlayMusic();
	obj.MoveAllObjects();
	obj.RecycleObjects();
	obj.CheckAllCollisions();
}
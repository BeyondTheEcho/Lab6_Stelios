#include "CApp.h"

void CApp::OnLoop()
{
	obj.MoveAllObjects();
	obj.RecycleObjects();
	obj.CheckAllCollisions();

}
#include "CApp.h"

void CApp::OnLoop()
{
	obj.MoveAllCars();
	obj.RecycleCars();
}
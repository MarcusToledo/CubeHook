#include "pch.h"
#include "hkMouseMove.h"
#include "Menu.h"


void* __cdecl hkMoveMouse(int idx, int idy) {

	if (GMenu.IsMenuOpened()) //essentially if menu is open
	{
		idx = 0;
		idy = 0;
	}
	return MoveMouse(idx, idy);
}

#include "pch.h"
#include "hkShowCursor.h"
#include "Menu/Menu.h"

static bool bEnabled = false;


int SDLCALL hkShowCursor(int toggle) {
	if (GMenu.IsMenuOpened()) {
		SDL_WM_GrabInput(SDL_GRAB_OFF);
		oShowCursor(SDL_ENABLE);
		bEnabled = true;


	}

	else if (bEnabled) {
		SDL_WM_GrabInput(SDL_GRAB_ON);
		oShowCursor(SDL_DISABLE);
		bEnabled = false;
	}

	return 0;
}

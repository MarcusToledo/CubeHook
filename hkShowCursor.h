#pragma once
#include "pch.h"
#include "Menu.h"
#include <SDL.h>


typedef int(SDLCALL* ShowCursor_t)(int toggle);

inline ShowCursor_t oShowCursor = nullptr;

int SDLCALL hkShowCursor(int toggle);


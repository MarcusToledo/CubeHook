#pragma once
#include "pch.h"
#include "Menu.h"
#include <SDL.h>
#include <Hook.h>


typedef int(SDLCALL* ShowCursor_t)(int toggle);

int SDLCALL hkShowCursor(int toggle);

inline HMODULE moduleSDL = GetModuleHandleA("SDL.dll");
inline BYTE* pShowCursor = reinterpret_cast<BYTE*>(GetProcAddress(moduleSDL, "SDL_ShowCursor"));

inline ShowCursor_t oShowCursor = reinterpret_cast<ShowCursor_t>(trampHook32(pShowCursor, reinterpret_cast<BYTE*>(hkShowCursor), 5));
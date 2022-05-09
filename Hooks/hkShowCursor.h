#pragma once
#include "pch.h"
#include "Menu/Menu.h"
#include "SDL.h"
#include "Hook.h"


typedef int(SDLCALL* t_showCursor)(int toggle); //TODO: Change this to a using
//using t_showCursor = int(SDLCALL*)(int toggle);


int SDLCALL hkShowCursor(int toggle);

inline HMODULE moduleSDL{ GetModuleHandleA("SDL.dll") };
inline BYTE* pShowCursor{ reinterpret_cast<BYTE*>(GetProcAddress(moduleSDL, "SDL_ShowCursor")) };

inline t_showCursor oShowCursor{ reinterpret_cast<t_showCursor>(trampHook32(pShowCursor, reinterpret_cast<BYTE*>(hkShowCursor), 5)) };
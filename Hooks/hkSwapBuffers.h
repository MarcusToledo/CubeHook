#pragma once
#include "pch.h"
#include "Hooks/Hook.h"

using t_wglSwapBuffers = BOOL(__stdcall*)(HDC hdc);
inline t_wglSwapBuffers o_wglSwapBuffers;

// 	TrampolineHook* myHook = new TrampolineHook("wglSwapBuffers", "opengl32.dll", (BYTE*)hkSwapBuffers, (BYTE*)&wglSwapBuffers, 5);


BOOL __stdcall hkSwapBuffers(HDC hDc);

inline Hook* hookWglSwapBuffer = new Hook("wglSwapBuffers", "opengl32.dll", reinterpret_cast<BYTE*>(hkSwapBuffers), reinterpret_cast<BYTE*>(&o_wglSwapBuffers), 5); // Init tramp hook



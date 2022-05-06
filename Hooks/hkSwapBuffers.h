#pragma once
#include "pch.h"

typedef BOOL(__stdcall* t_wglSwapBuffers)(HDC hdc);

inline t_wglSwapBuffers o_wglSwapBuffers = reinterpret_cast<t_wglSwapBuffers>(GetProcAddress(GetModuleHandle("opengl32.dll"), "wglSwapBuffers")); // Pointer to original swapbuffers function

BOOL __stdcall hkSwapBuffers(HDC hDc);



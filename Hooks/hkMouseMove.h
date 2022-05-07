#pragma once
#include "pch.h"

#include "Hook.h"
#include "Memory/Memory.h"

typedef void* (__cdecl* t_MoveMouse)(int idx, int idy); //TODO: Change this to a using

inline t_MoveMouse MoveMouse = reinterpret_cast<t_MoveMouse>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE);

void* __cdecl hkMoveMouse(int idx, int idy);

inline Hook* hookMouseMove = new Hook(reinterpret_cast<BYTE*>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE), reinterpret_cast<BYTE*>(&hkMoveMouse), reinterpret_cast<BYTE*>(&MoveMouse), 10);


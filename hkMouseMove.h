#pragma once
#include "pch.h"
#include "Memory.h"

typedef void* (__cdecl* tMoveMouse)(int idx, int idy);

inline tMoveMouse MoveMouse = reinterpret_cast<tMoveMouse>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE);

void* __cdecl hkMoveMouse(int idx, int idy);


//Hook* hookMouseMove = new Hook(reinterpret_cast<BYTE*>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE), reinterpret_cast<BYTE*>(hkMoveMouse), 10);

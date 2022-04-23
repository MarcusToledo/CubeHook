#pragma once
#include "pch.h"
#include "Hook.h"
#include "Memory.h"
#include "Menu.h"

typedef void* (__cdecl* tMoveMouse)(int idx, int idy);

inline tMoveMouse MoveMouse = reinterpret_cast<tMoveMouse>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE);

inline void* __cdecl hkMoveMouse(int idx, int idy) {

	if (GMenu.IsMenuOpened()) //essentially if menu is open
	{
		idx = 0;
		idy = 0;
	}
	return MoveMouse(idx, idy);
}

//Hook* hookMouseMove = new Hook(reinterpret_cast<BYTE*>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE), reinterpret_cast<BYTE*>(hkMoveMouse), 10);

// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include <cstdio>
#include <iostream>

#include "Cheats.h"

DWORD WINAPI MainThread(HMODULE hModule) {
	//create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout); // only output
	std::cout << "Injected!" << std::endl;
	Cheats* cheats = new Cheats();

	bool bInfiniteAmmo = false;

	while (true) {
		//check key inputs

		if (GetAsyncKeyState(VK_NUMPAD0) & 1) {
			break;
		}

		if (GetAsyncKeyState(VK_F1) & 1) {
			std::cout << "Ativando" << std::endl;
			cheats->localManager.bInfiniteAmmo = true;
			if (cheats->localManager.bInfiniteAmmo) {

				cheats->infiniteAmmo();
			}
		}
		Sleep(100);
	}



	return 0;
}


BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
) {
	switch (ul_reason_for_call) {
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hModule);
		// Create thread
		if (!CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(MainThread), hModule, 0, nullptr)) {
			CloseHandle(hModule);
		}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}


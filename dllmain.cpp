#include "pch.h"
#include "Cheats.h"
#include "Menu.h"
#include <thread>

static constexpr const char* OVERLAY_WINDOW_CLASS_NAME = "MyImGuiOverlayClass";
static constexpr const char* OVERLAY_WINDOW_NAME = "MyImGuiOverlay";


DWORD WINAPI MainThread(HMODULE hModule) {
	//create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout); // only output
	std::cout << "Injected!" << std::endl;
	Cheats* cheats = new Cheats();

	bool bInfiniteAmmo = false;

	GMenu.initilizeWindow(hModule, OVERLAY_WINDOW_CLASS_NAME, OVERLAY_WINDOW_NAME);
	Menu::handleMessages();

	FreeLibraryAndExitThread(hModule, 0);



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


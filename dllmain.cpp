#include "pch.h"
#include "Cheats.h"
#include "Menu.h"
#include <thread>
#include "hkMouseMove.h"
#include "hkShowCursor.h"
#include "Hook.h"


static constexpr const char* OVERLAY_WINDOW_CLASS_NAME = "MyImGuiOverlayClass";
static constexpr const char* OVERLAY_WINDOW_NAME = "MyImGuiOverlay";


DWORD WINAPI MainThread(HMODULE hModule) {
	//create console
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout); // only output
	std::cout << "Injected!" << std::endl;
	Cheats* cheats = new Cheats();


	HMODULE moduleSDL = GetModuleHandleA("SDL.dll");
	BYTE* pShowCursor = reinterpret_cast<BYTE*>(GetProcAddress(moduleSDL, "SDL_ShowCursor"));
	oShowCursor = reinterpret_cast<ShowCursor_t>(trampHook32(pShowCursor, reinterpret_cast<BYTE*>(hkShowCursor), 5));




	bool bInfiniteAmmo = false;

	Hook* hookMouseMove = new Hook(reinterpret_cast<BYTE*>(AddrBase::MODULE_BASE + AddrBase::FUNC_MOVE_MOUSE), reinterpret_cast<BYTE*>(&hkMoveMouse), reinterpret_cast<BYTE*>(&MoveMouse), 10);
	hookMouseMove->enable();







	/*Hook* hookShowCursor = new Hook("SDL_ShowCursor", "SDL.dll", )*/

	GMenu.initilizeWindow(hModule, OVERLAY_WINDOW_CLASS_NAME, OVERLAY_WINDOW_NAME);

	while (true) {
		GMenu.initCheats();
		Menu::handleMessages();
	}


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


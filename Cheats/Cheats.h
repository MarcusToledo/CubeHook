#pragma once
#include "Memory/Memory.h"
#include "Memory/PatternScanner.h"
#include "Memory/Reclass.h"
#include "Hooks/Hook.h"

class Cheats {
private:
	Entity* localPlayerPtr_{ *reinterpret_cast<Entity**>(AddrBase::MODULE_BASE + Offset::LOCAL_PLAYER) }; //ptr to local player
	PatternScanner* patternScanner_ = new PatternScanner("ac_client.exe"); // init pattern scanner and get modInfo

	DWORD ammoAddr_ = NULL; // ptr to ammo
	BYTE* fixByteAmmo_ = nullptr; // Original instructions for ammo function
public:
	//controllers for the cheat
	struct Local {
		bool bInfiniteAmmo = false;
	} localManager;
	struct cCheats {
		bool bInfiniteAmmo = false;
	};

	//methods
	cCheats* cheatManager = new cCheats;
	Cheats(); // constructor
	~Cheats(); // destructor

	void infiniteAmmo(); //TODO: Transform these methods into classes?
	//TODO: Add more features


};


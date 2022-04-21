#pragma once
#include "PatternScanner.h"
#include "Reclass.h"
#include "Memory.h"

class Cheats {
private:
	const uintptr_t moduleBase_ = (reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)));
	Entity* localPlayerPtr_{ *reinterpret_cast<Entity**>(moduleBase_ + Offset::LOCAL_PLAYER) };
	PatternScanner* patternScanner_ = new PatternScanner("ac_client.exe"); // init pattern scanner and get modInfo
public:
	//controllers for the cheat
	struct Local {
		bool bAmmo = false;
	} localManager;
	struct cCheats {
		bool bAmmo = false;
	};

	//methods
	cCheats* cheatManager = new cCheats;
	Cheats(); // constructor
	~Cheats(); // destructor

	void infiniteAmmo();


};


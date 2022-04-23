#pragma once
#include "PatternScanner.h"
#include "Reclass.h"
#include "Memory.h"

class Cheats {
private:
	Entity* localPlayerPtr_{ *reinterpret_cast<Entity**>(AddrBase::MODULE_BASE + Offset::LOCAL_PLAYER) };
	PatternScanner* patternScanner_ = new PatternScanner("ac_client.exe"); // init pattern scanner and get modInfo
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

	void infiniteAmmo();


};


#pragma once
#include "PatternScanner.h"

class Cheats {
private:
	DWORD ammoAddr = NULL;

	PatternScanner* patternScanner = new PatternScanner("ac_client.exe"); // init pattern scanner and get modInfo
public:
	//controllers for the cheat
	struct Local {
		bool bAmmo = false;
	} localManager;
	struct cCheats {
		bool bAmmo = false;
	};

	//methods
	cCheats* cheatManager;
	Cheats(); // constructor
	~Cheats(); // destructor

	void infiniteAmmo();


};


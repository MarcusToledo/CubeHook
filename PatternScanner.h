#pragma once
#include <Windows.h>
#include <TlHelp32.h>
#include <Psapi.h>

class PatternScanner {
private:
	MODULEINFO modInfo{ 0 };
public:
	PatternScanner(const char* modName);
	//constructor

	MODULEINFO getModuleInfo(const char* szModule);
	DWORD scanPattern(const char* szModule, const char* szPattern, const char* szMask);
};

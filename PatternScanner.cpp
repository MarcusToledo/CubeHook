#include "pch.h"
#include "PatternScanner.h"

PatternScanner::PatternScanner(const char* modName) {

	this->modInfo = getModuleInfo(modName);
}

MODULEINFO PatternScanner::getModuleInfo(const char* szModule) {
	MODULEINFO modInfo = { 0 };
	HMODULE hModule = GetModuleHandle(szModule); // return the handle of module

	if (hModule == NULL) {
		return modInfo;
	}

	GetModuleInformation(GetCurrentProcess(), hModule, &modInfo, sizeof(MODULEINFO)); // return informations of module

	return modInfo;
}

DWORD PatternScanner::scan(const char* szPattern, const char* szMask) {
	auto base = reinterpret_cast<DWORD>(this->modInfo.lpBaseOfDll); // get the module address
	DWORD size = this->modInfo.SizeOfImage; // get the size of module
	size_t patternLength = strlen(szMask); // size_t gives more optimization

	for (DWORD i = 0; i < size - patternLength; i++) {
		bool found = true;

		for (DWORD j = 0; j < patternLength; j++) {
			found &= szMask[j] == '?' || szPattern[j] == *reinterpret_cast<char*>(base + i + j); // verifica se o caracter da mask é ? ou se o caracter do pattern é igual ao caracter da mask
		}

		if (found) {
			return base + i; // if found returns the address
		}
	}
	return NULL;
}

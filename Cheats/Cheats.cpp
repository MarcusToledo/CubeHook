#include "pch.h"
#include "Cheats.h"


Cheats::Cheats() {

}

Cheats::~Cheats() {
	delete patternScanner_;
	delete cheatManager;
}

void Cheats::infiniteAmmo() {
	if (cheatManager->bInfiniteAmmo && !localManager.bInfiniteAmmo) { // Se cheat manager for true em localManager deve estar ao contrário
		this->localPlayerPtr_->currentWeapon->clipAmmo->ammo = 1337;
		localManager.bInfiniteAmmo = true; // seta como ativado no controlador local
	}
	if (!cheatManager->bInfiniteAmmo && localManager.bInfiniteAmmo) {
		localManager.bInfiniteAmmo = false;
	}

}

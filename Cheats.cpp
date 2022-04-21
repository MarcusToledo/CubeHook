#include "pch.h"
#include "Cheats.h"


Cheats::Cheats() {

}

Cheats::~Cheats() {
	delete patternScanner_;
	delete cheatManager;
}

void Cheats::infiniteAmmo() {
	this->localPlayerPtr_->currentWeapon->clipAmmo->ammo = 1337;
}

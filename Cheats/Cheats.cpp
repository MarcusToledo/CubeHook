#include "pch.h"
#include "Cheats.h"




Cheats::Cheats() : ammoAddr_(patternScanner_->scan(Pattern::INFINITY_AMMO, Pattern::INFINITY_AMMO_MASK)) {
	//TODO: Constructor?
}

Cheats::~Cheats() {
	delete patternScanner_;
	delete cheatManager;
}

void Cheats::infiniteAmmo() {
	if (cheatManager->bInfiniteAmmo && !localManager.bInfiniteAmmo) { // Se cheat manager for true em localManager deve estar ao contr�rio
		this->localPlayerPtr_->currentWeapon->clipAmmo->ammo = 1337;

		fixByteAmmo_ = new BYTE[Pattern::INFINITY_AMMO_LEN]; //aloca o espa�o para os byte originais
		memcpy(fixByteAmmo_, reinterpret_cast<BYTE*>(ammoAddr_), Pattern::INFINITY_AMMO_LEN); // copia bytes originais para fixByteAmmo_
		nop(reinterpret_cast<BYTE*>(ammoAddr_), Pattern::INFINITY_AMMO_LEN); // seta nop para os byes de ammo TODO: Verificar remo��o dos casts
		localManager.bInfiniteAmmo = true; // seta como ativado no controlador local
	}
	if (!cheatManager->bInfiniteAmmo && localManager.bInfiniteAmmo) {
		patch(reinterpret_cast<BYTE*>(ammoAddr_), fixByteAmmo_, Pattern::INFINITY_AMMO_LEN); // Retorna os bytes originais
		this->localPlayerPtr_->currentWeapon->clipAmmo->ammo = 30; // Seta muni��o para 30 novamente TODO: Validar muni��o padr�o da arma atual (30 � o padr�o para ar)
		localManager.bInfiniteAmmo = false;
	}

}

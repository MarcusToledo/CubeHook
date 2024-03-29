#pragma once

namespace AddrBase {
	const uintptr_t MODULE_BASE{ reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr)) };
	constexpr auto FUNC_MOVE_MOUSE{ 0x05C690 };
}

namespace Pattern {
	constexpr auto  GOD_MODE{ "\x55\x8B\xEC\x83\xE4\x00\x81\xEC\x00\x00\x00\x00\x53\x56\x8B\xF0" };
	constexpr auto GOD_MODE_MASK{ "xxxxx?xx????xxxx" };

	constexpr auto INFINITY_AMMO{ "\xFF\x0E\x57\x8B\x7C\x00\x00\x8D\x74\x00\x00\xE8\x00\x00\x00\x00\x5F\x5E\xB0\x00\x5B\x8B\xE5\x5D\xC2\x00\x00\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\x55" };
	constexpr auto INFINITY_AMMO_MASK{ "xxxxx??xx??x????xxx?xxxxx??xxxxxxxxxxxxx" };
	constexpr auto INFINITY_AMMO_LEN{ 2 }; //Size used to write opcodes

	constexpr auto NO_RECOIL{ "\x50\x8D\x4C\x00\x00\x51\x8B\xCE\xFF\xD2\x8B\x46\x00\x3B\x05" };
	constexpr auto NO_RECOIL_MASK{ "xxx??xxxxxxx?xx" };
	constexpr auto NO_RECOIL_LEN{ 10 }; //Size used to write opcodes
}

namespace Offset {
	//Entitys
	constexpr auto NO_RECOIL_INIT_ADDR{ 0x63786 };
	//constexpr auto LOCAL_PLAYER{ 0x109B74 };
	constexpr auto LOCAL_PLAYER{ 0x10F4F4 };
	//constexpr auto ENTITY_LIST{ 0x10F4F8 };
	constexpr auto ENTITY_BASE_HOP_OFFSET{ 0x4 };//?good for scanning through enemies, every enemy is 0x4 away from the previous one
}

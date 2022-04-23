#pragma once

namespace AddrBase {
	const uintptr_t MODULE_BASE = reinterpret_cast<uintptr_t>(GetModuleHandle(nullptr));
	constexpr auto FUNC_MOVE_MOUSE = 0x05C690;
}

namespace Pattern {
	constexpr auto  GOD_MODE = "\x55\x8B\xEC\x83\xE4\x00\x81\xEC\x00\x00\x00\x00\x53\x56\x8B\xF0";
	constexpr auto GOD_MODE_MASK = "xxxxx?xx????xxxx";
}

namespace Offset {
	//Entitys
	constexpr auto NO_RECOIL_INIT_ADDR = 0x63786;
	//constexpr auto LOCAL_PLAYER = 0x109B74;
	constexpr auto LOCAL_PLAYER = 0x10F4F4;
	//constexpr auto ENTITY_LIST = 0x10F4F8;
	constexpr auto ENTITY_BASE_HOP_OFFSET = 0x4;//?good for scanning through enemies, every enemy is 0x4 away from the previous one
}

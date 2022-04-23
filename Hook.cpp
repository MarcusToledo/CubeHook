#include "pch.h"
#include "Hook.h"


void patch(BYTE* dst, BYTE* src, unsigned int size) {
	DWORD oldProtect;
	VirtualProtect(dst, size, PAGE_EXECUTE_READWRITE, &oldProtect);
	memcpy_s(dst, size, src, size);
	VirtualProtect(dst, size, oldProtect, &oldProtect);
}

bool detour32(BYTE* src, BYTE* dst, const uintptr_t len) { //place jmp
	if (len < 5)
		return false;
	DWORD oldProtect;
	VirtualProtect(src, len, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(src, 0x90, len);
	uintptr_t relativeAddr = dst - (src + 5);
	*src = 0xE9;
	*reinterpret_cast<uintptr_t*>(src + 1) = relativeAddr;
	VirtualProtect(src, len, oldProtect, &oldProtect);
	return true;
}

BYTE* trampHook32(BYTE* src, BYTE* dst, const uintptr_t len) {
	if (len < 5)
		return nullptr;
	BYTE* gateway = static_cast<BYTE*>(VirtualAlloc(0, len + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE));
	memcpy_s(gateway, len, src, len);
	uintptr_t gatewayRelativeAddr = src - gateway - 5;
	*(gateway + len) = 0xE9;
	*reinterpret_cast<uintptr_t*>(reinterpret_cast<uintptr_t>(gateway) + len + 1) = gatewayRelativeAddr;
	detour32(src, dst, len);
	return gateway;
}

Hook::Hook(BYTE* src, BYTE* dst, BYTE* gatewayPtr, SIZE_T len) : mSrc_(src), mDst_(dst), mGatewayPtr_(gatewayPtr),
mLen_(len), mOriginalBytes_(new BYTE[len]) {
}

Hook::Hook(BYTE* src, BYTE* dst, SIZE_T len) : mSrc_(src), mDst_(dst), mGatewayPtr_(nullptr), mLen_(len), mOriginalBytes_(new BYTE[len]) {}

Hook::Hook(const char* exportName, const char* moduleName, BYTE* dst, BYTE* gatewayPtr, SIZE_T len) : mDst_(dst),
mGatewayPtr_(gatewayPtr), mLen_(len) {
	if (HMODULE hModule = GetModuleHandleA(moduleName))
		mSrc_ = reinterpret_cast<BYTE*>(GetProcAddress(hModule, exportName));
	this->mOriginalBytes_ = new BYTE[len];
}

bool Hook::detour32() { //place jmp
	if (mLen_ < 5)
		return false;
	DWORD oldProtect;
	VirtualProtect(mSrc_, mLen_, PAGE_EXECUTE_READWRITE, &oldProtect);
	memset(mSrc_, 0x90, mLen_);
	uintptr_t relativeAddr = mDst_ - (mSrc_ + 5);
	*mSrc_ = 0xE9;
	*reinterpret_cast<uintptr_t*>(mSrc_ + 1) = relativeAddr;
	VirtualProtect(mSrc_, mLen_, oldProtect, &oldProtect);
	return true;
}

bool Hook::getStatus() {
	return this->m_bStatus_;
}
void Hook::enable() {
	memcpy_s(mOriginalBytes_, mLen_, mSrc_, mLen_);
	*reinterpret_cast<uintptr_t*>(mGatewayPtr_) = reinterpret_cast<uintptr_t>(trampHook32(mSrc_, mDst_, mLen_));
	m_bStatus_ = true;
}

void Hook::disable() {
	patch(mSrc_, mOriginalBytes_, mLen_);
	VirtualFree(reinterpret_cast<void*>(*reinterpret_cast<uintptr_t*>(mGatewayPtr_)), 0, MEM_RELEASE);
	m_bStatus_ = false;
}
Hook::~Hook() {
	if (m_bStatus_)
		disable();
	delete[] this->mOriginalBytes_;
}
void Hook::toggle() {
	if (!m_bStatus_) {
		enable();
		Sleep(10);
	}
	else {
		disable();
		Sleep(10);
	}
}
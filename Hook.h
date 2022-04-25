#pragma once
#include "pch.h"



void patch(BYTE* dst, BYTE* src, unsigned int size);
bool detour32(BYTE* src, BYTE* dst, const uintptr_t len);
BYTE* trampHook32(BYTE* src, BYTE* dst, const uintptr_t len);


class Hook {
private:
	bool m_bStatus_{ false };
	BYTE* mSrc_{ nullptr };
	BYTE* mDst_{ nullptr };
	BYTE* mGatewayPtr_{ nullptr };
	SIZE_T mLen_{ 0 };
	BYTE* mOriginalBytes_{ nullptr };
public:
	bool getStatus();
	void enable();
	void disable();
	Hook(BYTE* src, BYTE* dst, BYTE* gatewayPtr, SIZE_T len);
	Hook(BYTE* src, BYTE* dst, SIZE_T len);
	Hook(const char* exportName, const char* moduleName, BYTE* dst, BYTE* gatewayPtr, SIZE_T len);
	~Hook();
	void toggle();

};


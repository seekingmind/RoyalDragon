#include "rdpch.h"

#define ROYALDRAGON_BUILD_ID "v0.1a"

namespace RoyalDragon {
	void InitializeCore()
	{
		RoyalDragon::Log::Init();
		
		RD_CORE_WARN("RoyalDragon Engine {}", ROYALDRAGON_BUILD_ID);
		RD_CORE_INFO("Initializing...");
	}
	
	void ShutdownCore()
	{
		RD_CORE_WARN("Shutting down...");
	}
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		RoyalDragon::InitializeCore();
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		RoyalDragon::ShutdownCore();
		break;
	}
	return TRUE;
}

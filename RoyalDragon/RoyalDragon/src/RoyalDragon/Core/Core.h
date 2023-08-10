#pragma once

namespace RoyalDragon {
	void InitializeCore();
	void ShutdownCore();
}

#ifdef RD_PLATEFORM_WINDOWS
	#ifdef ROYALDRAGON_BUILD_DLL
		#define ROYALDRAGON_API __declspec(dllexport)
	#else
		#define ROYALDRAGON_API __declspec(dllimport)
	#endif // ROYALDRAGON_BUILD_DLL
#else
#error "RoyalDragon only support Windows!"
#endif // RD_PLATEFORM_WINDOWS

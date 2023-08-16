#pragma once

namespace RoyalDragon {
	void InitializeCore();
	void ShutdownCore();
}

#ifdef  RD_DEBUG
	#define RD_ENABLE_ASSERTS
#endif //  RD_DEBUG


#ifdef RD_PLATEFORM_WINDOWS
	#ifdef ROYALDRAGON_BUILD_DLL
		#define ROYALDRAGON_API __declspec(dllexport)
	#else
		#define ROYALDRAGON_API __declspec(dllimport)
	#endif // ROYALDRAGON_BUILD_DLL
#else
#error "RoyalDragon only support Windows!"
#endif // RD_PLATEFORM_WINDOWS

#ifdef RD_ENABLE_ASSERTS
	#define RD_ASSERT(x, ...) { if(!(x)) { RD_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define RD_CORE_ASSERT(x, ...) { if(!(x)) { RD_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RD_ASSERT(x, ...)
#define RD_CORE_ASSERT(x, ...)
#endif // RD_ENABLE_ASSERTS

#define BIT(x) (1 << x)

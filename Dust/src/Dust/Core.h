#pragma once

#ifdef DUST_PLATFORM_WINDOWS
	#ifdef DUST_BUILD_DLL
		#define DUST_API __declspec(dllexport)
	#else
		#define DUST_API __declspec(dllexport)
	#endif
#else
	#error Dust only supports Windows!
#endif

#define DUST_ASSERT(x, ...) { if(!(x)) { DUST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define DUST_CORE_ASSERT(x, ...) { if(!(x)) { DUST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define BIT(x) (1 << x)

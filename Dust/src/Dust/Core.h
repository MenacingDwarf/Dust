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

#ifdef DUST_DEBUG
	#define DUST_ENABLE_ASSERTS
#endif

#ifdef DUST_ENABLE_ASSERTS
	#define DUST_ASSERT(x, ...) { if(!(x)) { DUST_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define DUST_CORE_ASSERT(x, ...) { if(!(x)) { DUST_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define DUST_ASSERT(x, ...)
	#define DUST_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define DUST_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)

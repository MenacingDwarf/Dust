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

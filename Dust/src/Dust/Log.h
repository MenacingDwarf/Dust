#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

typedef std::shared_ptr<spdlog::logger> LoggerRef;

namespace Dust {

	class DUST_API Log
	{
	public:
		static void Init();
		static void Deinit();

		static LoggerRef& GetCoreLogger();
		static LoggerRef& GetClientLogger();

	private:
		static Log* instance;
		LoggerRef s_core_logger;
		LoggerRef s_client_logger;
	};
}

// Core log macros
#define DUST_CORE_TRACE(...)	::Dust::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define DUST_CORE_INFO(...)		::Dust::Log::GetCoreLogger()->info(__VA_ARGS__);
#define DUST_CORE_WARN(...)		::Dust::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define DUST_CORE_ERROR(...)	::Dust::Log::GetCoreLogger()->error(__VA_ARGS__);
#define DUST_CORE_FATAL(...)	::Dust::Log::GetCoreLogger()->fatal(__VA_ARGS__);

// Client log macros
#define DUST_TRACE(...)	::Dust::Log::GetClientLogger()->trace(__VA_ARGS__);
#define DUST_INFO(...)	::Dust::Log::GetClientLogger()->info(__VA_ARGS__);
#define DUST_WARN(...)	::Dust::Log::GetClientLogger()->warn(__VA_ARGS__);
#define DUST_ERROR(...)	::Dust::Log::GetClientLogger()->error(__VA_ARGS__);
#define DUST_FATAL(...)	::Dust::Log::GetClientLogger()->fatal(__VA_ARGS__);


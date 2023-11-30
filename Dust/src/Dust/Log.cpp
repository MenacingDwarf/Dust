#include "dustpch.h"
#include "Log.h"

#include "spdlog/sinks/stdout_color_sinks.h"

namespace Dust {

	Log* Log::instance = nullptr;

	void Log::Init()
	{
		instance = new Log();
		
		spdlog::set_pattern("%^[%T] %n: %v%$");

		instance->s_core_logger = spdlog::stdout_color_mt("DUST");
		instance->s_core_logger->set_level(spdlog::level::trace);

		instance->s_client_logger = spdlog::stdout_color_mt("APP");
		instance->s_client_logger->set_level(spdlog::level::trace);
	}

	void Log::Deinit()
	{
		if (instance != nullptr)
		{
			delete instance;
		}
	}

	LoggerRef& Log::GetCoreLogger()
	{
		if (instance != nullptr)
		{
			return instance->s_core_logger;
		}

		auto null_logger = std::make_shared<spdlog::logger>(nullptr);
		return null_logger;
	}
	
	LoggerRef& Log::GetClientLogger()
	{
		if (instance != nullptr)
		{
			return instance->s_client_logger;
		}

		auto null_logger = std::make_shared<spdlog::logger>(nullptr);
		return null_logger;
	}
}

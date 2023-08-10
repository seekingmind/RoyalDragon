#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/bundled/ostream.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace RoyalDragon {
	class ROYALDRAGON_API Log
	{
	public:
		static void Init();
		
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// 引擎核心日志宏
#define RD_CORE_TRACE(...)		RoyalDragon::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RD_CORE_INFO(...)		RoyalDragon::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RD_CORE_WARN(...)		RoyalDragon::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RD_CORE_ERROR(...)		RoyalDragon::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RD_CORE_FATAL(...)		RoyalDragon::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// 其它项目日志宏
#define RD_TRACE(...)			RoyalDragon::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RD_INFO(...)			RoyalDragon::Log::GetClientLogger()->info(__VA_ARGS__)
#define RD_WARN(...)			RoyalDragon::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RD_ERROR(...)			RoyalDragon::Log::GetClientLogger()->error(__VA_ARGS__)
#define RD_FATAL(...)			RoyalDragon::Log::GetClientLogger()->fatal(__VA_ARGS__)

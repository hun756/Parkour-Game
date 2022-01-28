#include <stdarg.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>

enum class LogLevel
{
	Info,
	Warn,
	Error
};

static const char* toStr(LogLevel ll)
{
	switch(ll)
	{
	case LogLevel::Info: {
		return "[INFO] ";
		break;
	}
	case LogLevel::Error: {
		return "[ERROR] ";
		break;
	}
	case LogLevel::Warn: {
		return "[WARN] ";
		break;
	}
	}

	throw std::domain_error("Logging Level Error");
}

inline void __log(LogLevel ll, const char* msg, ...)
{
	char out_msg[3200];
	std::memset(out_msg, 0, sizeof(out_msg));

	__builtin_va_list argPtr;
	va_start(argPtr, msg);
	vsnprintf(out_msg, 3200, msg, argPtr);
	va_end(argPtr);

	char _out[3200];
	sprintf(_out, "%s%s\n", toStr(ll), out_msg);

	fprintf(stdout, "%s", _out);
}

#define _P_LOG_INFO(msg, ...) __log(LogLevel::Info, msg, ##__VA_ARGS__)
#define _P_LOG_WARN(msg, ...) __log(LogLevel::Warn, msg, ##__VA_ARGS__)
#define _P_LOG_ERR(msg, ...) __log(LogLevel::Error, msg, ##__VA_ARGS__)
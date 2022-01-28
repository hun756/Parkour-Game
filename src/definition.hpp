

///< Assertions

#include <Windows.h>
#include <cstdint>
#include <debugapi.h>
#include <memory>
#include <winbase.h>


void assertionFaileure(const char* exp, const char* msg, const char* file, int32_t line);

#define _P_ASSERT(expr)                                                                            \
	{                                                                                              \
		if(expr)                                                                                   \
			else                                                                                   \
			{                                                                                      \
				assertionFailure(#expr, "", __FILE__, __LINE__);                                   \
				DebugBreak();                                                                      \
			}                                                                                      \
	}

#define _P_ASSERT_MSG(expr, msg)                                                                   \
	{                                                                                              \
		if(expr)                                                                                   \
			else                                                                                   \
			{                                                                                      \
				assertionFailure(#expr, msg, __FILE__, __LINE__);                                  \
				DebugBreak();                                                                      \
			}                                                                                      \
	}

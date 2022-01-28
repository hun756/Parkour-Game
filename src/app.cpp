#include <iostream>
#include <string>
#include <vector>

#ifdef _WIN32
#include <tchar.h>
#else
typedef char _TCHAR;
#define _tmain main
#endif

namespace App
{
	static void Run(std::vector<std::string> args)
	{
		///< Program starting point..!
	}
} // namespace App

int _tmain(int argc, const _TCHAR* argv[])
{
	App::Run({argv + 1, argc + argv});
	return 0;
}
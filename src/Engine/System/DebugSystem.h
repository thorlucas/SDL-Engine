#ifndef _DEBUG_SYSTEM_H_
#define _DEBUG_SYSTEM_H_

#include <cstdio>

namespace Thor_Lucas_Development {

/**
 * Used to debug things.
 */
class DebugSystem {
public:
	static DebugSystem& get();

	void log(const char* s);
	static void slog(const char* s);
};

}

#endif // _DEBUG_SYSTEM_H_
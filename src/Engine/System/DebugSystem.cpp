#include "DebugSystem.h"
#include "../Engine.h"

namespace Thor_Lucas_Development {

DebugSystem& DebugSystem::get() {
	return Engine::get().getDebugSystem();
}

void DebugSystem::log(const char* s) {
	printf("%s\n", s);
}

void DebugSystem::slog(const char* s) {
	DebugSystem::get().log(s);
}

}
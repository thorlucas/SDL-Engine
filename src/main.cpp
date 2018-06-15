#include "Engine.h"

using namespace Thor_Lucas_Development;

int main(int argc, char const *argv[]) {
	// Engine engine = Engine();
	Engine& engine = Engine::get();
	engine.init();
	engine.mainLoop();

	return 0;
}
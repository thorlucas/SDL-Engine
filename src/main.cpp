#include "Engine.h"

using namespace Thor_Lucas_Development;

int main(int argc, char const *argv[]) {
	Renderer renderer = Renderer("Hello, World!");
	TextureManager textureManager = TextureManager(renderer, "./resources/");
	RenderSystem renderSystem = RenderSystem(renderer, textureManager);

	Engine engine = Engine(renderSystem);

	engine.mainLoop();

	return 0;
}
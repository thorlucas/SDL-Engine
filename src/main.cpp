#include "Engine.h"

using namespace Thor_Lucas_Development;

int main(int argc, char const *argv[]) {
	Engine* engine = new Engine();
	Renderer* renderer = new Renderer("Hello, World!");
	TextureManager* textureManager = new TextureManager(renderer, "./resources/");
	
	engine->setRenderer(renderer);
	engine->setTextureManager(textureManager);

	textureManager->createTexture("bg.jpg", "background");

	engine->mainLoop();

	delete renderer;
	delete engine;

	return 0;
}
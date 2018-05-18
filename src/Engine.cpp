#include "Engine.h"

namespace Thor_Lucas_Development {

Engine::Engine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
		throw EngineException("Failed to initialize SDL.");

	renderer = nullptr;
}

Engine::~Engine() {
	SDL_Quit();
}

void Engine::setRenderer(Renderer* r) {
	renderer = r;
}

void Engine::setTextureManager(TextureManager* t) {
	textureManager = t;
}

void Engine::mainLoop() {
	if (renderer == nullptr) throw EngineException("Renderer not set.");
	if (textureManager == nullptr) throw EngineException("Texture manager not set.");

	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
				case SDL_QUIT:
					quit = true; break;
				default: break;
			}
			renderer->addToRenderQueue(textureManager->getTexture("background"));
			renderer->render();
		}
	}
}

} // namespace Thor_Lucas_Development
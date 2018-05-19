#include "Engine.h"

namespace Thor_Lucas_Development {

Engine::Engine(RenderSystem& rs) : renderSystem(rs) {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
		throw EngineException("Failed to initialize SDL.");

	renderSystem.init();

	dummy = renderSystem.createRenderComponent();
}

Engine::~Engine() {	
	renderSystem.killRenderComponent(dummy);

	SDL_Quit();
}

void Engine::mainLoop() {
	SDL_Event event;
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event) != 0) {
			switch (event.type) {
				case SDL_QUIT:
					quit = true; break;
				default: break;
			}
		}

		renderSystem.render();
	}
}

} // namespace Thor_Lucas_Development
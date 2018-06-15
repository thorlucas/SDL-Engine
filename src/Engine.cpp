#include "Engine.h"
#include <sstream>

namespace Thor_Lucas_Development {

Engine::Engine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
		throw EngineException("Failed to initialize SDL.");

	// init debug system
	// init event system
	renderSystem.init("Hello, world!");
	resourceSystem.init(renderSystem.getRenderer());
}

Engine::~Engine() {
	resourceSystem.quit();
	renderSystem.quit();
	// quit debug system

	SDL_Quit();
}

void Engine::init() {
	quit = false;
	
	eventSystem.attachType(this, SDL_QUIT);

	resourceSystem.loadTexture("bg", "./resources/bg.jpg");
}

EventSystem& Engine::getEventSystem() {
	return eventSystem;
}

RenderSystem& Engine::getRenderSystem() {
	return renderSystem;
}

ResourceSystem& Engine::getResourceSystem() {
	return resourceSystem;
}

DebugSystem& Engine::getDebugSystem() {
	return debugSystem;
}

void Engine::mainLoop() {
	while (!quit) {
		eventSystem.handleEvents();
		renderSystem.render();
	}
}

void Engine::event(SDL_Event& event) {
	if (event.type == SDL_QUIT) {
		quit = true;
	}
}

} // namespace Thor_Lucas_Development
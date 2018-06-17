#include "Engine.h"
#include <sstream>

namespace Thor_Lucas_Development {

Engine::Engine() {
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_EVENTS) != 0)
		throw EngineException("Failed to initialize SDL.");

	// init debug system
	// init event system
	// init logic system
	renderSystem.init("Hello, world!");
	resourceSystem.init(renderSystem.getRenderer());
}

Engine::~Engine() {
	resourceSystem.quit();
	renderSystem.quit();
	// quit debug system
	// quit event system
	// quit logic system

	SDL_Quit();
}

void Engine::init() {
	quit = false;
	eventSystem.attachType([&](Event::Event& event) {
		if (event.type == Event::QUIT) quit = true;
	}, Event::QUIT);
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

LogicSystem& Engine::getLogicSystem() {
	return logicSystem;
}

void Engine::mainLoop() {
	while (!quit) {
		eventSystem.handleEvents();
		logicSystem.update();
		renderSystem.render();
	}
}

} // namespace Thor_Lucas_Development
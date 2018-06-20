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
	logicSystem.init();
	// entitySystem.init(100);
}

Engine::~Engine() {
	// entitySystem.quit();
	logicSystem.quit();
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

// EntitySystem& Engine::getEntitySystem() {
// 	return entitySystem;
// }

void Engine::mainLoop() {
	int frames;
	Uint32 accTime = 0;

	Uint32 currentTime;
	Uint32 deltaTime;
	lastTime = SDL_GetTicks();
	while (!quit) {
		currentTime = SDL_GetTicks();
		deltaTime = currentTime - lastTime;

		eventSystem.handleEvents();
		logicSystem.update(deltaTime);
		renderSystem.render();

		accTime += deltaTime;
		frames += 1;

		if (accTime >= 1000) {
			printf("%d FPS\n", frames);
			accTime = 0;
			frames = 0;
		}

		lastTime = currentTime;
	}
}

} // namespace Thor_Lucas_Development
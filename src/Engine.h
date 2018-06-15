#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SDL.h>
#include "EngineException.h"
#include "System/RenderSystem.h"
#include "System/ResourceSystem.h"
#include "System/DebugSystem.h"
#include "System/EventSystem.h"

namespace Thor_Lucas_Development {

/**
 * An SDL engine for games. 
 * This is a singleton. Get it by calling Engine::get().
 */
class Engine : public EventObserver {
private:
	EventSystem eventSystem;
	RenderSystem renderSystem;
	ResourceSystem resourceSystem;
	DebugSystem debugSystem;

	bool quit;
public:
	Engine();
	~Engine();

	static Engine& get() {
		static Engine sEngine;
		return sEngine;
	}

	void init();

	RenderSystem& getRenderSystem();
	ResourceSystem& getResourceSystem();
	DebugSystem& getDebugSystem();
	EventSystem& getEventSystem();

	void mainLoop();

	// Event Observer
	void event(SDL_Event& event);
};

} // namespace Thor_Lucas_Development

#endif // _ENGINE_H_
#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SDL.h>
#include "EngineException.h"

#include "System/RenderSystem.h"

namespace Thor_Lucas_Development {

// --------------- ENGINE --------------- //

/** An SDL engine for games. */
class Engine {
private:
	RenderSystem& renderSystem;
	RenderComponent* dummy;
public:
	Engine(RenderSystem& rs);
	~Engine();

	void mainLoop();
};

} // namespace Thor_Lucas_Development

#endif // _ENGINE_H_
#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#include <vector>
#include <SDL.h>
#include "../EngineException.h"
#include "../Component/RenderComponent.h"
#include "DebugSystem.h"

#include <cstdio>

namespace Thor_Lucas_Development {

/**
 * Singleton that manages a window, and rendering to that window.
 * All render components should be managed by this system.
 * The singleton should be managed by the Engine class, and that class ONLY.
 * TODO: Will this be a singleton after all? Or should each scene have one?
 * TODO: Consider making this a friend of Engine and the constructor private.
 */
class RenderSystem {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;

	std::vector<RenderComponent> components; /**< All the components which are rendered on render(). TODO: Replace. */
public:
	RenderSystem() {};
	~RenderSystem() {};

	/**
	 * Constructs the renderer.
	 * @param t the title on the window.
	 * @param w the width of the window.
	 * @param h the height of the window.
	 * @param x the x position of the window, or SDL_WINDOWPOS_UNDEFINED.
	 * @param y the y position of the window, or SDL_WINDOWPOS_UNDEFINED.
	 * @param f the flags for creating the window, like SDL_WINDOW_FULLSCREEN.
	 * TODO: Make it return an Err instead of throwing on error.
	 */
	void init(const char* t,
			  int w = 640, int h = 480,
			  int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED,
			  Uint32 f = 0);

	/**
	 * Destroys the window and the renderer.
	 */
	void quit();

	/**
	 * Renders all components.
	 */
	void render();

	/**
	 * @returns the renderer used.
	 * TODO: Do we still need this?
	 */
	SDL_Renderer* getRenderer();

	/**
	 * Creates a new component in this system.
	 * The component must still be initialized as normal.
	 * @returns a reference to the created component.
	 */
	RenderComponent& getNewComponent();
};

}

#endif // _RENDER_SYSTEM_H_
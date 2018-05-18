#ifndef _RENDERER_H_
#define _RENDERER_H_

#include "EngineException.h"
#include <SDL.h>
#include <queue>

namespace Thor_Lucas_Development {

/** An SDL 2 renderer. */
class Renderer {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::queue<SDL_Texture*> renderQueue;
public:
	/**
	 * Constructs the renderer.
	 * @param title the title on the window.
	 * @param width the width of the window.
	 * @param height the height of the window.
	 * @param x the x position of the window, or SDL_WINDOWPOS_UNDEFINED.
	 * @param y the y position of the window, or SDL_WINDOWPOS_UNDEFINED.
	 * @param flags the flags for creating the window, like SDL_WINDOW_FULLSCREEN.
	 */
	Renderer(const char* title,
			 int width = 640, int height = 480,
			 int x = SDL_WINDOWPOS_UNDEFINED, int y = SDL_WINDOWPOS_UNDEFINED,
			 Uint32 flags = 0);

	~Renderer();

	/**
	 * Creates a texture from a given surface, optimized to this renderer.
	 * @param surface the surface to be converted.
	 * @returns the texture.
	 */
	SDL_Texture* createTexture(SDL_Surface* surface);

	/**
	 * Adds a texture to the render queue.
	 * Behaves in a FIFO manner.
	 * @param texture the texture to be copied to the surface.
	 */
	void addToRenderQueue(SDL_Texture* texture);

	/** Performs the rendering. */
	void render();
};

} // namespace Thor_Lucas_Development

#endif // _RENDERER_H_
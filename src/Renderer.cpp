#include "Renderer.h"

namespace Thor_Lucas_Development {

Renderer::Renderer(const char* title, int width, int height, int x, int y, Uint32 flags) {
	window = nullptr; renderer = nullptr;

	if (SDL_WasInit(SDL_INIT_VIDEO) == 0) throw EngineException("SDL is not initialized.");

	window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (window == nullptr) throw EngineException("Failed to initialize window.");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) throw EngineException("Failed to initialize renderer.");
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

SDL_Texture* Renderer::createTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) throw EngineException("Unable to convert surface to texture.");
	return texture;
}

void Renderer::addToRenderQueue(SDL_Texture* texture) {
	renderQueue.push(texture);
}

void Renderer::render() {
	SDL_RenderClear(renderer);
	while (!renderQueue.empty()) {
		SDL_RenderCopy(renderer, renderQueue.front(), NULL, NULL);
		renderQueue.pop();
	}
	SDL_RenderPresent(renderer);
}

} // namespace Thor_Lucas_Development
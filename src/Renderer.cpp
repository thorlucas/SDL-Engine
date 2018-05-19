#include "Renderer.h"

namespace Thor_Lucas_Development {

Renderer::Renderer(const char* t, int w, int h, int x_, int y_, Uint32 f) : 
	title(t), width(w), height(h), x(x_), y(y_), flags(f) {
	window = nullptr; renderer = nullptr;
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void Renderer::init() {
	if (SDL_WasInit(SDL_INIT_VIDEO) == 0) throw EngineException("SDL is not initialized.");

	window = SDL_CreateWindow(title, x, y, width, height, flags);
	if (window == nullptr) throw EngineException("Failed to initialize window.");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) throw EngineException("Failed to initialize renderer.");
}

// TODO: Some sort of FAST flag for checking if it was initialized
SDL_Texture* Renderer::createTexture(SDL_Surface* surface) {
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (texture == NULL) throw EngineException("Unable to convert surface to texture.");
	return texture;
}

// TODO: Some sort of FAST flag for checking if it was initialized
void Renderer::addToRenderQueue(SDL_Texture* texture) {
	renderQueue.push(texture);
}

// TODO: Some sort of FAST flag for checking if it was initialized
void Renderer::render() {
	SDL_RenderClear(renderer);
	while (!renderQueue.empty()) {
		SDL_RenderCopy(renderer, renderQueue.front(), NULL, NULL);
		renderQueue.pop();
	}
	SDL_RenderPresent(renderer);
}

} // namespace Thor_Lucas_Development
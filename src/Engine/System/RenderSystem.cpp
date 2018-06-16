#include "RenderSystem.h"
#include "../Engine.h"

namespace Thor_Lucas_Development {
	
void RenderSystem::init(const char* t, int w, int h, int x, int y, Uint32 f) {
	if (SDL_WasInit(SDL_INIT_VIDEO) == 0) throw EngineException("SDL is not initialized.");

	window = nullptr; renderer = nullptr;

	window = SDL_CreateWindow(t, x, y, w, h, f);
	if (window == nullptr) throw EngineException("Failed to initialize window.");

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) throw EngineException("Failed to initialize renderer.");
}

void RenderSystem::quit() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderSystem::render() {
	SDL_RenderClear(renderer);
	for (auto it : components) {
		SDL_RenderCopy(renderer, it.texture, NULL, &it.dest);
	}
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderSystem::getRenderer() {
	return renderer;
}

RenderComponent& RenderSystem::getNewComponent() {
	components.emplace_back();
	return components.back();
}

} // namespace Thor_Lucas_Development
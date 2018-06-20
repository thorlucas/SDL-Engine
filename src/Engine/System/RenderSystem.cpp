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

	head = nullptr;
}

void RenderSystem::quit() {
	RenderEntry* entry = head;
	RenderEntry* next;
	while (entry != nullptr) {
		next = entry->next;
		delete entry;
		entry = next;
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
}

void RenderSystem::render() {
	SDL_RenderClear(renderer);
	RenderEntry* entry = head;
	while (entry != nullptr) {
		SDL_RenderCopy(renderer, entry->render->texture, NULL, &(entry->render->dest));
		entry = entry->next;
	}
	SDL_RenderPresent(renderer);
}

SDL_Renderer* RenderSystem::getRenderer() {
	return renderer;
}

RenderSystem::RenderEntry* RenderSystem::registerComponent(RenderComponent* component) {
	RenderEntry* entry = new RenderEntry{nullptr, component, head};
	if (head != nullptr) head->prev = entry;
	head = entry;

	return entry;
}

void RenderSystem::removeComponent(RenderEntry* handle) {
	if (handle->prev != nullptr)
		handle->prev->next = handle->next;
	else
		head = handle->next;

	if (handle->next != nullptr) handle->next->prev = handle->prev;

	delete handle;
}

} // namespace Thor_Lucas_Development
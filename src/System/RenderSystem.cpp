#include "RenderSystem.h"

namespace Thor_Lucas_Development {

RenderSystem::RenderSystem(Renderer& r, TextureManager& tm) : renderer(r), textureManager(tm) {
	poolHead = &pool[0];
	for (int i = 0; i < POOL_SIZE; ++i) {
		pool[i] = RenderComponent();
		pool[i].kill(i != POOL_SIZE-1 ? &pool[i+1] : nullptr);
	}
}

RenderSystem::~RenderSystem() { }

void RenderSystem::init() {
	renderer.init();
	textureManager.init();

	textureManager.createTexture("bg.jpg", "dummy");
}

RenderComponent* RenderSystem::createRenderComponent() {
	SDL_Texture* texture = textureManager.getTexture("dummy");

	RenderComponent* component = poolHead;
	poolHead = component->init(texture);

	return component;
}

void RenderSystem::killRenderComponent(RenderComponent* component) {
	component->kill(poolHead);
	poolHead = component;
}

void RenderSystem::render() {
	for (int i = 0; i < POOL_SIZE; ++i) {
		if (!pool[i].isDead()) {
			renderer.addToRenderQueue(pool[i].getTexture());
		}
	}

	renderer.render();
}

} // namespace Thor_Lucas_Development
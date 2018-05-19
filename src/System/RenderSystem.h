#ifndef _RENDER_SYSTEM_H_
#define _RENDER_SYSTEM_H_

#define POOL_SIZE 20

#include "../Renderer.h"
#include "../TextureManager.h"
#include "../Component/RenderComponent.h"

namespace Thor_Lucas_Development {

class RenderSystem {
private:
	/**
	 * Stores the graphics components to be rendered.
	 * TODO: Make this into some sort of object pool.
	 */
	RenderComponent pool[POOL_SIZE];
	RenderComponent* poolHead;

	TextureManager& textureManager;
	Renderer& renderer;
public:
	RenderSystem(Renderer& r, TextureManager& tm);
	~RenderSystem();
	void init();

	RenderComponent* createRenderComponent();
	void killRenderComponent(RenderComponent*);

	void render();
};

}

#endif // _RENDER_SYSTEM_H_
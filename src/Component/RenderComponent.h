#ifndef _GRAPHICS_COMPONENT_H_
#define _GRAPHICS_COMPONENT_H_

#include <SDL.h>
#include "../System/DebugSystem.h"

namespace Thor_Lucas_Development {

class RenderComponent {
friend class RenderSystem;
private:
	SDL_Texture* texture;
public:
	SDL_Rect dest; // Temp

	RenderComponent() {};
	~RenderComponent() {};

	bool isDead();
	SDL_Texture* getTexture();

	/**
	 * Initializes the component.
	 * @param t the texture to be rendered.
	 */
	void init(SDL_Texture* t, int x, int y, int w, int h);
	void quit();
};

}

#endif //_GRAPHICS_COMPONENT_H_
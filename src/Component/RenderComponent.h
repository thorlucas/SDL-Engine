#ifndef _GRAPHICS_COMPONENT_H_
#define _GRAPHICS_COMPONENT_H_

#include <SDL.h>

namespace Thor_Lucas_Development {

class RenderComponent {
private:
	bool dead;

	union {
		struct {
			SDL_Texture* texture;
			SDL_Rect drect;
		} live;

		RenderComponent* nextDead;
	};
public:
	RenderComponent();
	~RenderComponent();

	bool isDead();
	SDL_Texture* getTexture();

	/**
	 * Initializes the component, setting it to not dead.
	 * @param t the texture to be rendered.
	 * @returns a pointer to the next dead component.
	 */
	RenderComponent* init(SDL_Texture* t);	

	/**
	 * Kills the component, setting it to dead.
	 * @param d the next dead component in the pool.
	 */
	void kill(RenderComponent* d);
};

}

#endif //_GRAPHICS_COMPONENT_H_
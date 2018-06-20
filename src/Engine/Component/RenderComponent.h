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
	SDL_Rect dest; // TODO: Temp

	RenderComponent(SDL_Texture* t, SDL_Rect d) : texture(t), dest(d) {};
	~RenderComponent() {};
};

}

#endif //_GRAPHICS_COMPONENT_H_
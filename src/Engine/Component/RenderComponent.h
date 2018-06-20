#ifndef _RENDER_COMPONENT_H_
#define _RENDER_COMPONENT_H_

#include <SDL.h>
#include <cstdio>
#include "../util.h"

namespace Thor_Lucas_Development {

class RenderComponent {
friend class RenderSystem;
protected:
	Texture* texture;
	Rect src;
	Rect dest;

public:
	RenderComponent(Texture* t, Rect d, Rect s) : texture(t), dest(d), src(s) {};
	~RenderComponent() {};
};

}

#endif //_RENDER_COMPONENT_H_
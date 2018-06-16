#include "RenderComponent.h"

namespace Thor_Lucas_Development {

void RenderComponent::init(SDL_Texture* t, int x, int y, int w, int h) {
	texture = t;
	dest.x = x; dest.y = y; dest.w = w; dest.h = h;
}

SDL_Texture* RenderComponent::getTexture() {
	return texture;
}

}
#include "RenderComponent.h"

namespace Thor_Lucas_Development {

RenderComponent::RenderComponent() { }

RenderComponent::~RenderComponent() { }

bool RenderComponent::isDead() {
	return dead;
}

SDL_Texture* RenderComponent::getTexture() {
	return live.texture;
}

RenderComponent* RenderComponent::init(SDL_Texture* t) {
	dead = false;

	live.texture = t;
	// TODO
	live.drect.x = 0; live.drect.y = 0;
	live.drect.w = 64; live.drect.h = 64;

	return nextDead;
}

void RenderComponent::kill(RenderComponent* d) {
	dead = true;
	nextDead = d;
}

}
#include "ResourceSystem.h"
#include "../Engine.h"
#include "RenderSystem.h"

namespace Thor_Lucas_Development {

void ResourceSystem::init(/*const char rp, */SDL_Renderer* r) {
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) throw EngineException("Failed to initialize image library.");
	renderer = r;
}

void ResourceSystem::quit() {
	for (auto it = textureMap.begin(); it != textureMap.end(); ++it) {
		freeAnonymousTexture(it->second);
	}
}

SDL_Texture* ResourceSystem::createAnonymousTexture(const char* path) {
	SDL_Surface* s = IMG_Load(path);
	SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);
	SDL_FreeSurface(s);

	return t;
}

void ResourceSystem::freeAnonymousTexture(SDL_Texture* t) {
	SDL_DestroyTexture(t);
}

void ResourceSystem::loadTexture(std::string name, const char* path) {
	textureMap[name] = createAnonymousTexture(path);
}

SDL_Texture* ResourceSystem::getTexture(std::string name) {
	return textureMap.at(name);
}

void ResourceSystem::freeTexture(std::string name) {
	freeAnonymousTexture(textureMap.at(name));
	textureMap.erase(name);
}

}
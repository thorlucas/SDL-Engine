#ifndef _RESOURCE_SYSTEM_H_
#define _RESOURCE_SYSTEM_H_

#include <unordered_map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "../EngineException.h"
#include "DebugSystem.h"

#include <cstdio>

namespace Thor_Lucas_Development {

/**
 * Manages the resources (texutres and etc).
 * The one issue is: SDL_CreateTexture allocates the texture for us,
 * so we can't use a custom allocator for efficiency. TODO
 */
class ResourceSystem {
private:
	SDL_Renderer* renderer; /**< Taken from RendererSystem in order to create textures. */
	std::unordered_map<std::string, SDL_Texture*> textureMap;
	// TODO: Should I really be holding a pointer to it? Seems unsafe. But too slow to fetch it every time.
	// char* resourcePath;
public:
	ResourceSystem() {};
	~ResourceSystem() {};

	void init(/*const char rp, */SDL_Renderer* r);
	void quit();

	SDL_Texture* createAnonymousTexture(const char* path);
	void freeAnonymousTexture(SDL_Texture* t);

	void loadTexture(std::string name, const char* path);
	SDL_Texture* getTexture(std::string name);
	void freeTexture(std::string name);
};

}

#endif // _RESOURCE_SYSTEM_H_
#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <map>
#include <string>
#include <SDL.h>
#include <SDL_image.h>
#include "EngineException.h"
#include "Renderer.h"

namespace Thor_Lucas_Development {

/** Texture manager for tiles, sprites, etc. */
class TextureManager {
private:
	Renderer& renderer; /**< The renderer used when creating textures. */
	std::map<std::string, SDL_Texture*> textureMap;
	std::string resourcePath;
public:
	/**
	 * Constructs the texture manager with a given renderer.
	 * @param r renderer.
	 * @param rp the path to the resources folder.
	 */
	TextureManager(Renderer& r, std::string rp = "");
	~TextureManager();	

	void init();

	SDL_Texture* createTexture(std::string fileName, std::string textureName);

	SDL_Texture* getTexture(std::string textureName);
};

} // namespace Thor_Lucas_Development

#endif // _TEXTURE_MANAGER_H_
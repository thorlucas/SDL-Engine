#include "TextureManager.h"

namespace Thor_Lucas_Development {

TextureManager::TextureManager(Renderer* r, std::string rp) : renderer(r), resourcePath(rp) {
	if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) == 0) throw EngineException("Failed to initialize image library.");
}
TextureManager::~TextureManager() {
	for (auto it = textureMap.begin(); it != textureMap.end(); ++it) {
		SDL_DestroyTexture((*it).second);
	}
}

void TextureManager::createTexture(std::string fileName, std::string textureName) {
	SDL_Surface* surface = IMG_Load((resourcePath + fileName).c_str());
	if (surface == NULL) throw EngineException("Unable to load image: %s", fileName.c_str());

	SDL_Texture* texture = renderer->createTexture(surface);
	textureMap[textureName] = texture;

	SDL_FreeSurface(surface);
}

SDL_Texture* TextureManager::getTexture(std::string textureName) {
	return textureMap[textureName];
	// TODO: Throw an exception
}

} // namespace Thor_Lucas_Development
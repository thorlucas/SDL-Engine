#ifndef _ENGINE_H_
#define _ENGINE_H_

#include <SDL.h>
#include "EngineException.h"
#include "Renderer.h"
#include "TextureManager.h"

namespace Thor_Lucas_Development {

// --------------- ENGINE --------------- //

/** An SDL engine for games. */
class Engine {
private:
	Renderer* renderer;
	TextureManager* textureManager;	
public:
	Engine();
	~Engine();

	/** 
	 * Sets the current renderer to be used.
	 * @param r the renderer.
	 * TODO: Meh
	 */
	void setRenderer(Renderer* r);

	/**
	 * Sets the current texture manager to be used.
	 * @param t the texture manager.
	 * TODO: Meh
	 */
	void setTextureManager(TextureManager* t);

	void mainLoop();
};

} // namespace Thor_Lucas_Development

#endif // _ENGINE_H_
#ifndef _SPRITE_COMPONENT_H_
#define _SPRITE_COMPONENT_H_

#include "../System/ResourceSystem.h"
#include "RenderComponent.h"

namespace Thor_Lucas_Development {

class SpriteRenderComponent : public RenderComponent {
friend class RenderSystem;
private:
	Point position;

public:
	SpriteRenderComponent(ResourceSystem& rs, std::string texName, Rect d);
	SpriteRenderComponent(ResourceSystem& rs, std::string texName, Rect d, Rect s);
	SpriteRenderComponent(Texture* tex, Rect d);
	SpriteRenderComponent(Texture* tex, Rect d, Rect s);
	~SpriteRenderComponent() {};

	void move(const Vector& dist);
};

}

#endif //_SPRITE_COMPONENT_H_
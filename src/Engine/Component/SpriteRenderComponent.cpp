#include "SpriteRenderComponent.h"
#include "../System/RenderSystem.h"

namespace Thor_Lucas_Development {

SpriteRenderComponent::SpriteRenderComponent(ResourceSystem& rs, std::string texName, Rect d) : 
	SpriteRenderComponent(rs.getTexture(texName), d) {}

SpriteRenderComponent::SpriteRenderComponent(ResourceSystem& rs, std::string texName, Rect d, Rect s) :
	SpriteRenderComponent(rs.getTexture(texName), d, s) {}

SpriteRenderComponent::SpriteRenderComponent(Texture* tex, Rect d) :
	SpriteRenderComponent(tex, d, getTextureDimensions(tex)) {}

SpriteRenderComponent::SpriteRenderComponent(Texture* tex, Rect d, Rect s) :
	RenderComponent(tex, d, s) {
	position.x = float(dest.x);
	position.y = float(dest.y);		
}

void SpriteRenderComponent::move(const Vector& dist) {
	position += dist;
	convertPointToRect(position, dest);
}

}
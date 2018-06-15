#include "CharacterEntity.h"

namespace Thor_Lucas_Development {

CharacterEntity::CharacterEntity(RenderComponent* r) : render(r) { }

CharacterEntity::~CharacterEntity() { }

RenderComponent* CharacterEntity::getRender() {
	return render;
}

}
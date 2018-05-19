#include "CharacterEntity.h"

namespace Thor_Lucas_Development {

CharacterEntity::CharacterEntity(RenderComponent* g) : graphics(g) { }

CharacterEntity::~CharacterEntity() {
	delete graphics;
}

}
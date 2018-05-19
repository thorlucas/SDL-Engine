#ifndef _CHARACTER_ENTITY_H_
#define _CHARACTER_ENTITY_H_

#include "../Component/RenderComponent.h"

namespace Thor_Lucas_Development {

class CharacterEntity {
private:
	RenderComponent* graphics;
public:
	CharacterEntity(RenderComponent* g);

	/** TODO: Does character entity own this component? */
	~CharacterEntity();
};

}

#endif // _CHARACTER_ENTITY_H_
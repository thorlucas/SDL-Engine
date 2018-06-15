#ifndef _CHARACTER_ENTITY_H_
#define _CHARACTER_ENTITY_H_

#include "../Component/RenderComponent.h"

namespace Thor_Lucas_Development {

class CharacterEntity {
private:
	RenderComponent* render;
public:
	/**
	 * Creates the entity.
	 * @param g a render component, which should be returned from the RenderSystem.
	 */
	CharacterEntity(RenderComponent* render);

	/**
	 * The character should be deleted by a manager,
	 * which will properly destroy the render component.
	 * TODO: What if it's not? Should we set a flag?
	 * the render system could loop through and kill
	 * the components that are flagged for death.
	 */
	~CharacterEntity();

	RenderComponent* getRender();
};

}

#endif // _CHARACTER_ENTITY_H_
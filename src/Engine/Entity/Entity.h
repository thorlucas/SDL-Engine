#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../Component/RenderComponent.h"

/**
 * Base entity class. Managed by the EntitySystem.
 * The EntitySystem calls the init and the quit functions
 * when the entity is added or removed.
 */
class Entity {
public:
	Entity() {};
	~Entity() {};

	// virtual void init() = 0;
	// virtual void quit() = 0;
};

#endif //_ENTITY_H_
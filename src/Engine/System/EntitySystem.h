#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

#include <vector>
#include "Entity.h"

namespace Thor_Lucas_Development {

/**
 * Manages the creation, storage, and deletion of entities.
 */
class EntitySystem {
private:
	std::vector<Entity*> entities;
public:
	EntitySystem() {};
	~EntitySystem() {};

	// void init();
	// void quit();

	void addEntity()
};

}

#endif //_ENTITY_SYSTEM_H_
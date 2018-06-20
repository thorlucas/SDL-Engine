#ifndef _ENTITY_SYSTEM_H_
#define _ENTITY_SYSTEM_H_

#include <vector>
#include "../Entity/Entity.h"

namespace Thor_Lucas_Development {

/**
 * Manages the creation, storage, and deletion of entities.
 */
class EntitySystem {
public:
	struct EntityEntry {
		bool alive;
		union {
			EntityEntry* nextDead; /**< The next dead entry if the entry is dead. */
			Entity* entity; /**< The entity if the entry is alive. */
		};
	};
private:
	int poolSize; /**< TODO: This should be const but can't... */
	EntityEntry* pool; /**< A fixed pool array of entries. */
	EntityEntry* head; /**< The first dead entry. */
public:
	EntitySystem() {};
	~EntitySystem() {};

	void init(int ps);
	void quit();

	EntityEntry* addEntity(Entity* entity);
	void killEntity(EntityEntry* handle);
};

}

#endif //_ENTITY_SYSTEM_H_
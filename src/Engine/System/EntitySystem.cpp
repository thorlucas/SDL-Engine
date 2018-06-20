#include "EntitySystem.h"

namespace Thor_Lucas_Development {

void EntitySystem::init(int ps) {
	poolSize = ps;
	pool = new EntityEntry[poolSize];

	head = pool;
	for (EntityEntry* entry = pool; entry < pool+poolSize; ++entry) {
		entry->alive = false;
		if (entry != pool+poolSize-1) {
			entry->nextDead = entry+1;
		} else {
			entry->nextDead = nullptr;
		}
	}
}

void EntitySystem::quit() {
	for (EntityEntry* entry = pool; entry < pool+poolSize; ++entry) {
		killEntity(entry);
	}
}

// TODO: Add safe guards to make sure entity is appropriately dead or alive.
EntitySystem::EntityEntry* EntitySystem::addEntity(Entity* entity) {
	if (head == nullptr) return nullptr; // TODO: THROW ERROR!!!

	EntityEntry* entry = head;
	head = entry->nextDead;
	entry->alive = true;
	entry->entity = entity;
	// entity->init();
	return entry;
}

void EntitySystem::killEntity(EntityEntry* handle) {
	if (!handle->alive) return;

	// handle->entity->quit();
	delete handle->entity;
	handle->alive = false;
	handle->nextDead = head;
	head = handle;
}

}
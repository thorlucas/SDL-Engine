#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "../Component/RenderComponent.h"

/**
 * Base entity class. Managed by the EntitySystem.
 */
class Entity {
private:
	RenderComponent& renderComponent;
public:
	Entity(RenderComponent& rc) : renderComponent(rc) {};
	~Entity() {};
}

#endif //_ENTITY_H_
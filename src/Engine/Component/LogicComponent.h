#ifndef _LOGIC_COMPONENT_H_
#define _LOGIC_COMPONENT_H_

#include "RenderComponent.h"
#include "../System/EventSystem.h"

namespace Thor_Lucas_Development {

class LogicComponent {
friend class LogicSystem;
public:
	virtual ~LogicComponent() {};

	virtual void update() = 0;
};

}

#endif //_LOGIC_COMPONENT_H_
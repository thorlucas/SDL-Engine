#ifndef _LOGIC_COMPONENT_H_
#define _LOGIC_COMPONENT_H_

#include "RenderComponent.h"
#include "../System/EventSystem.h"

namespace Thor_Lucas_Development {

class LogicComponent : public EventObserver {
friend class LogicSystem;
public:
	LogicComponent() {};
	~LogicComponent() {};

	virtual void init() = 0;
	virtual void quit() = 0;

	virtual void update() = 0;
	virtual void event(SDL_Event& event) = 0;
};

}

#endif //_LOGIC_COMPONENT_H_
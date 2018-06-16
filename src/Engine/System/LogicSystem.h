#ifndef _LOGIC_SYSTEM_H_
#define _LOGIC_SYSTEM_H_

#include <vector>
#include "../Component/LogicComponent.h"

namespace Thor_Lucas_Development {

class LogicSystem {
private:
	std::vector<LogicComponent*> components;
public:
	LogicSystem() {};
	~LogicSystem() {};

	// void init();
	// void quit();

	void update();

	void addLogicComponent(LogicComponent* l);
};

}

#endif //_LOGIC_SYSTEM_H_
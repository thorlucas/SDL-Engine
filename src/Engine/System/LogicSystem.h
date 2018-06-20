#ifndef _LOGIC_SYSTEM_H_
#define _LOGIC_SYSTEM_H_

#include <vector>
#include "../Component/LogicComponent.h"

namespace Thor_Lucas_Development {

class LogicSystem {
public:
	struct LogicEntry {
		LogicEntry* next;
		LogicComponent* logic;
		LogicEntry* prev;

		~LogicEntry() {
			delete logic;
		};
	};

private:
	LogicEntry* head;
public:
	LogicSystem() {};
	~LogicSystem() {};

	void init();
	void quit();

	void update();

	LogicEntry* registerComponent(LogicComponent* l);
	void removeComponent(LogicEntry* handle);
};

typedef LogicSystem::LogicEntry* LogicHandle;

}

#endif //_LOGIC_SYSTEM_H_
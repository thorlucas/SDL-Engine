#include "LogicSystem.h"

namespace Thor_Lucas_Development {

void LogicSystem::update() {
	for (auto it : components) {
		it->update();
	}
}

void LogicSystem::addLogicComponent(LogicComponent* l) {
	components.push_back(l);
}

}
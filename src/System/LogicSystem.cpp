#include "LogicSystem.h"

namespace Thor_Lucas_Development {

void LogicSystem::update() {
	for (auto it : components) {
		it.update();
	}
}

LogicComponent& LogicSystem::getNewComponent() {
	components.emplace_back();
	return components.back();
}

}
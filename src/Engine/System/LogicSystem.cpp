#include "LogicSystem.h"
#include "DebugSystem.h"

namespace Thor_Lucas_Development {

void LogicSystem::init() {
	head = nullptr;
}

void LogicSystem::quit() {
	LogicEntry* entry = head;
	LogicEntry* next;
	while (entry != nullptr) {
		next = entry->next;
		delete entry;
		entry = next;
	}
}

void LogicSystem::update() {
	LogicEntry* entry = head;
	while (entry != nullptr) {
		entry->logic->update();
		entry = entry->next;
	}
}

LogicSystem::LogicEntry* LogicSystem::registerComponent(LogicComponent* l) {
	LogicEntry* entry = new LogicEntry{nullptr, l, head};
	if (head != nullptr) head->prev = entry;
	head = entry;

	return entry;
}

void LogicSystem::removeComponent(LogicEntry* handle) {
	if (handle->prev != nullptr)
		handle->prev->next = handle->next;
	else
		head = handle->next; // Handle must be the head.

	if (handle->next != nullptr) handle->next->prev = handle->prev;
	delete handle;
}

}
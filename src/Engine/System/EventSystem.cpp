#include "EventSystem.h"
#include "DebugSystem.h"

namespace Thor_Lucas_Development {

void EventSystem::notifyKey() {
	auto found = keyObservers.find(event.key.keysym.sym);
	if (found == keyObservers.end()) {
		return;
	}
	ObserverEntry* entry = found->second;
	do {
		entry->observer->event(event);
		entry = entry->nextEntry;
	} while (entry != nullptr);
}

void EventSystem::notifyType() {
	auto found = typeObservers.find(event.type);
	if (found == typeObservers.end()) return;
	ObserverEntry* entry = found->second;
	do {
		entry->observer->event(event);
		entry = entry->nextEntry;
	} while (entry != nullptr);
}

void EventSystem::handleEvents() {
	while (SDL_PollEvent(&event) != 0) {
		switch (event.type) {
			case SDL_QUIT:
				notifyType();
				break;
			case SDL_KEYDOWN:
				notifyType();
				notifyKey();
				break;
			case SDL_KEYUP:
				notifyType();
				notifyKey();
				break;
			default: break;
		}
	}
}

void EventSystem::attachKey(EventObserver* o, SDL_Keycode code) {
	auto found = keyObservers.find(code);
	ObserverEntry* last = (found == keyObservers.end()) ? nullptr : found->second;
	ObserverEntry* entry = new ObserverEntry;
	entry->nextEntry = last;
	entry->observer = o;

	keyObservers[code] = entry;
}

void EventSystem::attachType(EventObserver* o, SDL_EventType type) {
	auto found = typeObservers.find(type);
	ObserverEntry* last = (found == typeObservers.end()) ? nullptr : found->second;
	ObserverEntry* entry = new ObserverEntry;
	entry->nextEntry = last;
	entry->observer = o;

	typeObservers[type] = entry;
}

}
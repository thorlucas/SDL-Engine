#include "EventSystem.h"
#include "DebugSystem.h"

namespace Thor_Lucas_Development {

void EventSystem::notifyKey() {
	ObserverEntry* entry = keyObservers[event.key];
	if (entry == nullptr) return;

	do {
		entry->callback(event);
		entry = entry->nextEntry;
	} while (entry != nullptr);
}

void EventSystem::notifyType() {
	ObserverEntry* entry = typeObservers[event.type];
	if (entry == nullptr) return;

	do {
		entry->callback(event);
		entry = entry->nextEntry;
	} while (entry != nullptr);
}

void EventSystem::handleEvents() {
	while (SDL_PollEvent(&sdlevent) != 0) {
		Event::convertEvent(sdlevent, event);
		switch (event.type) {
			case Event::QUIT:
				notifyType();
				break;
			case Event::KEYDOWN:
				notifyType();
				notifyKey();
				break;
			case Event::KEYUP:
				notifyType();
				notifyKey();
				break;
			default: break;
		}
	}
}

void EventSystem::attachKey(Event::EventCallback callback, Event::Keycode code) {
	ObserverEntry* last = keyObservers[code];
	ObserverEntry* entry = new ObserverEntry(callback, last);
	keyObservers[code] = entry;
}

void EventSystem::attachType(Event::EventCallback callback, Event::EventType type) {
	ObserverEntry* last = typeObservers[type];
	ObserverEntry* entry = new ObserverEntry(callback, last);
	typeObservers[type] = entry;
}

}
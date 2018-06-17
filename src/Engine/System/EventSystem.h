#ifndef _EVENT_SYSTEM_H_
#define _EVENT_SYSTEM_H_

#include <SDL.h>
#include <functional>
#include "Event.h"

namespace Thor_Lucas_Development {

/**
 * Manages and notifies observers of subscribed events.
 * Register by calling attachKey or attachType.
 */
class EventSystem {
private:
	/**
	 * Entry into a map of observers. It's a singly-linked
	 * list, pointing to the next entry. nullptr if no next.
	 */
	struct ObserverEntry {
		Event::EventCallback callback;
		ObserverEntry* nextEntry; 
		ObserverEntry(Event::EventCallback cb, ObserverEntry* ne) : callback(cb), nextEntry(ne) {};
	};

	ObserverEntry* keyObservers[Event::KEYCODE_SIZE]; /**< Keycode to observer map. */
	ObserverEntry* typeObservers[Event::EVENTTYPE_SIZE]; /**< Type to observer map. */

	SDL_Event sdlevent;
	Event::Event event;

	void notifyKey(); /**< Notifies observers of key events. */
	void notifyType(); /**< Notifies observers of type events. */
public:
	EventSystem() : keyObservers(), typeObservers() {};
	~EventSystem() {};

	// init, quit

	/**
	 * Polls the events and notifies the appropriate observers.
	 * Called by Engine. No need to manually call this ever.
	 */
	void handleEvents();

	/**
	 * Attach an observer to a specific keycode. Use this when you want to be
	 * notified of a specific key press, either up or down.
	 * Note for the callback, the lambda function will typically look something like this:
	 * `[&](Event& event) { ... }`
	 * @param callback a lambda expression of type Event::EventCallback.
	 * @param code the Event::Keycode to be listened to.
	 */
	void attachKey(Event::EventCallback callback, Event::Keycode code);

	/**
	 * Attach an observer to a specific event type.
	 * Use this to be notified of any event of type 'type'. For example, QUIT.
	 * Note for the callback, the lambda function will typically look something like this:
	 * `[&](Event& event) { ... }`
	 * @param callback a lambda expression of type Event::EventCallback.
	 * @param type the Event::EventType to be listened to.
	 */
	void attachType(Event::EventCallback callback, Event::EventType type);
};

}

#endif // _EVENT_SYSTEM_H_
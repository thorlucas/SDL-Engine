#ifndef _EVENT_SYSTEM_H_
#define _EVENT_SYSTEM_H_

#include <SDL.h>
#include <map>

namespace Thor_Lucas_Development {

/**
 * Class to be inherited by each observer.
 */
class EventObserver {
public:
	virtual void event(SDL_Event& event) = 0; /**< Must be implemented by observer. */
};

/**
 * Manages and dispatches events to observers.
 */
class EventSystem {
private:
	/**
	 * Entry into a map of observers. It's a singly-linked
	 * list, pointing to the next entry. nullptr if no next.
	 */
	struct ObserverEntry {
		EventObserver* observer;
		ObserverEntry* nextEntry; 
	};

	// TODO: Replace later
	std::map<int, ObserverEntry*> keyObservers; /**< SDL_Keycode to observer map. */
	std::map<int, ObserverEntry*> typeObservers; /**< SDL_EventType to observer map. */

	SDL_Event event;
	void notifyKey();
	void notifyType();
public:
	EventSystem() {};
	~EventSystem() {};

	// init, quit

	/**
	 * Polls the events and notifies the appropriate observers.
	 */
	void handleEvents();

	/**
	 * Attach an observer to a specific keycode.
	 * @param o A pointer to the observer (usually you'll use "this").
	 * @param code the SDL_Keycode to be listened to.
	 */
	void attachKey(EventObserver* o, SDL_Keycode code);

	/**
	 * Attach an observer to a specific event type.
	 * @param o A pointer to the observer (usually you'll use "this").
	 * @param type the SDL_EventType to be listened to.
	 */
	void attachType(EventObserver* o, SDL_EventType type);
};

}

#endif // _EVENT_SYSTEM_H_
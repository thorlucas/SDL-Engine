#ifndef _EVENT_H_
#define _EVENT_H_

#include <SDL.h>

namespace Thor_Lucas_Development {

namespace Event {

enum Keycode {
	KEY_UNKNOWN = -1,
	A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	KEYCODE_SIZE
};

enum EventType {
	TYPE_UNKNOWN = -1,
	QUIT,
	KEYUP,
	KEYDOWN,
	EVENTTYPE_SIZE
};

/**
 * This is the event object you'll receive when subscribing
 * via the event system.
 */
struct Event {
	EventType type; /**< The type of event. */

	/** A union which contains the info of each event. */
	union {
		Keycode key; /**< If the type is KEYUP or KEYDOWN, use this Keycode. */
	};
};

typedef std::function<void(Event&)> EventCallback;

inline Keycode convertSDLKeycode(SDL_Keycode code) {
	// Map 97 (a) - 122 (z) to 0-25 (keycode)
	if (code >= SDLK_a && code <= SDLK_z)
		return (Keycode)((int)code - 97);

	// Unsupported keycode
	return KEY_UNKNOWN;
}

inline EventType convertSDLEventType(SDL_EventType type) {
	switch (type) {
		case SDL_QUIT: return QUIT;
		case SDL_KEYUP: return KEYUP;
		case SDL_KEYDOWN: return KEYDOWN;
		default: return TYPE_UNKNOWN;
	}
}

inline void convertEvent(SDL_Event& sdlevent, Event& event) {
	event.type = convertSDLEventType((SDL_EventType)sdlevent.type);
	if (event.type == KEYUP || event.type == KEYDOWN) {
		event.key = convertSDLKeycode(sdlevent.key.keysym.sym);
	}
}

}

}

#endif //_EVENT_H_
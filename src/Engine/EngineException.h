#ifndef _ENGINE_EXCEPTION_H_
#define _ENGINE_EXCEPTION_H_

#include <exception>
#include <cstring>
#include <cstdio>
#include <cstdarg>

namespace Thor_Lucas_Development {

/** Exception class thrown by the engine and other classes. */
class EngineException : public std::exception {
private:
	char description[256];
public:
	EngineException (const char* format, ...) {
		char buffer[256];
		strcpy(buffer, "Engine Exception: ");
		strcat(buffer, format);

		va_list args;
		va_start(args, format);
		vsprintf(description, buffer, args);
		va_end(args);
	}

	virtual const char* what() const throw() {
		return description;
	}
};

} // namespace Thor_Lucas_Development

#endif // _ENGINE_EXCEPTION_H_
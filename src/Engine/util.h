#ifndef _UTIL_H_
#define _UTIL_H_

#include <SDL.h>

namespace Thor_Lucas_Development {

typedef SDL_Rect Rect;
typedef SDL_Texture Texture;

struct Vector {
	float dx; float dy;
	Vector& operator*=(const float rhs);
	Vector& operator+=(const Vector& rhs);
};

struct Point {
	float x; float y;
	Point& operator+=(const Vector& rhs);
};

Point operator+(const Point& rhs, const Vector& lhs);
Point operator+(const Vector& lhs, const Point& rhs);
Vector operator+(const Vector& lhs, const Vector& rhs);
Vector operator*(const Vector& lhs, const float rhs);
Vector operator*(const float lhs, const Vector& rhs);

/**
 * A helper function to query a texture's dimensions.
 * @param t the texture to query.
 * @returns an SDL_Rect with x & y at 0, and w & h filled in.
 */
SDL_Rect getTextureDimensions(SDL_Texture* t);

void convertPointToRect(Point& point, Rect& rect);

}

#endif //_UTIL_H_
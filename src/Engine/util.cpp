#include "util.h"

namespace Thor_Lucas_Development {

Point& Point::operator+=(const Vector& rhs) {
	x += rhs.dx; y += rhs.dy;
	return *this;
}

Vector& Vector::operator*=(const float rhs) {
	dx *= rhs; dy *= rhs;
	return *this;
}

Vector& Vector::operator+=(const Vector& rhs) {
	dx += rhs.dx; dy += rhs.dy;
	return *this;
}

Point operator+(const Point& lhs, const Vector& rhs) {
	Point ret = lhs;
	ret += rhs;
	return ret;
}

Point operator+(const Vector& lhs, const Point& rhs) {
	return rhs + lhs;
}

Vector operator+(const Vector& lhs, const Vector& rhs) {
	Vector ret = lhs;
	ret += rhs;
	return ret;
}

Vector operator*(const Vector& lhs, const float rhs) {
	Vector ret = lhs;
	ret *= rhs;
	return ret;
}

Vector operator*(const float lhs, const Vector& rhs) {
	return rhs * lhs;
}

SDL_Rect getTextureDimensions(SDL_Texture* t) {
	SDL_Rect ret; ret.x = 0; ret.y = 0;
	SDL_QueryTexture(t, NULL, NULL, &ret.w, &ret.h);
	return ret;
}

void convertPointToRect(Point& point, Rect& rect) {
	rect.x = int(point.x);
	rect.y = int(point.y);
}

}
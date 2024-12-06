#include "Point.hpp"

Point::Point() : _x(0), _y(0) {}

Point::Point(const float x, const float y) : _x(x), _y(y) {}

Point::Point(const Point &other) : _x(other._x), _y(other._y) {}

Point::~Point() {}

Point &Point::operator=(const Point& other) {
	// Since _x and _y are const, we cannot assign them after initialization.
    // The class is immutable once constructed.
    // Thus, we don't actually perform any assignment here.
	(void)other;
	return (*this);
}

const Fixed &Point::getX() const {
	return (this->_x);
}

const Fixed &Point::getY() const {
	return (this->_y);
}
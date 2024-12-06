#include "Fixed.hpp"

Fixed::Fixed() : _fixedPointValue(0) {
	//std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int value) {
	//std::cout << "Int constructor called\n";
	_fixedPointValue = value << _fractionalBits;
}

Fixed::Fixed(const float value) {
	//std::cout << "Float constructor called\n";
	_fixedPointValue = static_cast<int>(roundf(value * (1 << _fractionalBits)));
}



Fixed::Fixed(const Fixed &other) {
	//std::cout << "Copy constructor called\n";
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	//std::cout << "Copy assignment operator called\n";
	if (this != &other) {
		this->_fixedPointValue = other.getRawBits();
	}
	return *this;
}

Fixed::~Fixed() {
	//std::cout << "Destructor called\n";
}

int	Fixed::getRawBits(void) const {
	return this->_fixedPointValue;
}

void Fixed::setRawBits(int const raw) {
	this->_fixedPointValue = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(_fixedPointValue) / (1 << _fractionalBits);
}

int	Fixed::toInt(void) const {
	return _fixedPointValue >> _fractionalBits;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj) {
	os << obj.toFloat();
	return os;
}

bool	Fixed::operator>(const Fixed &other) const {
	return this->_fixedPointValue > other._fixedPointValue;
}

bool	Fixed::operator<(const Fixed &other) const {
	return this->_fixedPointValue < other._fixedPointValue;
}

bool	Fixed::operator>=(const Fixed &other) const {
	return this->_fixedPointValue >= other._fixedPointValue;
}

bool	Fixed::operator<=(const Fixed &other) const {
	return this->_fixedPointValue <= other._fixedPointValue;
}

bool	Fixed::operator==(const Fixed &other) const {
	return this->_fixedPointValue == other._fixedPointValue;
}

bool	Fixed::operator!=(const Fixed &other) const {
	return this->_fixedPointValue != other._fixedPointValue;
}

Fixed	Fixed::operator+(const Fixed &other) const {
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue + other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator-(const Fixed &other) const {
	Fixed	result;
	result._fixedPointValue = this->_fixedPointValue - other._fixedPointValue;
	return (result);
}

Fixed	Fixed::operator*(const Fixed &other) const {
	Fixed	result;
	int64_t temp = (int64_t)this->_fixedPointValue * (int64_t)other._fixedPointValue;
	result._fixedPointValue = (int)(temp >> _fractionalBits);
	return (result);
}

Fixed	Fixed::operator/(const Fixed &other) const {
	if (other._fixedPointValue == 0) {
		std::cerr << "Error: Division by zero" << std::endl;
	}
	Fixed	result;
	int64_t	temp = ((int64_t)this->_fixedPointValue << _fractionalBits) / other._fixedPointValue;
	result._fixedPointValue = (int)temp;
	return (result);
}

Fixed &Fixed::operator++() {
	this->_fixedPointValue += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	this->_fixedPointValue += 1;
	return (temp);
}

Fixed &Fixed::operator--() {
	this->_fixedPointValue -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	this->_fixedPointValue -= 1;
	return (temp);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

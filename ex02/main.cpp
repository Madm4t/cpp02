#include "Fixed.hpp"

int	main(void) {
	//Fixed c(26.7f);
	Fixed		a;
	Fixed const	b(Fixed(5.05f) * Fixed(2));
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max(a, b) << std::endl;
	//std::cout << c <<std::endl;
	return (0);
}
#include <iostream>
#include "Fixed.hpp"

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_ORANGE "\033[33m"
#define C_RESET "\033[0m"


int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	a = Fixed( 1234.4321f );

	std::cout << C_ORANGE"To float test"C_RESET << std::endl;
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << C_ORANGE"To int test"C_RESET << std::endl;
	std::cout << "a is " << a.toInt() << " as integer." << std::endl;
	std::cout << "b is " << b.toInt() << " as integer." << std::endl;
	std::cout << "c is " << c.toInt() << " as integer." << std::endl;
	std::cout << "d is " << d.toInt() << " as integer." << std::endl;
	
	return 0;
}
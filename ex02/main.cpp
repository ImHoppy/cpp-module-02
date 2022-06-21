#include <iostream>
#include "Fixed.hpp"

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_ORANGE "\033[33m"
#define C_RESET "\033[0m"

#define TEST(A, B) std::cout << a << " " << #A << " " << B << " = " << (a A B) << std::endl;

int main( void ) {
	std::cout << C_ORANGE"Subject test"C_RESET << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << C_ORANGE"\nMy own test"C_RESET << std::endl;
	{
		Fixed a(10.10f);
		Fixed b(2);
		Fixed c(10.10f);

		TEST(>, b)
		TEST(<, b)
		
		TEST(>=, b)
		TEST(>=, c)
		TEST(<=, b)
		TEST(<=, c)
		TEST(==, b)
		TEST(==, c)
		TEST(!=, b)
		TEST(!=, c)
		TEST(+, b)
		TEST(-, b)
		TEST(*, b)
		TEST(/, b)
	}
	return 0;
}
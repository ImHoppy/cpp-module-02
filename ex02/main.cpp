#include <iostream>
#include "Fixed.hpp"

#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_ORANGE "\033[33m"
#define C_BLUE "\033[94m"
#define C_RESET "\033[0m"

#define TEST(A, B, C) std::cout << A << "\t\t" << C_BLUE #B C_RESET << "\t" << C << C_GREEN "\t\t= " C_RESET << (A B C) << std::endl;

#define LINE std::cout << std::endl;

int main( void ) {
	std::cout << "\033c \033[33m\n";
	std::cout << C_ORANGE "Subject test" C_RESET << std::endl;
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		std::cout << C_BLUE"a" C_RESET << std::endl;
		std::cout << a << std::endl;

		std::cout << C_BLUE "++a" C_RESET << std::endl;
		std::cout << ++a << std::endl;

		std::cout << C_BLUE "a" C_RESET << std::endl;
		std::cout << a << std::endl;

		std::cout << C_BLUE "a++" C_RESET << std::endl;
		std::cout << a++ << std::endl;

		std::cout << C_BLUE "a" C_RESET << std::endl;
		std::cout << a << std::endl;

		std::cout << C_BLUE "b" C_RESET << std::endl;
		std::cout << b << std::endl;
		
		std::cout << C_BLUE "max( a, b )" C_RESET << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}
	std::cout << C_ORANGE "\nAll operator tests" C_RESET << std::endl;
	{
		Fixed a(10.10f);
		Fixed b(2);
		Fixed c(100);

		TEST(a, >, b)
		TEST(b, >, a)
		TEST(a, <, b)
		TEST(b, <, a)
		LINE

		TEST(a, >=, b)
		TEST(c, >=, c)
		TEST(a, <=, b)
		TEST(c, <=, c)
		TEST(a, ==, b)
		TEST(c, ==, c)
		TEST(a, !=, b)
		TEST(c, !=, c)
		LINE

		TEST(a, +, b)
		TEST(a, -, b)
		TEST(a, *, b)
		TEST(a, /, b)
	}
	return 0;
}
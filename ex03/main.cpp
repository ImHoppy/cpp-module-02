#include <iostream>
#include "Point.hpp"

bool bsp(const Point a, const Point b, const Point c, const Point point);


#define TRIANGLE "\
                                            ██ \n\
                                          ██░░██ \n\
                                        ██░░░░░░██ \n\
                                      ██░░░░░░░░░░██ \n\
                                      ██░░░░░░░░░░██ \n\
                                    ██░░░░░░░░░░░░░░██ \n\
                                  ██░░░░░░░░░░░░░░░░░░██ \n\
                                  ██░░░░░░░░░░░░░░░░░░██ \n\
                                ██░░░░░░░░░░░░░░░░░░░░░░██ \n\
                                ██░░░░░░░░░░░░░░░░░░░░░░██ \n\
                              ██░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                            ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                            ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                          ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                          ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                        ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                        ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                      ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                      ██░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██ \n\
                        ██████████████████████████████████████████ \n\n\
                                            BSP"


#define C_RED "\033[31m"
#define C_GREEN "\033[32m"
#define C_RESET "\033[0m"

void	BSP_TEST( Point const a, Point const b, Point const c, Point const point)
{
	std::cout <<
	"The point :\n" <<
	"\t ( " <<point << "\t)\n" <<
	"Triangle :\n" <<
	"\ta( " << a << "\t)\n" <<
	"\tb( " << b << "\t)\n" <<
	"\tc( " << c << "\t)\n" << std::endl;

	std::cout << (bsp(a, b, c, point) == true ? C_GREEN : C_RED);
	std::cout << "The point " << (bsp(a, b, c, point) == true ? "is" : "is not") << " in the triangle" C_RESET << std::endl;
	std::cout << std::endl << std::endl;
}

int main(void)
{
	//https://imgur.com/a/UIcvSB9
	std::cout << "\033c \033[33m\n";
	std::cout << TRIANGLE << C_RESET <<"\n\n";
	{
		const Point a;
		const Point b(10, 0);
		const Point c(0, 10);
		const Point point(1, 1);
		BSP_TEST(a, b, c, point);
	}
	{
		Point a(-1.5, -1.5);
		Point b(2.5, 2.5);
		Point c(-1, -2);
		Point point(8.5, -9);

		BSP_TEST(a, b, c, point);
	}
	{
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(10, 0);
		
		BSP_TEST(a, b, c, point);
	}
	{
		Point a(0, 0);
		Point b(10, 30);
		Point c(20, 0);
		Point point(0.1, 0.1);
		
		BSP_TEST(a, b, c, point);
	}
	return (0);
}
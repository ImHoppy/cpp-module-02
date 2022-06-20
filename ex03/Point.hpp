#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include <string>

#include "Fixed.hpp"

class Point
{
	private:

		Fixed const	_x;
		Fixed const	_y;

	public:

		Point();
		Point(float const x, float const y);
		Point( Point const & src );

		~Point();

		Fixed const	getX(void) const;
		Fixed const	getY(void) const;

		Point &		operator=( Point const & rhs );

};

std::ostream &			operator<<( std::ostream & o, Point const & i );

#endif /* POINT_H */
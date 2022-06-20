#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(): _x(0), _y(0)
{
}
Point::Point(float const x, float const y): _x(x), _y(y)
{
}

Point::Point( const Point & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	if ( this != &rhs )
	{
		(Fixed)this->_x = rhs.getX();
		(Fixed)this->_y = rhs.getY();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	o << "x = " << i.getX() << " y = " << i.getY();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/


Fixed const					Point::getX(void) const
{
	return this->_x;
}

Fixed const 				Point::getY(void) const
{
	return this->_y;
}

/* ************************************************************************** */
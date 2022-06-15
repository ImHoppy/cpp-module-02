#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point(): _x(0), _y(0)
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
		this->_x.setRawBits(rhs.getX().getRawBits());
		this->_y = rhs.getY();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	//o << "Value = " << i.getValue();
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
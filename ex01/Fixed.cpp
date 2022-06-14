#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed( const int & value )
{
	std::cout << "Int constructor called" << std::endl;
	setRawBits(roundf(value * (1<<_fractionalBits)));
}

Fixed::Fixed( const float & value)
{
	std::cout << "Float constructor called" << std::endl;
	setRawBits(roundf(value * (1<<_fractionalBits)));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float	Fixed::toFloat( void ) const
{
	return ((float) getRawBits()/(1<<_fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return ( getRawBits()>>_fractionalBits);
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Fixed::setRawBits( int const raw )
{
	// std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

int	Fixed::getRawBits( void ) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

/* ************************************************************************** */
#include "Fixed.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed(): _value(0)
{
	#ifdef DEBUG
		std::cout << "Default constructor called" << std::endl;
	#endif
}

Fixed::Fixed( const Fixed & src )
{
	#ifdef DEBUG
		std::cout << "Copy constructor called" << std::endl;
	#endif
	*this = src;
}

Fixed::Fixed( const int & value )
{
	#ifdef DEBUG
		std::cout << "Int constructor called" << std::endl;
	#endif
	setRawBits(TORAWBIT(value));
}

Fixed::Fixed( const float & value)
{
	#ifdef DEBUG
		std::cout << "Float constructor called" << std::endl;
	#endif
	setRawBits(TORAWBIT(value));
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	#ifdef DEBUG
		std::cout << "Destructor called" << std::endl;
	#endif
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed &				Fixed::operator=( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Copy assignation operator called" << std::endl;
	#endif
	if ( this != &rhs )
	{
		this->_value = rhs.getRawBits();
	}
	return *this;
}

Fixed &		Fixed::operator>( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Greater than operator called" << std::endl;
	#endif
	return (this->_value > rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator<( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Less than operator called" << std::endl;
	#endif
	return (this->_value < rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator>=( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Greater than or equal operator called" << std::endl;
	#endif
	return (this->_value >= rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator<=( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Less tham or equal operator called" << std::endl;
	#endif
	return (this->_value <= rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator==( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Equal operator called" << std::endl;
	#endif
	return (this->_value == rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator!=( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Not equal operator called" << std::endl;
	#endif
	return (this->_value != rhs.getRawBits()) ? *this : (Fixed &)rhs;
}

Fixed &	Fixed::operator+( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Addition operator called" << std::endl;
	#endif
	this->_value += rhs.getRawBits();
	return *this;
}

Fixed &	Fixed::operator-( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Substraction operator called" << std::endl;
	#endif
	this->_value -= rhs.getRawBits();
	return *this;
}

Fixed &	Fixed::operator*( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Multiplication operator called" << std::endl;
	#endif
	setRawBits(TORAWBIT(this->toFloat() * rhs.toFloat()));
	return *this;
}

Fixed &	Fixed::operator/( Fixed const & rhs )
{
	#ifdef DEBUG
		std::cout << "Division operator called" << std::endl;
	#endif
	setRawBits(TORAWBIT(this->toFloat() / rhs.toFloat()));
	return *this;
}

Fixed &	Fixed::operator++( void )
{
	#ifdef DEBUG
		std::cout << "Incrementation operator called" << std::endl;
	#endif
	this->_value++;
	return *this;
}

Fixed	Fixed::operator++( int )
{
	#ifdef DEBUG
		std::cout << "Incrementation operator called" << std::endl;
	#endif
	Fixed	tmp(*this);
	this->operator++();
	return tmp;
}

Fixed &	Fixed::operator--( void )
{
	#ifdef DEBUG
		std::cout << "Decrementation operator called" << std::endl;
	#endif
	this->_value--;
	return *this;
}

Fixed	Fixed::operator--( int )
{
	#ifdef DEBUG
		std::cout << "Decrementation operator called" << std::endl;
	#endif
	Fixed	tmp(*this);
	this->operator--();
	return tmp;
}


std::ostream &		operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

float	Fixed::toFloat( void ) const
{
	return ((float) getRawBits() / (1 << _fractionalBits));
}

int	Fixed::toInt( void ) const
{
	return (getRawBits() >> _fractionalBits);
}

Fixed &	Fixed::min(Fixed & a, Fixed & b)
{
	return (a < b);
}

Fixed const &	Fixed::min(Fixed const & a, Fixed const & b)
{
	return ((Fixed &) a < b);
}

Fixed &	Fixed::max(Fixed & a, Fixed & b)
{
	return (a > b);
}

Fixed const &	Fixed::max(Fixed const & a, Fixed const & b)
{
	return ((Fixed &)a > b);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

void	Fixed::setRawBits( int const raw )
{
	#ifdef DEBUG
		std::cout << "setRawBits member function called" << std::endl;
	#endif
	this->_value = raw;
}

int	Fixed::getRawBits( void ) const
{
	#ifdef DEBUG
		std::cout << "getRawBits member function called" << std::endl;
	#endif
	return this->_value;
}

/* ************************************************************************** */
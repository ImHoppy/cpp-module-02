#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>
# include <cmath>

#define TORAWBIT(A) roundf(A * (1<<_fractionalBits))

class Fixed
{

	public:

		Fixed();
		Fixed( Fixed const & src );
		Fixed( int const & value );
		Fixed( float const & value );
		~Fixed();

		Fixed &			operator=( Fixed const & rhs );
		
		bool			operator>( Fixed const & rhs );
		bool			operator<( Fixed const & rhs );
		bool			operator>=( Fixed const & rhs );
		bool			operator<=( Fixed const & rhs );
		bool			operator==( Fixed const & rhs );
		bool			operator!=( Fixed const & rhs );

		Fixed &			operator+( Fixed const & rhs );
		Fixed &			operator-( Fixed const & rhs );
		Fixed &			operator*( Fixed const & rhs );
		Fixed &			operator/( Fixed const & rhs );

		Fixed &			operator++( void );		// prefix
		Fixed 			operator++( int );		// postfix
		Fixed &			operator--( void );		// prefix
		Fixed 			operator--( int );		// postfix

		static Fixed &	min(Fixed & a, Fixed & b);
		static Fixed const &	min(Fixed const & a, Fixed const & b);

		static Fixed &	max(Fixed & a, Fixed & b);
		static Fixed const &	max(Fixed const & a, Fixed const & b);

		int				getRawBits( void ) const;
		void			setRawBits( int const raw );

		float			toFloat( void ) const;
		int				toInt( void ) const;

	private:

		int					_value;
		static const int	_fractionalBits = 8;
};

std::ostream &			operator<<( std::ostream & o, Fixed const & i );

#endif // FIXED_HPP
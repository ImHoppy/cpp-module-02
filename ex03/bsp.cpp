#include "Point.hpp"

#include <iostream>


float	ft_abs(float value)
{
 	if (value < 0)
		return -value;
	return value;
}

float Area(Point a, Point b, Point c)
{
	
	return ft_abs((
			  ( a.getX().toFloat() * ( b.getY().toFloat() - c.getY().toFloat() ) )
			+ ( b.getX().toFloat() * ( c.getY().toFloat() - a.getY().toFloat() ) )
			+ ( c.getX().toFloat() * ( a.getY().toFloat() - b.getY().toFloat() ) )
			) / 2.0f);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float TriangleArea = Area(a, b, c);
	
	float A1 = Area(point, b, c);
	
	float A2 = Area(a, point, c);
	
	float A3 = Area(a, b, point);

	if ( A1 == 0 || A2 == 0 || A3 == 0)
			return (false);
	return ( TriangleArea == A1 + A2 + A3 );
}

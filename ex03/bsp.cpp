#include "Point.hpp"

//Barycentric Subdivision Point
static Fixed triangleArea(Point const &a, Point const &b, Point const &c) {
	Fixed x1 = a.getX();
	Fixed y1 = a.getY();
	Fixed x2 = b.getX();
	Fixed y2 = b.getY();
	Fixed x3 = c.getX();
	Fixed y3 = c.getY();

	Fixed area = (x1 * (y2 - y3)
				+ x2 * (y3 - y1)
				+ x3 * (y1 - y2)) / Fixed(2);
	//We need absolute value:
	if (area < Fixed(0))
		area = area * Fixed(-1);
	return (area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed areaABC = triangleArea(a, b, c);
	//If areaABC is 0, A, B, C are collinear, no valid triangle
	if (areaABC == Fixed(0))
		return (false);
	
	Fixed areaPBC = triangleArea(point, b, c);
	Fixed areaAPC = triangleArea(a, point, c);
	Fixed areaABP = triangleArea(a, b, point);

	// Check if sum of sub-areas equals total area
	// Also ensure none of the sub-areas is 0 to ensure strictly inside
	if (areaPBC == Fixed(0) || areaAPC == Fixed(0) || areaABP == Fixed(0))
		return (false);
	
	return (areaPBC + areaAPC + areaABP == areaABC);
}
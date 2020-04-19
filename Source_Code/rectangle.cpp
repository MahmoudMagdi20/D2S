#include "rectangle.h"

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle)
{
	os << rectangle.x1 << " " << rectangle.y1 << " ";
    os << rectangle.x2 << " " << rectangle.y2;
	return os;
}

std::istream& operator>>(std::istream& is, Rectangle& rectangle)
{
	is >> rectangle.x1 >> rectangle.y1 >> rectangle.x2 >> rectangle.y2;

	//Check if input in wrong format
	if (!is)
	{
		std::cout << "Invalid Format, Each line must be rectangle in format (x1 y1 x2 y2):";
		std::cout << " All integer numbers.";
		std::cout << std::endl;
		exit(254);
	}
	return is;
}

//Return true if this rectangle overlap with the other rectangle
bool Rectangle::overlap_with(const Rectangle& rectangle) const
{
	//Check if one rectangle left edge is to the right of right edge of the other rectangle.
	if (this->x1 >= rectangle.x2 || rectangle.x1 >= this->x2)
		return false;

	//Check if one rectangle bottom edge is above top edge of the other rectangle.
	if (this->y1 >= rectangle.y2 || rectangle.y1 >= this->y2)
		return false;

	return true;
}

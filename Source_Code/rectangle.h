#include <iostream>

struct RectanglesCompare;

class Rectangle {
	friend std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);
	friend std::istream& operator>>(std::istream& is, Rectangle& rectangle);
	friend RectanglesCompare;
public:
	Rectangle(long x1 = 0, long y1 = 0,
              long x2 = 0, long y2 = 0): x1(x1), y1(y1), x2(x2), y2(y2) {}
	bool overlap_with(const Rectangle& rectangle) const;
private:
	long x1;
    long y1;
    long x2;
    long y2;
};

std::ostream& operator<<(std::ostream& os, const Rectangle& rectangle);

std::istream& operator>>(std::istream& is, Rectangle& rectangle);

/*
Compare two rectangles return true if first rectangle has smaller x1 if both
rectangles has sanme x1, then return true if first rectangle has smaller y1
*/
struct RectanglesCompare {
	bool operator() (const Rectangle& rec1, const Rectangle& rec2)
	{
		if (rec1.x1 < rec2.x1)
	        return true;
	    else if (rec1.x1 > rec2.x1)
	        return false;
	    if (rec1.y1 < rec2.y1)
	        return true;
	    else if (rec1.y1 > rec2.y1)
	        return false;
	    return true;
	}
};

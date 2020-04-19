#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

#include "rectangle.h"

class DataSet {
public:
	DataSet(const char* s); //Construct dataset from input file
	void output_groups(); //Output groups of non overlaped rectangles into files
private:
	void divide_into_groups(); //Divide dataset into groups of non overlaped rectangles
	std::vector<Rectangle> rectangles;
	std::vector<std::vector<Rectangle>> groups;
};

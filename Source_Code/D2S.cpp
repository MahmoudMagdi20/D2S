#include "dataset.h"

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s DataSet_File\n", argv[0]);
		return 1;
	}

	DataSet data_set(argv[1]); //Construct dataset from input file
	data_set.output_groups(); //Output groups of non overlaped rectangles into files
	
	return 0;
}

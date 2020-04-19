#include "dataset.h"

//Construct dataset from input file
DataSet::DataSet(const char* file_name)
{
	//Open input dataset file
	FILE* input_file = fopen(file_name, "r");

	//File not found output error
	if (input_file == NULL)
	{
		perror("Error opening file");
		exit(255);
	}

	char str[50];
	while (fgets(str, 50, input_file) != NULL)
	{
	  std::istringstream rectangle_coordinates(str);

	  //Extract rectangle
	  Rectangle rectangle;
	  rectangle_coordinates >> rectangle;

	  //Add rectangle to dataset
	  rectangles.push_back(rectangle);
   	}

	fclose(input_file);
}

//Divide dataset into groups of non overlaped rectangles
void DataSet::divide_into_groups()
{
    //Sort rectangles in dataset according to smallest x1 then smallest y1
	sort(rectangles.begin(), rectangles.end(), RectanglesCompare());

    for (size_t i = 0; i < rectangles.size(); ++i)
	{
        //Loop over current groups
		auto group_it = groups.begin();
		for (; group_it != groups.end(); ++group_it)
		{
            //Check if current rectangle overlap with other rectangle in this group
			auto rectangle_it = group_it->begin();
			for (; rectangle_it != group_it->end(); ++rectangle_it)
			{
				if (rectangles[i].overlap_with(*rectangle_it))
					break;
			}

            //Add Current rectangle to this group as it does not overlap other rectangle in group
			if (rectangle_it == group_it->end())
			{
				group_it->push_back(rectangles[i]);
				break;
			}
		}
        //Create new group for Current rectangle as it dont fit in any of the current groups
		if (group_it == groups.end())
			groups.push_back(std::vector<Rectangle>(1, rectangles[i]));
	}
}

//Output groups of non overlaped rectangles into files
void DataSet::output_groups()
{
	divide_into_groups();

    int group_number = 0;
	//Create file for each group
    for (auto group_it = groups.begin(); group_it != groups.end(); ++group_it)
	{
		//Create name for output file
		std::ostringstream oss;
		oss << "group_" << ++group_number << ".txt";

		//Open output file
		std::ofstream ofile(oss.str());
		if (ofile.is_open())
		{
			//Output rectangles in this group to file
			for (auto rectangle_it = group_it->begin();
                 rectangle_it != group_it->end(); ++rectangle_it)
			{
				ofile << *rectangle_it << std::endl;
			}
			ofile.close();
		}
	}
}
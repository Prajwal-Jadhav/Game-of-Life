#include "Board.h"

#include <string>
#include <sstream>


/*
	constuctor which reads input from text file and creates 2-D matrix
*/
Board::Board(std::ifstream& file)
{
	std::string line;
	while (std::getline(file, line))
	{
		board.push_back(std::vector<int>());

		std::istringstream is(line);
		int i = 0;
		while (is >> i)
			board.back().push_back(i);
	}
}



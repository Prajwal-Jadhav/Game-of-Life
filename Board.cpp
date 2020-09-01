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
		board.push_back(std::vector<Cell>());

		std::istringstream is(line);
		int i = 0;
		while (is >> i)
			board.back().push_back(Cell(i));
	}
}

/*
	printing board aka 2-D matrix
*/
void Board::display_board(std::ostream& os)
{
	os << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX\n\n" << std::flush;
	os << "Generation: " << generation << "\n" << std::endl;

	for (auto &row : board)
	{
		for (auto &col : row)
			os << col.get_new() << " ";

		os << std::endl;
	}

	os << "\n\n" << std::flush;
}

/*
	function for counting state of neighbouring eight cells
	if conditions are for checking, so that we do not access 
	elements out of index of vector
	particularly important for elements on the edge of matrix
*/
std::size_t Board::count_neighbours(row i, col j)
{
	std::size_t count = 0;

	row row_last_index = board.size() - 1;
	col col_last_index = board[0].size() - 1;

	if (i != 0)
		count += board[i - 1][j].get_old();     // upper cell

	if (j != 0)
		count += board[i][j - 1].get_old();     // left cell

	if (i != row_last_index)
		count += board[i + 1][j].get_new();     // downward cell

	if (j != col_last_index)
		count += board[i][j + 1].get_new();     // rightward cell

	if (i != 0 && j != 0)
		count += board[i - 1][j - 1].get_old(); // upper left cell

	if (i != 0 && j != col_last_index)
		count += board[i - 1][j + 1].get_old(); // upper right cell

	if (i != row_last_index && j != col_last_index)
		count += board[i + 1][j + 1].get_new(); // downward right cell

	if (i != row_last_index && j != 0)
		count += board[i + 1][j - 1].get_new(); // downward left cell

	return count;
}


void Board::update_board()
{
	for (row i = 0; i != board.size(); ++i)
	{
		for (col j = 0; j != board[i].size(); ++j)
		{
			Cell& cell = board[i][j];

			std::size_t count = count_neighbours(i, j);

			if (count < 2 || count > 3)
				cell.kill();
			else if (cell.get_new() == 1 || count == 3)
				cell.regenerate();
			else
				cell.kill(); // if cell has 2 neighbours and old_state = 1, new_state = 0
		}
	}

	++generation;
}



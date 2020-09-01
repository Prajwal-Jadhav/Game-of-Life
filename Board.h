#pragma once

/*
	Board class which holds 2-d matrix for displaying cells 
	and updating on each generation
*/

#include "Cell.h"

#include <vector>
#include <fstream>
#include <iostream>

class Board
{
public:
	using row = std::vector <std::vector<Cell>>::size_type;
	using col = std::vector<Cell>::size_type;

	/* 
		constructors which read from text file and create 2-d matrix
	*/
	Board(std::ifstream& file);
	Board() = default;

	void display_board(std::ostream& os); // for displaying 2-d matrix in terminal
	void update_board();

private:
	std::size_t count_neighbours(row i, col j);
	unsigned generation = 1;
	std::vector<std::vector<Cell>> board;
};


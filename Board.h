#pragma once

/*
	Board class which holds 2-d matrix for displaying cells 
	and updating on each generation
*/

#include <vector>
#include <fstream>
#include <iostream>

class Board
{
public:
	/* 
		constructors which read from text file and create 2-d matrix
	*/
	Board(std::ifstream& file);
	Board() = default;

	void display_board(std::ostream& os); // for displaying 2-d matrix in terminal

private:
	unsigned generation = 1;
	std::vector<std::vector<int>> board;
};


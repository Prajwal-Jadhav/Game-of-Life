// game_of_life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"

int main()
{
    std::ifstream file("Input.txt");

    Board b(file);

    b.display_board(std::cout);
}


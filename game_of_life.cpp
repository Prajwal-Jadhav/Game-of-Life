// game_of_life.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Board.h"

int main()
{
    std::ifstream file("Input.txt"); // file from which to read the initial configuration of board

    Board b(file);

    std::cout << "How many generations do you want?: " << std::flush;

    int g_count = 0;
    std::cin >> g_count;

    for (int i = 0; i != g_count; ++i)
    {
        b.display_board(std::cout);
        b.update_board();
    }

}


/* This file contains definitions of members of Cell class */

#include "Cell.h"

// initially we want both states to be same
Cell::Cell(int state) : old_state(state), new_state(state) {};

int Cell::get_old()
{
	return old_state;
}

int Cell::get_new()
{
	return new_state;
}


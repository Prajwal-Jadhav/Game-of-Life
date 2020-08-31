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


/* 
   here 1 is assumed alive and 0 dead 
   new state is saved in old state for reference for cells coming after because
   newly born cell should't interfare with next cells
*/
void Cell::regenerate()
{
	old_state = new_state;
	new_state = 1;
}

void Cell::kill()
{
	old_state = new_state;
	new_state = 0;
}


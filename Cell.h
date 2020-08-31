#pragma once

class Cell
{
public:
	Cell() = default;
	Cell(int state);

	void regenerate();
	void kill();

	int get_old() { return old_state; };
	int get_new() { return new_state; };
private:
	int old_state = 0;
	int new_state = 0;
};



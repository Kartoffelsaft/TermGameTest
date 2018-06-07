#include <ncurses.h>
#include "./game.h"

void ginit()
{
	initscr();
	noecho();
}

void cinit()
{
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
}

bool beginshutdown()
{
	if(getinput() != 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
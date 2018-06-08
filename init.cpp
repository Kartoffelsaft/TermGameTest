#include <ncurses.h>
#include "./game.h"

void init()
{
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);
}
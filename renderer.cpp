#include <ncurses.h>
#include "./game.h"

void renderer()
{
	int height;
	int width;
	getmaxyx(stdscr, height, width);

	mvwaddch(stdscr, 4, 6, 97);

	wrefresh(stdscr);
}

void renderershutdown()
{
	endwin();
}
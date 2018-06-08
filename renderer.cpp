#include <ncurses.h>
#include "./game.h"

void renderer()
{
	int height;
	int width;
	getmaxyx(stdscr, height, width);

	mvwaddch(stdscr, 4, 6, 'a');

	wrefresh(stdscr);
}

void renderershutdown()
{
	endwin();
}
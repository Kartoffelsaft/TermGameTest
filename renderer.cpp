#include <ncurses.h>
#include "./game.h"

void renderer(int x, int y, char character)
{
	int height;
	int width;
	getmaxyx(stdscr, height, width);

	mvwaddch(stdscr, y, x, character);

	wrefresh(stdscr);
}

void renderershutdown()
{
	endwin();
}

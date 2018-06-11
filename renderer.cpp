#include <ncurses.h>
#include "./game.h"

int sizex()
{
	return getmaxx(stdscr);
}

int sizey()
{
	return getmaxy(stdscr);
}


void render()
{
	int sx{sizex()};
	int sy{sizey()};

	for(int x{0}; x<sx; x++)
	{
		for(int y{0}; y<sy; y++)
		{
			char c{fetchobj(x, y)};
			mvwaddch(stdscr, y, x, c);
		}
	}
	wrefresh(stdscr);
}

// void renderer()
// {
// 	mvwaddch(stdscr, y, x, character);
// }
//
// void rendererfinish()
// {
// 	wrefresh(stdscr);
// }

void renderershutdown()
{
	endwin();
}

#include <ncurses.h>
#include "./game.h"

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

void addtext(int startx, int starty, string text)
{
	for(int stringlocation; stringlocation < text.length(); stringlocation++)
	{
		addobject(stringlocation+startx, starty, text.at(stringlocation));
	}
}

void renderershutdown()
{
	endwin();
}

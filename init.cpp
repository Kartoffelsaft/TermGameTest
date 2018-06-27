#include <ncurses.h>
#include "./game.h"
using namespace colors;

void init()
{
	initscr();
	noecho();
	cbreak();
	nodelay(stdscr, true);
	keypad(stdscr, true);

	start_color();
		init_color(BLUE, 0, 0, 1000);
		init_color(LIGHT_BLUE, 250, 250, 1000);
		init_color(GREEN, 0, 500, 0);
		init_color(LIGHT_GREEN, 0, 1000, 0);
		init_color(WHITE, 1000, 1000, 1000);
		init_color(GRAY, 500, 500, 500);
		init_color(LIGHT_GRAY, 750, 750, 750);
		init_color(BLACK, 0, 0, 0);

		init_pair(WATER_PAIR, BLUE, LIGHT_BLUE);
		init_pair(LAND_PAIR, GREEN, LIGHT_GREEN);
		init_pair(MOUNTAIN_PAIR, LIGHT_GRAY, GRAY);
		init_pair(FOREST_PAIR, LIGHT_GREEN, GREEN);
		init_pair(KELP_PAIR, GREEN, BLUE);
		init_pair(MONTANE_PAIR, GREEN, GRAY);
		init_pair(UNKNOWN_PAIR, WHITE, BLACK);
}

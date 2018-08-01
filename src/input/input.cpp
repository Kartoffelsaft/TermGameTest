#include <ncurses.h>
#include "./game.h"
#include "./world.h"

int getinput()
{
	int inp{getch()};
	if(inp != ERR)
	{
		return inp;
	}
	else
	{
		return 0;
	}
}

int inputhandler()
{
	int inp{getinput()};

	if(inp == 27)
	{
		shutdown();
	}
	else if(inp != 0)
	{
		newevent();
	}

	using namespace world;
	switch(inp)
	{
		case KEY_UP:
			yoffset -= 1;
			break;
		case KEY_DOWN:
			yoffset += 1;
			break;
		case KEY_LEFT:
			xoffset -= 1;
			break;
		case KEY_RIGHT:
			xoffset += 1;
			break;
	}
	int xleeway{settings::worldgen::worldx - sizex() + 2};
	int yleeway{settings::worldgen::worldy - sizey() + 4};

	if(xleeway < 0)	//this makes shure that the variation in the x and y offsets are not < zero
	{xleeway = 0;}
	if(yleeway < 0)
	{yleeway = 0;}

	if(xoffset < 0)	//this is keeping the x and y offsets within the bounds of the screen to prevent segfaulting
	{xoffset = 0;}
	if(xoffset > xleeway)
	{xoffset -= 1;}
	if(yoffset > yleeway)
	{yoffset -= 1;}
	if(yoffset < 0)
	{yoffset = 0;}

	return inp;
}

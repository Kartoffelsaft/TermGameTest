#include <ncurses.h>
#include "./game.h"

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

	return inp;
}

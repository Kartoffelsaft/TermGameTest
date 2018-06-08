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

void inputhandler(bool waitonblank)
{
	int inp{getinput()};

	if(inp == 0 && waitonblank)
	{
		dowaittick();
	}
	else
	{
		shutdown();

		switch(inp)
		{
			
		}
	}
}
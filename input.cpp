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
		dowaittick();
		return 0;
	}
}

void inputhandler()
{
	int inp{getinput()};

	switch(inp)
	{
		
	}
}
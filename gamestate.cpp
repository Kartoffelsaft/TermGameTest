#include <bitset>
#include "game.h"

static std::bitset<8> gamestate{0b00000001};		/* starting from rightmost bit
																								0: is game running
																								1: menu state (00 = world, 01 = resources)
																								2: menu state (10 = unsgnd, 11 = unsgnd)
																								3: If an event has occurred this frame
																								4: unassigned
																								5: unassigned
																								6: unassigned
																								7: unassigned
																								*/

bool running()
{
	return gamestate.test(0);
}

void shutdown()
{
	gamestate.reset(0);
}

bool inworld()
{
	if(gamestate.test(1) == false & gamestate.test(2) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void gotoworld()
{
	gamestate.reset(1);
	gamestate.reset(2);
}

bool inresources()
{
	if(gamestate.test(1) == true & gamestate.test(2) == false)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void gotoresources()
{
	gamestate.set(1);
	gamestate.reset(2);
}

void newframe()
{
	gamestate.reset(3);
}

bool isevent()
{
	gamestate.test(3);
}

void newevent()
{
	gamestate.set(3);
}

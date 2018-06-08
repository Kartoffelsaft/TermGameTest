#include <bitset>
#include "game.h"

static std::bitset<8> gamestate{0b00000001};		/* starting from rightmost bit
													0: is game running
													1: unassigned
													2: unassigned
													3: unassigned
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
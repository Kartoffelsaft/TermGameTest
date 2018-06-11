#include "./game.h"

static int playerx{0};
static int playery{0};

void doplayer()
{
    int inp{inputhandler(true)};

    if(inp != 0)
    {
        // renderer(playerx, playery, 32); //clears current player position to prevent duplicates

        if(inp == 'w')
        {
            playery -= 1;
        }
        if(inp == 's')
        {
            playery += 1;
        }
        if(inp == 'a')
        {
            playerx -= 1;
        }
        if(inp == 'd')
        {
            playerx += 1;
        }
    }
    addobject(playerx, playery, 'X');
}

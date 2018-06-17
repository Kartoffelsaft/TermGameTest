#include "./game.h"

static int playerx{1};
static int playery{1};

void doplayer()
{
  addobject(playerx, playery, 'X');

  docitydata(playerx, playery);
  dodepositdata(playerx, playery);
}

void doplayerinput()
{
  int inp{inputhandler()};

  if(inp != 0)
  {
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
    if(inp == 'b')
    {
      createcity(playerx, playery);
    }
    if(inp == 'l')
    {
      nextturn();
    }
    if(inp == 'r')
    {
      gotoresources();
    }
    if(inp == 'g')
    {
      gotoworld();
    }
  }
}

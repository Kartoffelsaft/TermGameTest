#include "./game.h"

static int playerx{0};
static int playery{0};

void doplayer()
{
  addobject(playerx, playery, 'X');

  citydata(playerx, playery);
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

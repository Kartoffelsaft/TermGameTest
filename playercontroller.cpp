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
    playerx = playerx % sizex(); //so that player location is actually on
    playery = playery % sizey(); //screen and not just appearing that way

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
      buildcity(playerx, playery);
    }
    if(inp == 'm')
    {
      buildmine(playerx, playery);
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

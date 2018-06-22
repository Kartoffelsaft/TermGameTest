#include "./game.h"

static int playerx{1};
static int playery{1};

void doplayer()
{
  addobject(playerx, playery, 'X');

  docitydata(playerx, playery);
  // dodepositdata(playerx, playery);
  dofloordata(playerx, playery);
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

    if(playerx > 1 || playery > 1)
    {
      playerx = playerx % settings::worldgen::worldx; //so that player location is actually on
      playery = playery % settings::worldgen::worldy; //screen and not just appearing that way
    }
    if(playerx < 1)
    {
      playerx = 1;
    }
    if(playery < 1)
    {
      playery = 1;
    }
  }
}

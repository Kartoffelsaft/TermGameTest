#include "./game.h"

static int playerx{1};
static int playery{1};

void doplayer()
{
  if(cursorpresent())
  {
    addobject(playerx, playery, 'X');

    dofloordata(playerx, playery);
    docitydata(playerx, playery);
  }
}

void doplayerinput()
{
  int inp{inputhandler()};

  if(inp != 0)
  {
    if(cursorpresent())
    {
      switch(inp)
      {
        case 'w':
          playery -= 1;
          break;
        case 's':
          playery += 1;
          break;
        case 'a':
          playerx -= 1;
          break;
        case 'd':
          playerx += 1;
          break;
        case 'b':
          buildcity(playerx, playery);
          break;
        case 'm':
          buildmine(playerx, playery);
          break;
        case 'p':
          buildsteelplant(playerx, playery);
          break;
      }
    }
    switch(inp)
    {
      case ' ':
        togglecursor();
        break;
      case 'l':
        nextturn();
        break;
      case 'r':
        gotoresources();
        break;
      case 'g':
        gotoworld();
        break;
    }

    if(playerx > 1 || playery > 1)
    {
      playerx = playerx % sizex(); //so that player location is actually on
      playery = playery % sizey(); //screen and not just appearing that way
    }
    if(playerx < 1)
    {
      playerx = settings::worldgen::worldx - 1;
    }
    if(playery < 1)
    {
      playery = settings::worldgen::worldy - 1;
    }
  }
}

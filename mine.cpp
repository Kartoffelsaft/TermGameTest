#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

void buildmine(int x, int y)
{
  mines.push_back({-1, 0, 0});

  int depositid{getdepositid(x, y)};
  if(depositid != -1)
  {
    mines.at(mines.size() - 1).initmine(depositid);
  }
  else
  {
    addtext(1, sizey() - 1, string("you can't place a mine there!"));
    mines.pop_back();
  }
}

void extractresources()
{
  for(int i{0}; i < mines.size(); i++)
  {
    mines.at(i).mine();
  }
}

void domines()
{
  for(int i{0}; i < mines.size(); i++)
  {
    addobject(getdepositx(mines.at(i).exploiteddeposit), getdeposity(mines.at(i).exploiteddeposit), 'Q');
  }
}

#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

void buildmine(int x, int y)
{
  mines.push_back({-1, 0, 0});

  mines.at(mines.size() - 1).initmine(x, y);
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

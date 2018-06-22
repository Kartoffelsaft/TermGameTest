#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

void buildmine(int x, int y)
{
  mines.push_back({-1, 0, 0});

  int deposit{world2dto1d(x, y)};

  mines.at(mines.size() - 1).initmine(deposit);
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
    int mineloc{mines.at(i).exploiteddeposit};

    addobject(world1dtox(mineloc), world1dtoy(mineloc), 'Q');
  }
}

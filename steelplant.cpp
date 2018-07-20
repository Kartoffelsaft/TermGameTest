#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

void buildsteelplant(int x, int y)
{
  if(buy(20))
  {
    steelplants.push_back({});
    steelplants.back().build(x, y);
    steelplants.back().rate = 5;
  }
}

void dosteelplants()
{
  for(int i{0}; i < steelplants.size(); i++)
  {
    steelplants.at(i).render('F');
  }
}

int steelproduction()
{
  int volume{0};

  for(int i{0}; i < steelplants.size(); i++)
  {
    volume += steelplants.at(i).rate;
  }

  return volume;
}

#include "./game.h"
#include <vector>

struct city
{
  int x;
  int y;

  int income; //to be used in future
};

static std::vector<city> cities;

int getcityid(int x, int y)
{
  for(int checkc; checkc < cities.size(); checkc++)
  {
    if((cities.at(checkc).x == x) & (cities.at(checkc).y == y))
    {
      return checkc;
    }
  }
  return consts::maxnumb;
}

void createcity(int x, int y)
{
  if(getcityid(x, y) == consts::maxnumb)
  {
    cities.push_back({x, y, 1});
  }
}

void docities()
{
  for(int checkc; checkc < cities.size(); checkc++)
  {
    addobject(cities.at(checkc).x, cities.at(checkc).y, '#');
  }
}

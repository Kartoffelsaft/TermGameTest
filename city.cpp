#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

int getcityid(int xqry, int yqry)
{
  for(int checkc; checkc < cities.size(); checkc++)
  {
    if((cities.at(checkc).x == xqry) & (cities.at(checkc).y == yqry))
    {
      return checkc;
    }
  }
  return -1;
}

void buildcity(int x, int y)
{
  if(getcityid(x, y) == -1)
  {
    int cityvalue{0};

    using namespace settings;
    for(int rx{0}; rx < 2 * cityrange + 1; rx++)
    {
      for(int ry{0}; ry < 2 * cityrange + 1; ry++)
      {
        cityvalue += getlandvalue(x - rx + cityrange, y - ry + cityrange);
      }
    }

    cities.push_back({x, y, cityvalue});
  }
}

void docities()
{
  for(int checkc; checkc < cities.size(); checkc++)
  {
    addobject(cities.at(checkc).x, cities.at(checkc).y, '#');
  }
}

int cityincome()
{
  int income{0};

  for(int checkc{0}; checkc < cities.size(); checkc++)
  {
    income += cities.at(checkc).income;
  }

  return income;
}

void docitydata(int x, int y)
{
  int cityid{getcityid(x, y)};

  if(cityid != -1)
  {
    cities.at(cityid).displaycitydata();
  }
}

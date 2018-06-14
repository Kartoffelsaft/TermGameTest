#include "./game.h"
#include <vector>

class City
{
public:
  int x;
  int y;

  int income;

  void displaycitydata()
  {
    addtext(1, sizey() - 2, string("loc: ") + std::to_string(x) + string(", ") + std::to_string(y) + string(" income: ") + std::to_string(income));
  }
};

static std::vector<City> cities;

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

void createcity(int x, int y)
{
  if(getcityid(x, y) == -1)
  {
    cities.push_back({x, y, 2});
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

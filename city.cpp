#include "./game.h"
#include "./structures.h"
#include <vector>
using namespace structures;

int getcityid(int xqry, int yqry)
{
  int queryloc{world2dto1d(xqry, yqry)};
  int id{-1};

  for(int checkc{0}; checkc < cities.size(); checkc++)
  {
    if(cities.at(checkc).terrainloc == queryloc)
    {
      id = checkc;
    }
  }
  return id;
}

void updatecities()
{
  for(int i{0}; i < cities.size(); i++)
  {
    cities.at(i).income = 0;
    cities.at(i).population = 0;

    using namespace settings;
    for(int rx{0}; rx < 2 * cityrange + 1; rx++)
    {
      for(int ry{0}; ry < 2 * cityrange + 1; ry++)
      {
        int workingx{cities.at(i).x() - rx + cityrange};
        int workingy{cities.at(i).y() - ry + cityrange};

        cities.at(i).income += getlandvalue(workingx, workingy, 0);
        cities.at(i).population += getlandvalue(workingx, workingy, 1);
      }
    }
  }
}

void buildcity(int x, int y)
{
  if(getcityid(x, y) == -1)
  {
    cities.push_back({});
    cities.back().build(x, y);
    updatecities();
  }
}

void docities()
{
  for(int checkc{0}; checkc < cities.size(); checkc++)
  {
    addobject(cities.at(checkc).x(), cities.at(checkc).y(), '#');
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

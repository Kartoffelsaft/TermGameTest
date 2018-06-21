#include "./game.h"
#include "./structures.h"
#include <bitset>
using namespace structures;
using settings::worldx;
using settings::worldy;

// void dofloor()
// {
//   // for (int x=0; x<sizex(); x++)
//   //     for (int y=0; y<sizey(); y++)
//   //         renderer(x,y,'-');
//
//   int size[2] = {sizex(), sizey()};
//
//   int xloop{0};
//   int yloop{0};
//
//   while(size[0]>xloop)
//   {
//     while(size[1]>yloop)
//     {
//         addobject(xloop, yloop, '=');
//
//         yloop += 1;
//     }
//     xloop += 1;
//     yloop = 0;
//   }
// }

void worldgen()
{
  int landmass[2]{randuni(0, worldx), randuni(0, worldy)};

  terrains.at(landmass[0] * worldy + landmass[1]).setland();
  for(int i{0}; i < settings::landmasssize; i++)
  {
    for(int x{0}; x < worldx; x++)
    {
      for(int y{0}; y < worldy; y++)
      {
        if(terrains.at(x * worldy + y).getland())
        {
          int up{y-1};
          int down{y+1};
          int left{x-1};
          int right{x+1};

          if(up >= 0 &&
             randuni(0, 100) < settings::landrizechance)
          {
            terrains.at(x * worldy + up).setland();
          }
          if(down < worldy &&
             randuni(0, 100) < settings::landrizechance)
          {
            terrains.at(x * worldy + down).setland();
          }
          if(left >= 0 &&
             randuni(0, 100) < settings::landrizechance)
          {
            terrains.at(left * worldy + y).setland();
          }
          if(right < worldx &&
             randuni(0, 100) < settings::landrizechance)
          {
            terrains.at(right * worldy + y).setland();
          }
        }
      }
    }
  }
}

void dofloor()
{
  for(int i{0}; i < worldx; i++)
  {
    for(int j{0}; j < worldy; j++)
    {
      int terrainloc{i * worldy + j};
      int x{i+1};
      int y{j+1};


      switch (terrains.at(terrainloc).biome)
      {
        case 0b0000'0000://ocean
          addobject(x, y, '~');
          break;
        case 0b0000'0001://land
          addobject(x, y, '=');
          break;
        default:
          addobject(x, y, '?');
          break;
      }
    }
  }
}

#include "./game.h"
#include "./structures.h"
#include <bitset>
using namespace structures;
using namespace settings::worldgen;

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

Terrain& getterrain(int x, int y)
{
  return terrains.at(world2dto1d(x, y));
}

int world2dto1d(int x, int y)
{
  return ((x * worldy + 1) + (y + 1));
}
int world1dtox(int location)
{return (location - 1)/worldy;}
int world1dtoy(int location)
{return (location - 1)%worldy - 1;}

void makeblob(char type, int landmassmax = maxcontinents, int size = landmasssize, int rizechance = landrizechance)
{
  for(int i{0}; i < landmassmax; i++)
  {
    int landmass[2]{randuni(0, worldx), randuni(0, worldy)};

    getterrain(landmass[0], landmass[1]).biome |= type;
  }

  for(int i{0}; i < size; i++)
  {
    for(int x{0}; x < worldx; x++)
    {
      for(int y{0}; y < worldy; y++)
      {
        if(getterrain(x, y).biome & type)
        {
          int up{y-1};
          int down{y+1};
          int left{x-1};
          int right{x+1};

          if(up >= 0 &&
             randuni(0, 100) < rizechance)
          {
            getterrain(x, up).biome |= type;
          }
          if(down < worldy &&
             randuni(0, 100) < rizechance)
          {
            getterrain(x, up).biome |= type;
          }
          if(left >= 0 &&
             randuni(0, 100) < rizechance)
          {
            getterrain(left, y).biome |= type;
          }
          if(right < worldx &&
             randuni(0, 100) < rizechance)
          {
            getterrain(right, y).biome |= type;
          }
        }
      }
    }
  }
}

void makecap(char type, int percentcoverage = polepercent, int variation = polevariation)
{
  for(int i{0}; i < worldx; i++)
  {
    int polelatitude{randbell(worldy * percentcoverage, percentcoverage * variation)/100};
    for(int j{0}; j < polelatitude; j++)
    {
      getterrain(i, j).biome |= type;
    }

    polelatitude = randbell(worldy * percentcoverage, percentcoverage * variation)/100;
    for(int j{0}; j < polelatitude; j++)
    {
      getterrain(i, worldy - j).biome |= type;
    }
  }
}

void worldgen()
{
  makeblob(0b0000'0001);//add land
  makeblob(0b0000'0010);//set altitudes
  makeblob(0b0000'0100);//add vegetation
  makecap(0b0000'1000);//add ice
}

void dofloor()
{
  for(int i{0}; i < worldx; i++)
  {
    for(int j{0}; j < worldy; j++)
    {
      switch (getterrain(i, j).biome)
      {
        case 0b0000'0000://ocean
          addobject(i, j, '~', colors::WATER_PAIR);
          break;
        case 0b0000'0001://land
          addobject(i, j, '=', colors::LAND_PAIR);
          break;
        case 0b0000'0010://trench
          addobject(i, j, 'v', colors::WATER_PAIR);
          break;
        case 0b0000'0011://mountain
          addobject(i, j, 'A', colors::MOUNTAIN_PAIR);
          break;
        case 0b0000'0100://swamp
          addobject(i, j, '@', colors::FOREST_PAIR);
          break;
        case 0b0000'0101://forest
          addobject(i, j, 'T', colors::FOREST_PAIR);
          break;
        case 0b0000'0110://kelp forest
          addobject(i, j, ';', colors::KELP_PAIR);
          break;
        case 0b0000'0111://montane
          addobject(i, j, '%', colors::MONTANE_PAIR);
          break;
        case 0b0000'1000://glacier
          addobject(i, j, '*', colors::ICE_PAIR);
          break;
        case 0b0000'1001://snow
          addobject(i, j, ' ', colors::ICE_PAIR);
          break;
        case 0b0000'1010://arctic water
          addobject(i, j, '*', colors::WATER_PAIR);
          break;
        case 0b0000'1011://snowy mountain
          addobject(i, j, 'A', colors::ICE_PAIR);
          break;
        case 0b0000'1100://frozen junk
          addobject(i, j, '$', colors::ICE_PAIR);
          break;
        case 0b0000'1101://tundra
          addobject(i, j, 'T', colors::TUNDRA_PAIR);
          break;
        case 0b0000'1110://arctic corals
          addobject(i, j, ';', colors::ICE_PAIR);
          break;
        case 0b0000'1111://frozen montane
          addobject(i, j, '%', colors::TUNDRA_PAIR);
          break;
        default:
          addobject(i, j, '?');
          break;
      }
    }
  }
}

void dofloordata(int x, int y)
{
  getterrain(x, y).displayterraindata();
}

void clearresources(int location, int amount)
{
  terrains.at(location).deposits -= amount;
}

char getdepositresource(int location)
{
  return terrains.at(location).biome;
}

int getlandvalue(int x, int y)
{
  char land{getterrain(x, y).biome};
  int value{0};

  if(land & 0b0000'0001)//is land
  {
    value += 2;
  }
  if(land & 0b0000'0010)//is extreme elevation
  {
    value -= 2;
  }
  if(land & 0b0000'0100)//is forested
  {
    value += 1;
  }
  if(land & 0b0000'1000)//is cold
  {
    value -= 3;
  }

  return value;
}

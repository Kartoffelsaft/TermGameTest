#pragma once
#include "./game.h"
#include <vector>

class Terrain
{
public:
  char biome{0b0000'0000};  //b0: land; 1 = land, 0 = water
                            //b1: altitude; 1 = extreme, 0 = normal
                            //b2: vegetation; 1 = plants, 0 = barren
                            //b3: temperature; 1 = cold, 0 = warm
                            //bx: undefined
  int deposits{randbell(750, 250)};

  bool getland()
  {
    return biome & 0b0000'0001;
  }

  void displayterraindata()
  {
    string type;
    switch (biome) //if anyone knows of a better way to do this, please tell me, because maintaining this whole biome thing is ... inconvinient to put it nicely
    {
      case 0b0000'0000:
        type = "ocean";
        break;
      case 0b0000'0001:
        type = "land";
        break;
      case 0b0000'0010:
        type = "trench";
        break;
      case 0b0000'0011:
        type = "mountain";
        break;
      case 0b0000'0100:
        type = "swamp";
        break;
      case 0b0000'0101:
        type = "forest";
        break;
      case 0b0000'0110:
        type = "kelp forest";
        break;
      case 0b0000'0111:
        type = "montane";
        break;
      case 0b0000'1000:
        type = "glacier";
        break;
      case 0b0000'1001:
        type = "snow";
        break;
      case 0b0000'1010:
        type = "arctic water";
        break;
      case 0b0000'1011:
        type = "snowy mountain";
        break;
      case 0b0000'1100:
        type = "frozen junk";
        break;
      case 0b0000'1101:
        type = "tundra";
        break;
      case 0b0000'1110:
        type = "arctic corals";
        break;
      case 0b0000'1111:
        type = "frozen montane";
        break;
    }

    addtext(1, sizey()-2, string("biome: ") + type + string("  resources: ") + std::to_string(deposits));
  }
};

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

class Mine
{
public:
  int exploiteddeposit;
  char resourcetype;

  int minerate;

  void initmine(int deposit)
  {
    exploiteddeposit = deposit;

    resourcetype = getdepositresource(exploiteddeposit);
    minerate = 2;
  }

  void mine()
  {
    clearresources(exploiteddeposit, minerate);

    addminerals(resourcetype, minerate);
  }
};

namespace structures
{
  static std::vector<Terrain> terrains((settings::worldgen::worldx + 1) * (settings::worldgen::worldy + 1));
  static std::vector<City> cities;
  static std::vector<Mine> mines;
}

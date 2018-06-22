#pragma once
#include "./game.h"
#include <vector>

class Terrain
{
public:
  char biome{0b0000'0000};  //b0: land; 1 = land, 0 = water
                            //b1: altitude; 1 = extreme, 0 = normal
                            //bx: undefined
  int deposits{randbell(750, 250)};

  void setland()
  {
    biome = biome | 0b0000'0001;
  }
  bool getland()
  {
    return biome & 0b0000'0001;
  }

  void displayterraindata()
  {
    string type;
    switch (biome)
    {
      case 0b0000'0000:
        type = "ocean";
        break;
      case 0b0000'0001:
        type = "land";
        break;
    }

    addtext(1, sizey()-2, string("biome: ") + type + string(" resources: ") + std::to_string(deposits));
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

// class Deposit
// {
// public:
//   int x;
//   int y;
//
//   char resourcetype; //b0 = iron, b1 = coal, rest undefined
//   int amount;
//
//   void displaydepositdata()
//   {
//     addtext(1, sizey() - 2, string("loc: ") + std::to_string(x) + string(", ") + std::to_string(y) + string(" volume: ") + std::to_string(amount));
//   }
// };

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
  // static std::vector<Deposit> deposits;
  static std::vector<Mine> mines;
}

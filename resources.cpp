#include "./game.h"

namespace resources
{
  static int money{0};
  static int iron{0};
  static int coal{0};
  static int wood{0};
}

void addminerals(char type, int amount)  //type should be just like the type found in Deposit class
{
  if(type & 0b0000'0001)
  {
    resources::iron += amount;
  }
  if(type & 0b0000'0010)
  {
    resources::coal += amount;
  }
  if(type & 0b0000'0100)
  {
    resources::wood += amount;
  }
}

int getincome()
{
  int income{0};

  income += cityincome();

  return income;
}

void addresources()
{
  resources::money += getincome();
}

void doresourcemenus()
{
  addtext(1, 1, (string("Money: ") + std::to_string(resources::money)));

  addtext(1, 2, (string("Iron: ") + std::to_string(resources::iron)));

  addtext(1, 3, (string("Coal: ") + std::to_string(resources::coal)));

  addtext(1, 4, (string("Wood: ") + std::to_string(resources::wood)));
}

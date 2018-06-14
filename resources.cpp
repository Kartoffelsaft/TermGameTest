#include "./game.h"

namespace resources
{
  static int money{0};
}

int getincome()
{
  int income{0};

  income += cityincome();

  return income;
}

void addincome()
{
  resources::money += getincome();
}

void doresourcemenus()
{
  addtext(1, 1, (string("Money: ") + std::to_string(resources::money)));
}

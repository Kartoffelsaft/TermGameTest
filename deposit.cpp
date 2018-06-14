#include "./game.h"
#include <vector>

class Deposit
{
public:
  int x;
  int y;

  char resourcetype; //b0 = iron, b1 = coal, rest undefined
  int amount;
};

static std::vector<Deposit> deposits;

static std::uniform_int_distribution<> coordinates{0, 15};
void irongenerator()
{
  int depositcount{randbell(8, 2)};

  for(int i{0}; i < depositcount; i++)
  {
    deposits.push_back({randuni(0, 15), randuni(0, 15), 0b0000'0001, randbell(750, 250)});
  }
}

void dodeposits()
{
  for(int i{0}; i < deposits.size(); i++)
  {
    addobject(deposits.at(i).x, deposits.at(i).y, '@');
  }
}

void generatedeposits()
{
  irongenerator();
}

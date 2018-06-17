#include "./game.h"
#include <vector>

class Deposit
{
public:
  int x;
  int y;

  char resourcetype; //b0 = iron, b1 = coal, rest undefined
  int amount;

  void displaydepositdata()
  {
    addtext(1, sizey() - 2, string("loc: ") + std::to_string(x) + string(", ") + std::to_string(y) + string(" volume: ") + std::to_string(amount));
  }
};

static std::vector<Deposit> deposits;

int getdepositid(int xqry, int yqry)
{
  for(int checkd; checkd < deposits.size(); checkd++)
  {
    if(deposits.at(checkd).x == xqry & deposits.at(checkd).y == yqry)
    {
      return checkd;
    }
  }
  return -1;
}

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

void dodepositdata(int x, int y)
{
  int depositid{getdepositid(x, y)};

  if(depositid != -1)
  {
    deposits.at(depositid).displaydepositdata();
  }
}

void generatedeposits()
{
  irongenerator();
}

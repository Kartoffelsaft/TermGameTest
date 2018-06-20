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

class Mine
{
public:
  int exploiteddeposit;
  char resourcetype;

  int minerate;

  void initmine(int depositid)
  {
    exploiteddeposit = depositid;

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
  static std::vector<City> cities;
  static std::vector<Deposit> deposits;
  static std::vector<Mine> mines;
}

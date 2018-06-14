#include "./game.h"
#include <vector>
#include <random>
#include <cmath>

struct deposit
{
  int x;
  int y;

  char resourcetype; //b0 = iron, b1 = coal, rest undefined
  int amount;
};

static std::vector<deposit> deposits;

static std::uniform_int_distribution<> coordinates{0, 15};
void irongenerator()
{
  std::random_device rd;
  std::mt19937 gen(rd());

  std::normal_distribution<> rawdepositcount{8, 2};
  std::normal_distribution<> rawresourceamount{750, 250};

  int depositcount{int(std::round(rawdepositcount(gen)))};

  for(int i{0}; i < depositcount; i++)
  {
    deposits.push_back({coordinates(gen), coordinates(gen), 0b00000001, int(std::round(rawresourceamount(gen)))});
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

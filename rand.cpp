#include "./game.h"
#include <random>
#include <cmath>

int randbell(int median, int stndDevi)
{
  std::random_device rd;
  std::mt19937 gen(rd());

  std::normal_distribution<> curve{median, stndDevi};

  return int(std::round(curve(gen)));
}

int randuni(int min, int max)
{
  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<> space{min, max};

  return space(gen);
}

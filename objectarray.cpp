#include "./game.h"
#include <vector>
using namespace std;

static std::vector<char> objects;

static int prevx{0};
static int prevy{0};

void objectspace()
{
  int currentx{sizex()};
  int currenty{sizey()};

  if (currentx-prevx != 0 & currenty-prevy != 0)
  {
    objects.resize((currenty + 3) * (currentx + 3)); //the +3's prevent segfaults when expanding the terminal

    prevx = currentx;
    prevy = currenty;
  }
}

void addobject(int x, int y, char character)
{
  objects[x * prevy + y] = character;
}

char fetchobj(int x, int y)
{
  return objects[x * prevy + y];
}

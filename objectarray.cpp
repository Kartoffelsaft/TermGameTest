#include "./game.h"
#include <vector>
using namespace std;

static std::vector<char> objects;

static int prevx{sizex()};
static int prevy{sizey()};

void objectspace()
{
  int currentx{sizex()};
  int currenty{sizey()};

  if (currentx-prevx != 0 & currenty-prevy != 0)
  {
    objects.resize(currenty * currentx);

    prevx = currentx;
    prevy = currenty;
  }
}

void addobject(int x, int y, char character)
{
  objects[x * prevx + y] = character;
}

char fetchobj(int x, int y)
{
  return objects[x * prevx + y];
}

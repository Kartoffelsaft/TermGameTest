#include "./game.h"
#include <vector>
#include <ncurses.h>

static std::vector<char> objects;

static int prevx{0};
static int prevy{0};

static int width{0};
static int height{0};

int sizex()
{
	return width;
}

int sizey()
{
	return height;
}

void objectspace()
{
  width = getmaxx(stdscr);
  height = getmaxy(stdscr);

  int currentx{sizex()};
  int currenty{sizey()};

  if (currentx-prevx != 0 & currenty-prevy != 0)
  {
    objects.resize((currenty + 3) * (currentx + 3));

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

#include "./game.h"
#include <vector>
#include <ncurses.h>

class Object
{
public:
	char character;
	int colorpair{colors::UNKNOWN_PAIR};
};

static std::vector<Object> objects;

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

void addobject(int x, int y, char character, int color)
{
  objects[x * prevy + y].character = character;

	if(color != -1)
	{
		objects[x * prevy + y].colorpair = color;
	}
	else
	{
		objects[x * prevy + y].colorpair = colors::UNKNOWN_PAIR;
	}
}

char fetchobj(int x, int y)
{
  return objects[x * prevy + y].character;
}

int fetchcolor(int x, int y)
{
	return objects[x * prevy + y].colorpair;
}

void clearobjects()
{
	for(int i{0}; i < objects.size(); i++)
	{
		objects.at(i).character = ' ';
	}
}

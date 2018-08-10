#include "./game.h"

void dogui()
{
  for(int i{1}; i < sizey() - 1; i++)
  {
    addobject(0, i, '|');
    addobject(sizex() - 1, i, '|');
  }
  for(int j{1}; j < sizex() - 1; j++)
  {
    addobject(j, sizey() - 2, ' ');

    addobject(j, 0, '-');
    addobject(j, sizey() - 3, '-');
    addobject(j, sizey() - 1, '-');
  }

  addobject(0, 0, 'O');
  addobject(0, sizey() - 1, 'O');
  addobject(sizex() - 1, 0, 'O');
  addobject(sizex() - 1, sizey() - 1, 'O');
  addobject(0, sizey() - 3, 'O');
  addobject(sizex(), sizey() - 3, 'O');
}

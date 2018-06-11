#include "./game.h"

void dofloor()
{
  // for (int x=0; x<sizex(); x++)
  //     for (int y=0; y<sizey(); y++)
  //         renderer(x,y,'-');

  int size[2] = {sizex(), sizey()};

  int xloop{0};
  int yloop{0};

  while(size[0]>xloop)
  {
    while(size[1]>yloop)
    {
        addobject(xloop, yloop, '-');

        yloop += 1;
    }
    xloop += 1;
    yloop = 0;
  }
}

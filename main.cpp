#include <iostream>
#include "./game.h"

int main()
{
	init();

	while(running())
	{
		doplayer();
	}

	renderershutdown();
	return 0;
}

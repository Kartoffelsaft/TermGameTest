#include "./game.h"

int main()
{
	init();

	while(running())
	{
		objectspace();

		dofloor();
		doplayer();

		render();
	}

	renderershutdown();
	return 0;
}

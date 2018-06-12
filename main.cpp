#include "./game.h"

int main()
{
	init();

	while(running())
	{
		objectspace();

		dofloor();
		docities();
		doplayer();

		render();
	}

	renderershutdown();
	return 0;
}

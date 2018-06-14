#include "./game.h"

int main()
{
	init();

	generatedeposits();

	while(running())
	{
		starttimer();
		objectspace();

		doplayerinput();

		if(inworld())
		{
			dofloor();
			docities();
			dodeposits();
			doplayer();
		}
		else if(inresources())
		{
			doresourcemenus();
		}

		endtimer();
		dowaittick();

		render();
	}

	renderershutdown();
	return 0;
}

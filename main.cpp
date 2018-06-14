#include "./game.h"

int main()
{
	init();

	while(running())
	{
		starttimer();
		objectspace();

		doplayerinput();

		if(inworld())
		{
			dofloor();
			docities();
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

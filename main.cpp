#include "./game.h"

int main()
{
	init();

	generatedeposits();

	while(running())
	{
		starttimer();
		newframe();
		objectspace();

		doplayerinput();

		if(inworld())
		{
			dofloor();
			docities();
			dodeposits();
			domines();
			dogui();
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

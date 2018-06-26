#include "./game.h"

int main()
{
	init();

	worldgen();
	// generatedeposits();

	do
	{
		starttimer();
		newframe();
		objectspace();

		doplayerinput();

		clearobjects();
		if(inworld())
		{
			dofloor();
			docities();
			// dodeposits();
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
	while(running());

	renderershutdown();
	return 0;
}

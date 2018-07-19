#include "./game.h"

int main()
{
	init();

	worldgen();

	while(running())
	{
		starttimer();
		objectspace();

		doplayerinput();

		clearobjects();
		if(inworld())
		{
			dofloor();
			dosteelplants();
			docities();
			domines();
			dogui();
			doplayer();
		}
		else if(inresources())
		{
			doresourcemenus();
		}

		render();

		newframe();

		endtimer();
		dowaittick();
	}

	renderershutdown();
	return 0;
}

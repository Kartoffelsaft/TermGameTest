#include "./game.h"

int main()
{
	init();

	worldgen();

	while(running());
	{
		starttimer();
		newframe();
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

		endtimer();
		dowaittick();

		render();
	}

	renderershutdown();
	return 0;
}

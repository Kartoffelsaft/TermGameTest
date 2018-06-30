#include "./game.h"

int main()
{
	init();

	worldgen();

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

#include <iostream>
#include "./game.h"

int main()
{
	init();

	while(running())
	{
		inputhandler(true);
		renderer();
	}

	renderershutdown();
	return 0;
}
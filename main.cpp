#include <iostream>
#include "./game.h"

int main()
{
	ginit();
	cinit();

	while(beginshutdown() == false)
	{
		inputhandler();
		renderer();
	}

//	

	renderershutdown();
	return 0;
}
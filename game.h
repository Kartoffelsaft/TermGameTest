#pragma gamefuncandconsts

namespace settings
{
	const int idlerate{60}; 		//how many times per second gameloop happens while idle
}

/* INITIALIZATION AND SHUTDOWN */
void init();						//initializes input settings
bool running();
void shutdown();

/* INPUT HANDLING */
int getinput();
void inputhandler(bool waitonblank);//the waitonblank variable is to allow control 
									//over whether no input will halt the game for a short time

/* RENDER HANDLING */
void renderer();
void renderershutdown();

/* MISC FUNCTIONS */
void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening
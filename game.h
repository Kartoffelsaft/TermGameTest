#pragma gamefuncandconsts

namespace settings
{
	const int calcrate{60}; 		//how many times per second gameloop happens while idle
}

/* INITIALIZATION AND SHUTDOWN */
void ginit();				//initializes the graphics
void cinit();				//initializes input settings
bool beginshutdown();

/* INPUT HANDLING */
int getinput();
void inputhandler();

/* RENDER HANDLING */
void renderer();
void renderershutdown();

/* MISC FUNCTIONS */
void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening
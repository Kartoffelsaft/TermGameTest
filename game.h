#pragma once


namespace settings
{
	const int idlerate{100}; 		//how many times per second gameloop happens while idle
}

/* INITIALIZATION AND SHUTDOWN */
void init();						//initializes input settings
bool running();
void shutdown();

/* INPUT HANDLING */
int getinput();
int inputhandler(bool waitonblank);//the waitonblank variable is to allow control over whether no input will halt the game for a short time
void doplayer();

/* RENDER HANDLING */
void renderer(int, int, char);
void renderershutdown();

/* MISC FUNCTIONS */
void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening

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


/* RENDER HANDLING */

// void renderer(int, int, char);
void render();
void renderershutdown();
// void rendererfinish();
int sizex();
int sizey();


/* GAME OBJECT HANDLING */

void doplayer();
void dofloor();
void objectspace(); 
void addobject(int, int, char);
char fetchobj(int, int);


/* MISC FUNCTIONS */

void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening

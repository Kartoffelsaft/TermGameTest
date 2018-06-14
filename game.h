#pragma once
#include <string>
using std::string;


namespace settings
{
	const double idlerate{100}; 		//how many times per second gameloop happens while idle
}

namespace consts
{
	const unsigned int maxnumb{unsigned(0)-unsigned(1)};	// for when an unrealistically large number is needed
}

/* INITIALIZATION, SHUTDOWN, AND GAMESTATE */

void init();						//initializes input settings
bool running();
void shutdown();
bool inworld();
void gotoworld();
bool inresources();
void gotoresources();


/* INPUT HANDLING */

int getinput();
int inputhandler();
void doplayerinput();


/* RENDER HANDLING */

// void renderer(int, int, char);
void render();
void renderershutdown();
// void rendererfinish();
int sizex();
int sizey();
void addtext(int, int, string);


/* GAME OBJECT HANDLING */

void doplayer();
void dofloor();
void docities();
void dodeposits();
void doresourcemenus();
void objectspace();
void addobject(int, int, char);
char fetchobj(int, int);
int getcityid(int, int);
void docitydata(int, int);
void createcity(int, int);

/* RESOURCE CONTROL */

int cityincome();

int getincome();
void addincome();

void generatedeposits();
void irongenerator();


/* MISC FUNCTIONS */

void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening
void starttimer();
void endtimer();
void nextturn();

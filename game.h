#pragma once
#include <string>
using std::string;


namespace settings
{
	namespace worldgen
	{
		const int worldx{64};
		const int worldy{32};

		const int maxcontinents{3};
		const int landmasssize{12};
		const int landrizechance{60};

		const int polepercent{15};
		const int polevariation{5};
	}
	const int cityrange{3};

	const double idlerate{100}; 		//how many times per second gameloop happens while idle
}

namespace consts
{
	const unsigned int maxnumb{unsigned(0)-unsigned(1)};	// for when an unrealistically large number is needed
}

namespace colors
{
	const int BLUE{0};
	const int LIGHT_BLUE{1};
	const int GREEN{2};
	const int LIGHT_GREEN{3};
	const int WHITE{4};
	const int GRAY{5};
	const int LIGHT_GRAY{6};
	const int BLACK{7};

	const int UNKNOWN_PAIR{1};
	const int WATER_PAIR{2};
	const int LAND_PAIR{3};
	const int MOUNTAIN_PAIR{4};
	const int FOREST_PAIR{5};
	const int KELP_PAIR{6};
	const int MONTANE_PAIR{7};
	const int ICE_PAIR{8};
	const int TUNDRA_PAIR{9};
}

/* INITIALIZATION, SHUTDOWN, AND GAMESTATE */

void init();						//initializes game

void worldgen();

bool running();					//returns whether or not the game is supposed to be running
void shutdown();				//falsifies running()'s return value (thereby ending the game safefully)

bool inworld();					//returns whether or not the game is in the world menu
void gotoworld();				//sets the game to the world menu
bool inresources();			//returns whether or not the game is in the resource menu
void gotoresources();		//sets the game to the resource menu

void newframe();				//initializes gamestate for a new frame
bool isevent();					//returns whether an evant has occurred this frame
void newevent();				//sets the current frame to an event frame (to make above function return true)


/* INPUT HANDLING */

int getinput();					//returns what is inputed
int inputhandler();			//also returns what is inputed, prefferred over getinput() because int triggers isevent() and intercepts a few keystrokes (like esc)
void doplayerinput();		//handles most inputs by the player (some to be moved to inputhandler)


/* RENDER HANDLING */

// void renderer(int, int, char);
void render();											//triggers the rendering of the scene. isevent() must be true for it to work
void renderershutdown();						//safely stops the renderer
// void rendererfinish();
int sizex();												//returns the height of the terminal
int sizey();												//returns the width of the terminal
void addtext(int, int, string);			//adds a string of text starting at coords x, y


/* GAME OBJECT HANDLING */

void doplayer();										//prepares the player for rendering, and triggers player-location-bound functions
void dofloor();											//prepares the floor for rendering
void docities();										//prepares the cities for rendering
void dodeposits();									//prepares the deposits for rendering
void domines();											//prepares the mines for rendering
void doresourcemenus();							//displays information about current resource amounts when inresources() is true
void dogui();												//prepares the gui for rendering

void objectspace();									//sets the size of the array for game objects to sit within
void addobject(int, int, char, int = -1);			//places an object (char) in the 2D objects array at point x, y to be rendered (prone to segfaulting if improperly used)
void clearobjects();
char fetchobj(int, int);						//returns the object most recently placed at x, y
int fetchcolor(int, int);						//returns the color of an object at x, y

int world2dto1d(int, int);					//turns the x & y coords to the number that addresses a world tile in the terrains vector
int world1dtox(int);								//inverse of the above function to get x
int world1dtoy(int);								//inverse of the above function to get y

int getcityid(int, int);						//returns location of the city at x, y inside of the cities array
int getdepositid(int, int);					//returns a number like getcityid() but for deposits
void docitydata(int, int);					//displays information about the city at x, y
void dodepositdata(int, int);				//displays information about the deposit at x, y
void dofloordata(int, int);
void buildcity(int, int);						//creates a city at x, y
void buildmine(int, int);						//places a mine at x, y
char getdepositresource(int);				//input the depositid to get the resource type
int getdepositx(int);								//turns depositid into x coord
int getdeposity(int);								//turns depositid into y coord
void clearresources(int, int);			//decreases deposit(of the first int)'s resource amount by (the second) int
void addminerals(char, int);					//given the type and amount of resource, it will be added to the resource pool


/* RESOURCE CONTROL */

int getlandvalue(int, int);					//returns the value of a piece of land (for a city)

int cityincome();										//returns how much income comes from cities

int getincome();										//returns how much income is earned per turn
void addresources();										//adds income to the current money pool

void generatedeposits();						//creates all of the deposits for the game world
void irongenerator();								//creates all of the iron deposits (called by generatedeposits())
void extractresources();						//calls the functions needed to turn unextracted resources (in deposits class) to extracted resources (in resources namespace)


/* MISC FUNCTIONS */

void dowaittick();			//to avoid wasting processing power by waiting when nothing is happening
void starttimer();			//starts the timer that controls dowaittick()
void endtimer();				//ends the timer that controls dowaittick()

int randbell(int, int);	//generates a random number with a bell curve that has a median of (the first) int and a standard deviation of (the second) int
int randuni(int, int);	//generates a random number uniformly spread between (the first) int and (the second) int

void nextturn();				//calls all of the functions needed to setup the next turn

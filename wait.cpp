#include "game.h"
#include <chrono>
using namespace std::chrono;
#include <thread>

static auto t1 = high_resolution_clock::now();
static auto t2 = high_resolution_clock::now();

void starttimer()
{
	t1 = high_resolution_clock::now();
}

void endtimer()
{
	t2 = high_resolution_clock::now();
}

void dowaittick()
{
	std::this_thread::sleep_for(duration<double, std::milli>((t2 - t1)/settings::idlerate));
}

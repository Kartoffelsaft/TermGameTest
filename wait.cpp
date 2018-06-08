#include "game.h"
#include <chrono>
#include <thread>

void dowaittick()
{
	std::this_thread::sleep_for(std::chrono::milliseconds(1000/settings::idlerate));
}
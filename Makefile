compiler = g++
output = termgametest
arguments = -lncurses -std=gnu++17

all:
	$(compiler) -o $(output) *.cpp $(arguments)

all-debug:
	$(compiler) -o $(output) *.cpp $(arguments) -g

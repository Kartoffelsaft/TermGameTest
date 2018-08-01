source = ./src/*/*.cpp ./src/gameplay/*/*.cpp
headers = ./src/headers/ #this needs to be the directory the .h file is in, and not the .h file itself; as per -iquote rules

compiler = g++
output = termgametest
arguments = -lncurses -std=gnu++17 -iquote $(headers)

all:
	$(compiler) -o $(output) $(source) $(arguments)

all-debug:
	$(compiler) -o $(output) $(source) $(arguments) -g

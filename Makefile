SHELL=/bin/bash

OBJS := JSON.o Monster.o Hero.o Map.o Game.o Source.o
CFLAGS := -std=c++17 -Wall -Wextra -g
CC := g++-9

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h Damage.h
	$(CC) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c Hero.cpp

Map.o: Map.cpp Map.h
	$(CC) $(CFLAGS) -c Map.cpp

Game.o: Game.cpp Game.h Monster.h Hero.h Map.h
	$(CC) $(CFLAGS) -c Game.cpp

Source.o: Source.cpp Game.h
	$(CC) $(CFLAGS) -c Source.cpp

sca:
	bash -c "./cppcheck.sh"

memtest:
	bash -c "./valgrind.sh"
	
unittest:
	cd tests && ./runTests

doc: 
	doxygen doxconf

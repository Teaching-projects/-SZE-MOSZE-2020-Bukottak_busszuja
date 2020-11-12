OBJS := JSON.o Monster.o Hero.o Source.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++-9

CPPFILES := JSON.cpp Monster.cpp Hero.cpp Source.cpp
CPPCFLAGS := --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi

TESTFILES:= scenario1.json
VLGRNDFLAGS:= --leak-check=full --error-exitcode=3
VLGRNDPARAM:=  ./output $(TESTFILES)

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

JSON.o: JSON.cpp JSON.h
	$(CC) $(CFLAGS) -c JSON.cpp

Monster.o: Monster.cpp Monster.h JSON.h
	$(CC) $(CFLAGS) -c Monster.cpp

Hero.o: Hero.cpp Hero.h Monster.h JSON.h
	$(CC) $(CFLAGS) -c Hero.cpp

Source.o: Source.cpp Monster.h Hero.h
	$(CC) $(CFLAGS) -c Source.cpp

sca:
	cppcheck $(CPPFILES) $(CPPCFLAGS)

memtest:
	valgrind $(VLGRNDFLAGS) $(VLGRNDPARAM)
	
unittest:
	cd tests && ./runTests

doc: 
	doxygen doxconf

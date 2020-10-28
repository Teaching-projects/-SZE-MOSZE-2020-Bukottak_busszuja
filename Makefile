OBJS := Jsonparser.o Szorny.o Kalandor.o Source.o
CFLAGS := -std=c++17 -Wall -Werror -g
CC := g++

CPPFILES := Jsonparser.cpp Szorny.cpp Kalandor.cpp Source.cpp
CPPCFLAGS := --enable=all 2> report.txt && cat report.txt && if grep -q "(warning)" "./report.txt"; then exit 1; fi && if grep -q "(error)" "./report.txt"; then exit 1; fi

TESTFILES:= Units/Arnykiraly.json Units/Sotetvarazslo.json
VLGRNDFLAGS:= --leak-check=full --error-exitcode=3
VLGRNDPARAM:=  ./output $(TESTFILES)

build: $(OBJS)
	$(CC) $(CFLAGS) -o output $(OBJS)

Jsonparser.o: Jsonparser.cpp Jsonparser.h
	$(CC) $(CFLAGS) -c Jsonparser.cpp

Szorny.o: Szorny.cpp Szorny.h
	$(CC) $(CFLAGS) -c Szorny.cpp

Kalandor.o: Kalandor.cpp Kalandor.h
	$(CC) $(CFLAGS) -c Kalandor.cpp

Source.o: Source.cpp Szorny.h Kalandor.h
	$(CC) $(CFLAGS) -c Source.cpp

cppcheck:
	cppcheck $(CPPFILES) $(CPPCFLAGS)

valgrind:
	valgrind $(VLGRNDFLAGS) $(VLGRNDPARAM)
	
unittest:
	cd tests && ./runTests

doc: 
	doxygen doxconf

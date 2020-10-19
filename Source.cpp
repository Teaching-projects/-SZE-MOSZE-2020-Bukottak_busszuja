#include "Szorny.h"
#include "Kalandor.h"


int main(int argc, char **argv) {

	try {
		Szorny s2 = Szorny::parseUnit(argv[2]);
		Kalandor s1(Szorny::parseUnit(argv[1]));
    
		Szorny::harc(s1, s2);

		return 0;

	}
	catch (int e) {
		switch (e) {
		case 56: std::cout << "File does not exist!" << std::endl;
			break;
		case 57: std::cout << "Invalid character value!!" << std::endl;
			break;
		}
		return 0;
	}
}

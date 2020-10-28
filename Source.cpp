#include "Szorny.h"
#include "Kalandor.h"


int main(int argc, char **argv) {
	try {
		std::string f1 = argv[2];
		std::ifstream f(argv[2]);
		Jsonparser f2(f);
		Jsonparser f3(f1);
		Szorny s2 = Szorny::parseUnit(f2);
		Kalandor s1(Szorny::parseUnit(f3));
        	Szorny::harc(s1, s2);
        	if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp() << std::endl;
        	if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp() << std::endl;

		return 0;
	}
	catch (int e) {
		switch (e) {
		case MYFILEERROR: std::cout << "File does not exist!" << std::endl;
			break;
		case INVALID_VALUE: std::cout << "Invalid character value!!" << std::endl;
			break;
		}
		return 0;
	}
}

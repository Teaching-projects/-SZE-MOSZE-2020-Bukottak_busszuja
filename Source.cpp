#include "Szorny.h"
#include <stdexcept>
#include <string>

int sti(char* c)
{
	std::string arg = c;
	try {
		std::size_t pos;
		int x = std::stoi(arg, &pos);
		if (pos < arg.size()) {
			std::cerr << "Trailing characters after number: " << arg << '\n';
		}
		return x;
	}
	catch (std::invalid_argument const &ex) {
		std::cerr << "Invalid number: " << arg << '\n';
	}
	catch (std::out_of_range const &ex) {
		std::cerr << "Number out of range: " << arg << '\n';
	}
	return 0;
}

void kiir(const Szorny &s) {
	std::cout << s.getName() << ": HP: " << s.getHp() << ", DMG: " << s.getDmg() << std::endl;
}

int main(int argc, char ** argv) {
	try {
		Szorny s1 = Szorny::parseUnit(argv[1]);
		Szorny s2 = Szorny::parseUnit(argv[2]);
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

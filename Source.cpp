#include "Szorny.h"
#include "Kalandor.h"
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
    } catch (std::invalid_argument const &ex) {
        std::cerr << "Invalid number: " << arg << '\n';
    } catch (std::out_of_range const &ex) {
        std::cerr << "Number out of range: " << arg << '\n';
    }
    return 0;
}

void kiir(const Szorny &s) {
	std::cout << s.getName() << ": HP: " << s.getHp() << ", DMG: " << s.getDmg() << std::endl;
}

int main(int argc, char ** argv) {
	try {
		Kalandor s1(Kalandor::parseUnit(argv[1]));
		Szorny s2 = Szorny::parseUnit(argv[2]);
		while (s1.getHp() > 0 && s2.getHp() > 0) {
			s1.tamad(s2);
			if (s2.getHp() > 0) {
				s2.tamad(s1);
			}
		}
		if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp() << std::endl;
		if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp() << std::endl;

		return 0;

	}
     catch (int e) {
        switch(e) {
            case 56: std::cout << "File does not exist!" << std::endl;
                break;
            case 57: std::cout << "Invalid character value!!" << std::endl;
                break;
        }
		return 0;
    }
}


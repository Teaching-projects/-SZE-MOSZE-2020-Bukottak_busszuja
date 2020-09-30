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

int main(int argc,char ** argv) {
    try {
        std::ifstream f1, f2;
        f1.open(argv[1]);
        f2.open(argv[2]);
        if (!f1.good() || !f2.good())
            throw 56;
        else {
			Szorny s1 = Szorny::parseUnit(argv[1]);
			Szorny s2 = Szorny::parseUnit(argv[1]);
            while (s1.getHp() > 0 && s2.getHp() > 0) {
                s1.tamad(s2);
                if (s1.getHp() > 0 && s2.getHp() > 0) {
                    s2.tamad(s1);
                }
            }
            if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remained HP: " << s2.getHp() << std::endl;
            if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remained HP: " << s1.getHp() << std::endl;

            return 0;

        }
    } catch (int e) {
        std::cout << "Nem letezo fajl lett megadva!" << std::endl;
		return 0;
    }
}


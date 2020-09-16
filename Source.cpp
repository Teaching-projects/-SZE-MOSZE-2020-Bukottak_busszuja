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
}

int main(int argc, char **argv) {
	Szorny s1(argv[1], sti(argv[2]), sti(argv[3]));
	Szorny s2(argv[4], sti(argv[5]), sti(argv[6]));
	cout << s1.getName() << " " << s1.getHp() << " " << s1.getDmg() << " " << s2.getName() << " " << s2.getHp() << " " << s2.getDmg() << endl;
	int pont1 = s1.getHp();
	int pont2 = s2.getHp();
	while (pont1 > 0 && pont2 > 0) {
		cout << s1.getName() << " -> " << s2.getName() << endl;
		s1.tamad(s2);
		pont2 = s2.getHp();
		s1.kiir();
		s2.kiir();
		if (pont1 > 0 && pont2 > 0) {
			cout << s2.getName() << " -> " << s1.getName() << endl;
			s2.tamad(s1);
			pont1 = s1.getHp();
			s1.kiir();
			s2.kiir();
		}
	}
	if (s1.getHp() == 0) cout << s1.getName() << " meghalt. " << s2.getName() << " nyert." << endl;
	if (s2.getHp() == 0) cout << s2.getName() << " meghalt. " << s1.getName() << " nyert." << endl;

	cin.get();
	return 0;
}

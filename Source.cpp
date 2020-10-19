#include "Szorny.h"
#include "Kalandor.h"

double gcd(double a, double b)
{
	if (a < b)
		return gcd(b, a);
	if (fabs(b) < 0.001)
		return a;
	else
		return (gcd(b, a - floor(a / b) * b));
}

int main(int argc, char **argv) {

	try {
		Szorny s2 = Szorny::parseUnit(argv[2]);
		Kalandor s1(Szorny::parseUnit(argv[1]));

    double szamlalo = 0;
    double lepes;

    s1.tamad(s2);
    if (s2.getHp() > 0) {
        s2.tamad(s1);
    }

    while ((s1.getHp() > 0) && (s2.getHp() > 0)) {
        lepes = gcd(s1.getSpeed(), s2.getSpeed());
        szamlalo = szamlalo + lepes;
        if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed() && gcd(szamlalo, s2.getSpeed()) == s2.getSpeed()) {
            s1.tamad(s2);
            if (s2.getHp() > 0) s2.tamad(s1);
        }
        else if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed())s1.tamad(s2);
        else if (gcd(szamlalo, s2.getSpeed()) == s2.getSpeed())s2.tamad(s1);
    }



        if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp() << std::endl;
        if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << ", current level: " << s1.getLvl() << ", current experience: " << s1.getXp() << std::endl;

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

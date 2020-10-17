#include "Szorny.h"

double gcd(double a, double b)
{
	if (a < b)
		return gcd(b, a);
	if (fabs(b) < 0.001)
		return a;
	else
		return (gcd(b, a - floor(a / b) * b));
}


int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getHp()const {
	return hp;
}

std::string Szorny::getName()const {
	return nev;
}

double Szorny::getSpeed() const {
	return speed;
}

void Szorny::tamad(Szorny & a)const {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}

Szorny Szorny::parseUnit(std::string fajlnev) {
	int hp, dmg, i, keyv;
	double speed;
	std::string name;
	std::string::size_type found;
	std::ifstream f(fajlnev);
	if (!f.good()) throw 56;
	else {
		std::string sor = "";
		std::string tmp;

		while (!f.eof()) {
			getline(f, sor);
			keyv = 0;
			found = sor.find('"');
			if (found != std::string::npos) {
				i = found + 1;
				tmp = "";
				while (sor[i] != '"') {
					tmp = tmp + sor[i];
					i++;
				}

				if (tmp == "name") keyv = 1;
				if (tmp == "hp") keyv = 2;
				if (tmp == "dmg") keyv = 3;
				if (tmp == "speed") keyv = 4;
			}

			found = sor.find(':');
			if (found != std::string::npos) {
				i = found + 1;
				tmp = "";
				while (sor[i] != ',' && i != sor.size()) {
					if (sor[i] == '"' || sor[i] == ' ') {
						i++;
					}
					else {
						tmp = tmp + sor[i];
						i++;
					}
				}

				switch (keyv) {
				case 1: name = tmp;
					break;
				case 2: hp = stoi(tmp);
					break;
				case 3: dmg = stoi(tmp);
					break;
				case 4: speed = stod(tmp);
					break;
				default: throw 57;
					break;

				}
			}
		}
		f.close();

		return Szorny(name, hp, dmg,speed);
	}
}


void Szorny::harc(Szorny & s1,Szorny & s2) {
	double szamlalo = 0;
	double lepes = gcd(s1.getSpeed(), s2.getSpeed());
	s1.tamad(s2);
	if (s2.getHp() > 0) {
		s2.tamad(s1);
	}
	while ((s1.getHp() > 0) && (s2.getHp()>0)) {
		szamlalo = szamlalo + lepes;
		if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed() && gcd(szamlalo, s2.getSpeed()) == s2.getSpeed()) {
			s1.tamad(s2);
			if (s2.getHp() > 0) s2.tamad(s1);
		}
		else if (gcd(szamlalo, s1.getSpeed()) == s1.getSpeed())s1.tamad(s2);
		else if (gcd(szamlalo, s2.getSpeed()) == s2.getSpeed())s2.tamad(s1);
	}
	if (s1.getHp() == 0) std::cout << s2.getName() << " wins. Remaining HP: " << s2.getHp() << std::endl;
	if (s2.getHp() == 0) std::cout << s1.getName() << " wins. Remaining HP: " << s1.getHp() << std::endl;

}

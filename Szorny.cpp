#include "Szorny.h"

int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getMaxHp()const {
	return hp;
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

Szorny Szorny::parseUnit(const std::string &fajlnev) {
    int hp, dmg, keyv;
    double speed;
    std::string name;
    std::string::size_type found;
    std::ifstream f(fajlnev);
    if (!f.good()) throw 56;

    std::string sor;
    std::string tmp;
    std::string::size_type i;

    while (!f.eof()) {
        getline(f, sor);
        keyv = 0;
        found = sor.find('"');
        if (found!=std::string::npos) {
            i = found+1;
            tmp = "";
            while (sor[i]!='"') {
                tmp = tmp+sor[i];
                i++;
            }

            if (tmp == "name") keyv = 1;
            if (tmp == "hp") keyv = 2;
            if (tmp == "dmg") keyv = 3;
            if (tmp == "speed") keyv = 4;
        }

        found = sor.find(':');
        if (found!=std::string::npos) {
            i = found+1;
            tmp = "";
            while (sor[i]!=',' && i!=sor.size()) {
                if (sor[i]=='"' || sor[i]==' ') {
                    i++;
                } else {
                    tmp = tmp+sor[i];
                    i++;
                }
            }

            switch(keyv) {
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

Szorny& Szorny::operator=(const Szorny &szorny) {
    maxhp = szorny.getMaxHp();
    hp = szorny.getHp();
    dmg = szorny.getDmg();
    nev = szorny.getName();
    speed = szorny.getSpeed();
    return *this;
}

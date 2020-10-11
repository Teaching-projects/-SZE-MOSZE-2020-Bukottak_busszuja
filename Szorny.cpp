#include "Szorny.h"

Szorny::Szorny(std::string nev, int hp, int dmg){
    this->nev = nev;
    this->maxhp = hp;
    this->hp = maxhp;
    this->dmg = dmg;
}

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

void Szorny::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}

Szorny Szorny::parseUnit(std::string fajlnev) {
	int hp, dmg, keyv;
    std::string name;
    std::string::size_type found;
    std::ifstream f(fajlnev);
    if (!f.good()) throw 56;
    else {
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
                    default: throw 57;
                        break;

                }
            }
        }
        f.close();

        return Szorny(name, hp, dmg);
    }
}


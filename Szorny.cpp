#include "Szorny.h"


int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getHp()const {
	return hp;
}

std::string Szorny::getName()const {
	return nev;
}

void Szorny::tamad(Szorny & a)const {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}

void Szorny::parseUnit(std::ifstream & f) {
	std::vector<std::string> v;
	std::string sor = "";
	while (!f.eof()) {
		getline(f, sor);
		v.push_back(sor);
	}
	f.close();
	sor = "";
	for (int i = 12; i < v[1].size() - 2; i++) {
		sor = sor + v[1][i];
	}
	nev = sor;
	sor = "";
	for (int i = 9; i < v[2].size() - 1; i++) {
		sor = sor + v[2][i];
	}
	int j = stoi(sor);
	hp = j;
	sor = "";
	for (int i = 10; i < v[3].size(); i++) {
		sor = sor + v[3][i];
	}
	j = stoi(sor);
	dmg = j;
}


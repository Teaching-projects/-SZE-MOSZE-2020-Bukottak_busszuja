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

Szorny Szorny::parseUnit(Jsonparser & json) {
	std::string name = json.getErtek("name");
	int hp = stoi(json.getErtek("hp"));
	int dmg = stoi(json.getErtek("dmg"));
	return Szorny(name,hp,dmg);
}
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
	std::string nevp = "name"; std::string hpp = "hp"; std::string dmgg = "dmg";
	std::string name = json.getErtek(nevp);
	int hp = stoi(json.getErtek(hpp));
	int dmg = stoi(json.getErtek(dmgg));
	return Szorny(name,hp,dmg);
}
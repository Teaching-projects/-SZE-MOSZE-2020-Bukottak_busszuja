#include "Szorny.h"


int Szorny::getDmg()const {
	return dmg;
}

int Szorny::getHp()const {
	return hp;
}

string Szorny::getName()const {
	return nev;
}

void Szorny::kiir()const {
	cout << this->nev << ": HP: " << this->hp << ", DMG: " << this->dmg << endl;
}

void Szorny::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	if (a.hp < 0) a.hp = 0;
}

#include "Kalandor.h"
#include <math.h>

#define XPTOLVL 100

Kalandor::Kalandor(std::string nev, int hp, int dmg) : Szorny(nev, hp, dmg) {
    lvl = 1;
    xp = 0;
}

Kalandor::Kalandor(Szorny sz)
	: Szorny(sz.getName(), sz.getHp(), sz.getDmg()), xp(0), lvl(1){}

int Kalandor::getXp()const {
	return xp;
}

int Kalandor::getLvl()const {
	return lvl;
}

void Kalandor::lvlUp(int xptoLvl) {
    xp = xp-xptoLvl;
    lvl++;
    maxhp = floor(maxhp*1.1);
    hp = maxhp;
    dmg = floor(dmg*1.1);
}

void Kalandor::xpGain() {
    xp += dmg;
    while (xp >= XPTOLVL) {
        lvlUp(XPTOLVL);
    }
}

void Kalandor::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	xpGain();
	if (a.hp < 0) a.hp = 0;
}

Kalandor& Kalandor::operator=(const Szorny &szorny) {
    this->maxhp = szorny.getMaxHp();
    this->hp = szorny.getHp();
    this->dmg = szorny.getDmg();
    this->nev = szorny.getName();
    this->xp = 0;
    this->lvl = 1;
    return *this;
}



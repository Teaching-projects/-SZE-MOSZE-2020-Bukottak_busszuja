#include "Kalandor.h"
#include <math.h>

#define XPTOLVL 100

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

void Kalandor::xpGain(int gain) {
    xp += gain;
    while (xp >= XPTOLVL) {
        lvlUp(XPTOLVL);
    }
}

void Kalandor::tamad(Szorny & a) {
	a.hp = a.hp - this->dmg;
	int gain = dmg;
	if (a.hp < 0) a.hp = 0;
	if (dmg > a.hp) gain = a.hp;
	xpGain(gain);
}

Kalandor& Kalandor::operator=(const Szorny &szorny) {
    maxhp = szorny.getMaxHp();
    hp = szorny.getHp();
    dmg = szorny.getDmg();
    nev = szorny.getName();
    xp = 0;
    lvl = 1;
    return *this;
}



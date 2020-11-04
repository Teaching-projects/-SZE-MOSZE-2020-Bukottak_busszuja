#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Szorny.h"

class Kalandor : public Szorny {
    public:
        Kalandor(const std::string& nev, int hp, int dmg, double speed, int xp=0, int lvl=1) : Szorny(nev, hp, dmg, speed), xp(xp), lvl(lvl) {};
        Kalandor(const Szorny& sz) : Szorny(sz.getName(), sz.getHp(), sz.getDmg(), sz.getSpeed()), xp(0), lvl(1) {};
        int getXp() const;
        int getLvl() const;
        Kalandor& operator=(const Szorny&);
    protected:
        int xp;
        int lvl;
        void lvlUp(int xptoLvl);
        void xpGain(int gain);
        void tamad(Szorny&);
};

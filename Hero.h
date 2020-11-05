#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "Monster.h"

class Hero : public Monster {
    public:
        Hero(const std::string& nev, int hp, int dmg, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, double speedPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), speedPerLvl(speedPerLvl), xp(xp), lvl(lvl) {};
        int getXp() const;
        int getLevel() const;
        static Hero parse(const std::string& json);
        Hero& operator=(const Monster&);
    protected:
        int xpPerLvl;
        int hpPerLvl;
        int dmgPerLvl;
        double speedPerLvl;
        int xp;
        int lvl;
        void lvlUp();
        void xpGain(int gain);
        void tamad(Monster*);
};

#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include "gtest/gtest.h"
#include "Monster.h"

class Hero : public Monster {
    public:
        Hero(const std::string& nev, int hp, int dmg, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, double speedPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), speedPerLvl(speedPerLvl), xp(xp), lvl(lvl) {};
        int getXp() const;
        int getLevel() const;
	FRIEND_TEST(Unittest,Private_functions_test);
        static Hero parse(const std::string& json);
        Hero& operator=(const Monster&);
    	bool operator ==(const Hero & other)const {
			return (this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->nev == other.getName() && this->speed == other.getAttackCoolDown() && this->maxhp == other.getMaxHealthPoints()&& this->dmgPerLvl==other.dmgPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
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

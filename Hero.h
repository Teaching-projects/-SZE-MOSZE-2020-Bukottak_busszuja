#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include "gtest/gtest.h"
#include "Monster.h"

class Hero : public Monster {
    public:
        Hero(const std::string& nev, int hp, int dmg, int def, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, int defPerLvl, double speedPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, def, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), defPerLvl(defPerLvl), speedPerLvl(speedPerLvl), xp(xp), lvl(lvl) {};
        int getXp() const;
        int getLevel() const;
        FRIEND_TEST(Unittest,Private_functions_test);
        static Hero parse(const std::string& json);
        Hero& operator=(const Hero&);
    	bool operator ==(const Hero & other)const {
			return (this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && round(this->speed) == round(other.getAttackCoolDown()) && this->maxhp == other.getMaxHealthPoints() && this->dmgPerLvl==other.dmgPerLvl && this->defPerLvl==other.defPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
     protected:
        int xpPerLvl;
        int hpPerLvl;
        int dmgPerLvl;
        int defPerLvl;
        double speedPerLvl;
        int xp;
        int lvl;
        void lvlUp();
        void xpGain(int gain);
        void tamad(Monster*);
};

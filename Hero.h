#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include "gtest/gtest.h"
#include "Monster.h"

class Hero : public Monster {
    public:
        Hero(const std::string& nev, int hp, Damage dmg, int def, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, int mdmgPerLvl, int defPerLvl, double speedPerLvl, int lightradius, int lightradiusPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, def, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), mdmgPerLvl(mdmgPerLvl), defPerLvl(defPerLvl), speedPerLvl(speedPerLvl), lightradius(lightradius), lightradiusPerLvl(lightradiusPerLvl), xp(xp), lvl(lvl) {};
        int getXp() const;
        int getLevel() const;
         int getLightradius() const;
        FRIEND_TEST(Unittest,Private_functions_test);
        static Hero parse(const std::string& json);
        //Hero& operator=(const Hero&);
    	bool operator ==(const Hero & other)const {
			return (this->lightradiusPerLvl == other.lightradiusPerLvl && this->lightradius == other.getLightradius() && this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && round(this->speed) == round(other.getAttackCoolDown()) && this->maxhp == other.getMaxHealthPoints() && this->dmgPerLvl==other.dmgPerLvl && this->defPerLvl==other.defPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
     protected:
	int xpPerLvl;
        int hpPerLvl;
        int dmgPerLvl;
        int mdmgPerLvl;
        int defPerLvl;
        double speedPerLvl;
        int lightradius;
        int lightradiusPerLvl;
        int xp;
        int lvl;
        void lvlUp();
        void xpGain(int gain);
        void tamad(Monster*);
};

/**
 * \Class Hero
 *
 * \brief Hero Class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/12/07 17:55
*/
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<cmath>
#include "gtest/gtest.h"
#include "Monster.h"

class Hero : public Monster {
    public:
        Hero(const std::string& nev, int hp, Damage dmg, int def, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, int mdmgPerLvl, int defPerLvl, double speedPerLvl, int lightradius, int lightradiusPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, def, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), mdmgPerLvl(mdmgPerLvl), defPerLvl(defPerLvl), speedPerLvl(speedPerLvl), lightradius(lightradius), lightradiusPerLvl(lightradiusPerLvl), xp(xp), lvl(lvl) {};	///< Konstruktor ami incializal egy host
        int getXp() const; 		///< visszaadja a host xp-jét
        int getLevel() const;	///< visszaadja a hos szintjet
        int getLightradius() const; ///< visszaadja a hos látotavolsagat
        FRIEND_TEST(Unittest,Private_functions_test);	///< lehetové teszi hogy az egyik teszt hozzaferjen a privat adattagokhoz
        static Hero parse(const std::string& json);		///< Egy json objektumbol kinyeri a hos adatait
    	bool operator ==(const Hero & other)const {		///< Operator ami megadja, hogy ket hos egyenlo-e
			return (this->lightradiusPerLvl == other.lightradiusPerLvl && this->lightradius == other.getLightradius() && this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && round(this->speed) == round(other.getAttackCoolDown()) && this->maxhp == other.getMaxHealthPoints() && this->dmgPerLvl==other.dmgPerLvl && this->defPerLvl==other.defPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
     protected:
		int xpPerLvl;		///< Megadja szintlepeshez mennyi xp kell
        int hpPerLvl;		///< Szintlepesnel mennyit valtozik a hos hp-ja
        int dmgPerLvl;		///< Szintlepésnel mennyit változik a hos dmg-e
        int mdmgPerLvl;		///< Szintlepésnel mennyit változik a hos magic dmg-e
        int defPerLvl;		///< Szintlepésnel mennyit változik a hos defennse
        double speedPerLvl;	///< Szintlepesnel mennyit változik a hos attackspeed-je
        int lightradius;    ///< A hos latotavolsaga
        int lightradiusPerLvl;  ///< Szintlepesnel mennyit valtozik a hos latotavolsaga
        int xp;				///< A hos aktualis tapasztalat pontja
        int lvl;			///< A hos aktualis szintje
        void lvlUp();		///< Szintlepes fuggveny
        void xpGain(int gain);	///< Fuggveny a xp novelesere
        void tamad(Monster*);	///< Fuggveny ami bevisz egy tamadast a monsterbe
};

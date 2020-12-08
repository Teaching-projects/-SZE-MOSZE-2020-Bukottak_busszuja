/**
 * \Class Hero
 *
 * \brief Hero Class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
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
        Hero(const std::string& nev, int hp, Damage dmg, int def, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, int mdmgPerLvl, int defPerLvl, double speedPerLvl, int lightradius, int lightradiusPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, def, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), mdmgPerLvl(mdmgPerLvl), defPerLvl(defPerLvl), speedPerLvl(speedPerLvl), lightradius(lightradius), lightradiusPerLvl(lightradiusPerLvl), xp(xp), lvl(lvl) {};	///< Konstruktor ami incializál egy hõst
        int getXp() const; 		///< visszaadja a hõst xp-jét
        int getLevel() const;	///< visszaddja a hõs szintjét
        int getLightradius() const; ///< visszaadja a hős látótávolságát
        FRIEND_TEST(Unittest,Private_functions_test);	///< lehetõvé teszi hogy az egyik teszt hozzáférjen a privát adattagokhoz
        static Hero parse(const std::string& json);		///< Egy json objektumból kinyeri a hõs adatait
    	bool operator ==(const Hero & other)const {		///< Operátor ami megadja, hogy két hõs egyenlõ-e
			return (this->lightradiusPerLvl == other.lightradiusPerLvl && this->lightradius == other.getLightradius() && this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && round(this->speed) == round(other.getAttackCoolDown()) && this->maxhp == other.getMaxHealthPoints() && this->dmgPerLvl==other.dmgPerLvl && this->defPerLvl==other.defPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
     protected:
		int xpPerLvl;		///< Megadja szintlépéshez mennyi xp kell
        int hpPerLvl;		///< Szintlépésnél mennyit változik a hõs hp-ja
        int dmgPerLvl;		///< Szintlépésnél mennyit változik a hõs dmg-e
        int mdmgPerLvl;		///< Szintlépésnél mennyit változik a hõs magic dmg-e
        int defPerLvl;		///< Szintlépésnél mennyit változik a hõs defennse
        double speedPerLvl;	///< Szintlépésnél mennyit változik a hõs attackspeed-je
        int lightradius;    ///< A hős látótávolsága
        int lightradiusPerLvl;  ///< Szintlépésnél mennyit változik a hős látótávolsága
        int xp;				///< A hõs aktuális tapasztalat pontja
        int lvl;			///< A hõs aktuális szintje
        void lvlUp();		///< Szintlépés függvény
        void xpGain(int gain);	///< Függvény a xp növelésére
        void tamad(Monster*);	///< Függvény ami bevisz egy támadást a monsterbe
};

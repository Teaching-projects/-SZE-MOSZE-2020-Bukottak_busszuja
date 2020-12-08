/**
 * \Class Hero
 *
 * \brief Hero Class
 *
 * \author Hab�n Andr�s, Tranta M�t�, T�th Norbert
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
        Hero(const std::string& nev, int hp, Damage dmg, int def, double speed, int xpPerLvl, int hpPerLvl, int dmgPerLvl, int mdmgPerLvl, int defPerLvl, double speedPerLvl, int xp=0, int lvl=1) : Monster(nev, hp, dmg, def, speed), xpPerLvl(xpPerLvl), hpPerLvl(hpPerLvl), dmgPerLvl(dmgPerLvl), mdmgPerLvl(mdmgPerLvl), defPerLvl(defPerLvl), speedPerLvl(speedPerLvl), xp(xp), lvl(lvl) {};	///< Konstruktor ami incializ�l egy h�st
        int getXp() const; 		///< visszaadja a h�st xp-j�t
        int getLevel() const;	///< visszaddja a h�s szintj�t
        FRIEND_TEST(Unittest,Private_functions_test);	///< lehet�v� teszi hogy az egyik teszt hozz�f�rjen a priv�t adattagokhoz
        static Hero parse(const std::string& json);		///< Egy json objektumb�l kinyeri a h�s adatait
    	bool operator ==(const Hero & other)const {		///< Oper�tor ami megadja, hogy k�t h�s egyenl�-e
			return (this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && round(this->speed) == round(other.getAttackCoolDown()) && this->maxhp == other.getMaxHealthPoints() && this->dmgPerLvl==other.dmgPerLvl && this->defPerLvl==other.defPerLvl && this->hpPerLvl==other.hpPerLvl && this->xpPerLvl==other.xpPerLvl && this->speedPerLvl==other.speedPerLvl);
		}
     protected:
		int xpPerLvl;		///< Megadja szintl�p�shez mennyi xp kell
        int hpPerLvl;		///< Szintl�p�sn�l mennyit v�ltozik a h�s hp-ja
        int dmgPerLvl;		///< Szintl�p�sn�l mennyit v�ltozik a h�s dmg-e
        int mdmgPerLvl;		///< Szintl�p�sn�l mennyit v�ltozik a h�s magic dmg-e
        int defPerLvl;		///< Szintl�p�sn�l mennyit v�ltozik a h�s defennse
        double speedPerLvl;	///< Szintl�p�sn�l mennyit v�ltozik a h�s attackspeed-je
        int xp;				///< A h�s aktu�lis tapasztalat pontja
        int lvl;			///< A h�s aktu�lis szintje
        void lvlUp();		///< Szintl�p�s f�ggv�ny
        void xpGain(int gain);	///< F�ggv�ny a xp n�vel�s�re
        void tamad(Monster*);	///< F�ggv�ny ami bevisz egy t�mad�st a monsterbe
};

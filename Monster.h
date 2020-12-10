/**
 * \class Szorny
 *
 * \brief Szorny class
 *
 * \author Haban Andras, Tranta Mate, Toth Norbert
 *
 * Created on: 2020/10/14 17:15
*/
#pragma once
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include <cmath>
#include "JSON.h"
#include "Damage.h"

class Monster {
    protected:
        std::string nev;                                                                                                    ///< A szorny neve
        int maxhp;                                                                                                          ///< A szorny maximum eletpontja
        int hp;                                                                                                             ///< A szorny eletpontjai
        Damage dmg;                                                                                                         ///< A szorny utesenek erosege;                                                                                                           
        int def;																											///< A vedelmenek erosege;				
        double speed;                                                                                                       ///< A szorny uteseinek gyorsasaga
        virtual void tamad(Monster* );                                                                                          ///< Egy darab utest visz be
        friend class Hero;
    public:
        Monster(std::string nev, int hp, Damage dmg, int def, double speed) :nev(nev), maxhp(hp), hp(maxhp), dmg(dmg), def(def), speed(speed) {}   ///< Szorny osztaly konstruktora
        Damage getDamage()const;                                                                                                  ///< Lekeri a szorny sebzeset
        int getDefense() const;
        int getMaxHealthPoints() const;                                                                                               ///< Lekeri a szorny maximum HP-jat
        int getHealthPoints() const;                                                                                                   ///< Lekeri a szorny HP-jat
        double getAttackCoolDown() const;                                                                                             ///< Lekeri a szorny atackspeedjet
        std::string getName() const;                                                                                         ///< Lekeri a szorny nevet
        static Monster parse(const std::string& json);                                                               ///< Beolvassa a szorny ertekeit
        Monster& operator=(const Monster&);                                                                                   ///< Lehetove teszi egy szorny ertekeinek bealitasat egy mmasikra
        Monster(const Monster& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg), def(s2.def), speed(s2.speed) {};                ///< Lehetove teszi egy szorny letrehozasat egy maik a lemasolasaval
        void fightTilDeath(Monster&);
        bool isAlive() const;                                                                               ///< A parancsori argumentumban megadott ket host harcoltatja
	      bool operator ==(const Monster & other) const {
			return (this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->def == other.getDefense() && this->nev == other.getName() && this->speed == other.getAttackCoolDown() && this->maxhp==other.getMaxHealthPoints());	///< Operator ami osszehasonlit ket szorny objektumot
		}
};

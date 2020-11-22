/**
 * \class Szörny
 *
 * \brief Szörny class
 *
 * \author Habán András, Tranta Máté, Tóth Norbert
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
        std::string nev;                                                                                                    ///< A szörny neve
        int maxhp;                                                                                                          ///< A szörny maximum életpontja
        int hp;                                                                                                             ///< A szörny életpontjai
        Damage dmg;                                                                                                         ///< A szörny ütésének erõsege;
        double speed;                                                                                                       ///< A szörny ütéseinek gyorsasága
        virtual void tamad(Monster* );                                                                                          ///< Egy darab ütést visz be
        friend class Hero;
    public:
        Monster(std::string nev, int hp, Damage dmg, double speed) :nev(nev), maxhp(hp), hp(maxhp), dmg(dmg), speed(speed) {}   ///< Szörny osztály konstruktora
        Damage getDamage()const;                                                                                                  ///< Lekéri a szörny sebzését
        int getMagicalDamage()const;
        int getMaxHealthPoints() const;                                                                                               ///< Lekéri a szörny maximum HP-ját
        int getHealthPoints()const;                                                                                                   ///< Lekéri a szörny HP-ját
        double getAttackCoolDown()const;                                                                                             ///< Lekéri a szörny atackspeedjét
        std::string getName()const;                                                                                         ///< Lekéri a szörny nevét
        static Monster parse(const std::string& json);                                                               ///< Beolvassa a szörny értékeit
        Monster& operator=(const Monster&);                                                                                   ///< Lehetővé teszi egy szörny értékeinek beállítását egy másikéra
        Monster(const Monster& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg), speed(s2.speed) {};                ///< Lehetővé teszi egy szörny létrehozását egy másiknak a lemásolásával
        void fightTilDeath(Monster&);
        bool isAlive() const;                                                                               ///< A parancsori argumentumban megadott két hõst harcoltatja
	bool operator ==(const Monster & other)const {
			return (this->hp == other.getHealthPoints() && this->dmg == other.getDamage() && this->nev == other.getName() && this->speed == other.getAttackCoolDown() && this->maxhp==other.getMaxHealthPoints());
		}
};

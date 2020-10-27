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
#include "Jsonparser.h"  

class Szorny {
    protected:
        std::string nev;                                                                                                    ///< A szörny neve
        int maxhp;                                                                                                          ///< A szörny maximum életpontja
        int hp;                                                                                                             ///< A szörny életpontjai
        int dmg;                                                                                                            ///< A szörny ütésének erõsege
        double speed;                                                                                                       ///< A szörny ütéseinek gyorsasága
        virtual void tamad(Szorny&);                                                                                          ///< Egy darab ütést visz be
        friend class Kalandor;
    public:
        Szorny(std::string nev, int hp, int dmg, double speed) :nev(nev), maxhp(hp), hp(maxhp), dmg(dmg), speed(speed) {}   ///< Szörny osztály konstruktora
        int getDmg()const;                                                                                                  ///< Lekéri a szörny sebzését
        int getMaxHp() const;                                                                                               ///< Lekéri a szörny maximum HP-ját
        int getHp()const;                                                                                                   ///< Lekéri a szörny HP-ját
        double getSpeed()const;                                                                                             ///< Lekéri a szörny atackspeedjét
        std::string getName()const;                                                                                         ///< Lekéri a szörny nevét
        static Szorny parseUnit(Jsonparser &);                                                               ///< Beolvassa a szörny értékeit
        Szorny& operator=(const Szorny&);                                                                                   ///< Lehetővé teszi egy szörny értékeinek beállítását egy másikéra
        Szorny(const Szorny& s2) : nev(s2.nev), maxhp(s2.maxhp), hp(s2.hp), dmg(s2.dmg), speed(s2.speed) {};                ///< Lehetővé teszi egy szörny létrehozását egy másiknak a lemásolásával
        static void harc(Szorny &,Szorny &);                                                                                ///< A parancsori argumentumban megadott két hõst harcoltatja
};
